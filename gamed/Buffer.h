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

#ifndef __H_BUFFER
#define __H_BUFFER

#include "stdafx.h"
#include <vector>

class Buffer {

private:
	std::vector<uint8> buffer;

public:
	const std::vector<uint8>& getBytes() const { return buffer; }
	void clear() { buffer.clear(); }

	Buffer& operator<<(const std::string& data)
	{
		buffer.insert(buffer.end(), (uint8*)data.c_str(), (uint8*)(data.c_str())+data.length());
		return *this;
	}

	template<typename U>
	Buffer& operator<<(const U& data)
	{
		buffer.insert(buffer.end(), (uint8*)&data, (uint8*)(&data)+sizeof(U));
		return *this;
	}

	void fill(uint8 data, uint32 length) {
		for(int i = 0; i < length; ++i) {
			buffer.push_back(data);
		}
	}

	uint32 size() const {
		return buffer.size();
	}
};

#endif