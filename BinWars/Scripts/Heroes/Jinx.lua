function CastSpell(self,spellIndex,x,y)
        if spellIndex >= 0 and spellIndex <=3 then
                self:CastSpell(spellIndex,x,y)--DisplaySpell() --B4
        end
end