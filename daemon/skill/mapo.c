// TIE@FY3

inherit SKILL;
int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}
int valid_learn(object me)
{
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("assassin") + "/mapo/" + spell;
}
int practice_skill(object me)
{
        return notify_fail("麻婆寒练术只能用学的\n");
}

int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

