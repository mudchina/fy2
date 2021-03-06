// TIE@FY3
inherit SKILL;
mapping *action = ({
([      "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
        "dodge": -10,
        "damage": 30,
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
        "dodge": -20,
        "damage": 40,
        "damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
        "dodge": -30,
        "damage": 50,
        "damage_type": "挫伤"
]),
([      "action": "$N施出「拨狗朝天」，$w由下往上向$n撩去",
        "dodge": -20,
        "damage": 40,
        "damage_type": "挫伤"
]),
([      "action": "$N施展出打狗棒法中的「守棒揣狗」，$w往$n要害递去",
        "dodge": -20,
        "damage": 40,
        "damage_type": "挫伤"
]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 25 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
notify_fail("你必须先找一根木棍或者是类似的武器，才能练棍法。\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("你的体力不够练这门棍法，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 21;}
 
string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("beggar") + "/dagou-stick/" + action;
}

