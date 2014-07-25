/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2012  Intline9 <Intline9@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "stdafx.h"
#include "Server.h"
#include "Log.h"
#include "GameSession.h"
#include "ChampionFactory.h"
#include "Player.h"

#if defined(WIN32) || defined(_WIN32)
#include "win/platforms-time.h"
#else
#include <sys/time.h>
#endif


#define REFRESH_RATE 5

uint32 GetNewNetID() {
	static uint32 dwStart = 0x40000019;
	uint32 dwRet = dwStart;
	dwStart++;
	return dwRet;
}

Server::Server()
{

}

Server::~Server()
{
	_isAlive = false;

	delete _handler;
	delete _blowfish;
	enet_host_destroy(_host);
}

bool Server::initialize(ENetAddress *address, const char *baseKey)
{
	if (enet_initialize () != 0)
		return false;
	atexit(enet_deinitialize);

	_host = enet_host_create(address, 32, 0, 0);
	if(_host == NULL)
		return false;

	std::string key = base64_decode(baseKey);
	if(key.length() <= 0)
		return false;
	_blowfish = new BlowFish((uint8*)key.c_str(), 16);
	_handler = new PacketHandler(_host, _blowfish);
	
	return _isAlive = true;
}

PacketHandler* Server::GetPacketHandler()
{
	return _handler;
}

void Server::run()
{
	ENetEvent event;
	Player* p;
	struct timeval tStart, tEnd, tDiff;
	tStart.tv_sec = 0;
	tStart.tv_usec = 0;

	while(enet_host_service(_host, & event, 10) >= 0 && _isAlive)
	{
		switch (event.type)
		{
			case ENET_EVENT_TYPE_CONNECT:
				Logging->writeLine("A new client connected: %i.%i.%i.%i:%i \n", event.peer->address.host & 0xFF, (event.peer->address.host >> 8) & 0xFF, (event.peer->address.host >> 16) & 0xFF, (event.peer->address.host >> 24) & 0xFF, event.peer->address.port);

				/* Set some defaults */
				event.peer->mtu = PEER_MTU;

				event.peer->data = new ClientInfo();
				peerInfo(event.peer)->setName("Test");
				peerInfo(event.peer)->setChampion(ChampionFactory::getChampionFromType("Ezreal", GameSession::GetMap(), GetNewNetID()));
				peerInfo(event.peer)->skinNo = 6;
				peerInfo(event.peer)->team = 0;

				GameSession::AddPlayer(peerInfo(event.peer));

			break;

		case ENET_EVENT_TYPE_RECEIVE:
			if(!_handler->handlePacket(event.peer, event.packet,event.channelID))
			{
				//enet_peer_disconnect(event.peer, 0);
			}

			/* Clean up the packet now that we're done using it. */
			enet_packet_destroy (event.packet);
		break;

		case ENET_EVENT_TYPE_DISCONNECT:
			Logging->writeLine("Client disconnected: %i.%i.%i.%i:%i \n", event.peer->address.host & 0xFF, (event.peer->address.host >> 8) & 0xFF, (event.peer->address.host >> 16) & 0xFF, (event.peer->address.host >> 24) & 0xFF, event.peer->address.port);

			/* Cleanup */
			delete (ClientInfo*)event.peer->data;
		break;
		}


		tEnd = tStart;
		gettimeofday(&tStart, 0);
		timersub(&tStart, &tEnd, &tDiff);
		if(GameSession::started) {
			GameSession::GetMap()->update(tDiff.tv_sec*1000 + tDiff.tv_usec/1000);
		}
		usleep(REFRESH_RATE*1000);
	}
}