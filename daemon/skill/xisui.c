
inherit FORCE;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("洗髓经只能用学的。\n");
}

 
int effective_level() { return 20;}

string *absorb_msg = ({
        "$N如击败革，一股大力从$n身上反弹回来。\n",
        "$n全身似已脱胎换骨，一股弹力反击入$N。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 3;
}

int learn_bonus()
{
	return -70;
}
int practice_bonus()
{
	return -20;
}
int black_white_ness()
{
	return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/xisui/" + action;
}

