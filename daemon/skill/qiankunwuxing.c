// TIE@FY3
inherit SKILL;
int valid_enable(string usage) { return usage=="magic"; }
int valid_learn(object me)
{
	if( (int)me->query_skill("putiforce",1) < 10
	||	(int)me->query_skill("putfiforce",1) <= (int)me->query_skill("qiankunwuxing",1) )
		return notify_fail("你的菩堤心法还不够高深，无法学习乾坤无形。\n");
	return 1;
}

string conjure_magic_file(string spell)
{
	return CLASS_D("lishi") + "/qiankunwuxing/" + spell;
}
int effective_level() { return 10;}
int learn_bonus()
{
	return -10;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 10;
}
int practice_skill(object me)
{
	return notify_fail("乾坤无形只能用学的\n");
}
