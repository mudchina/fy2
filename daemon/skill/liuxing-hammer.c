// liuxing-hammer.c
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N手中$w抡动如飞，锤势连绵不断，一招［生生不息］，暴雨般向$n倾泻而去！",
                "force":               70,
                "dodge":                100,
                "parry":                100,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N激进如飞，身影忽隐忽现，一招［明晦隐现］，手中的$w却早到$n的眼前。",
                "damage":               70,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w舞动，一招［雷动九天］挟着震天的撞击之声，猛砸$n的$l。",

                "damage":               70,
		"force" :		200,
                "dodge":                -100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中的$w一转，一招［无中生有］从四面八方盖向$n的$l",
                "damage":               40,
		"force" :		200,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":
"$N一抖手中的$w，一招［我法俱空］锤影漫天飞舞，虚虚实实的挥向$n的$l",
                "force":               100,
		"damage" : 		50,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("你必须先找一个锤或者是类似的武器，才能练盘古九式。\n");

        if( (int)me->query("kee") < 60 )
                return 
notify_fail("你的体力不够练反转流星锤法，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 15;}
 
string *parry_msg = ({
        "$n后退一步，一招［不生不灭］手中的$v猛的砸向$N的$w。\n",
	"$n身形微顿，手中的$v一招［指引无生］反捣$N的必救之处。\n",
	"$n手中的$v从下往上急挥，一招［法归本性］磕开了$N手中的$w\n",
});

string *unarmed_parry_msg = ({
	"$n一招［阴阳轮转］，手中的$v从偏锋击向$N的太阳大穴。\n",
	"$n手中的$v从左划右，一招［万劫无移］封住了$N的攻势。\n",
	"$n凌空三连翻，一招［芥纳须弥］手中的$v反击$N的后脑，逼得$N中途撤招。\n",
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
	return 0;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 10;
}
string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/liuxing-hammer/" + action;
}


