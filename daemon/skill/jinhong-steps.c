// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С���Ǯ���ء��������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ���������ԡ����ѱ����߳�֮�⡣\n",
	"$nʹ�����ƻ����ء����������ɵ�������\n",
	"$n����һ�㣬һ�С��������¡��ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С������ٷ硹����������Ʈ�˿�ȥ��\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�������������������������粽����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
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
	return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/jinhong-steps/" + action;
}
