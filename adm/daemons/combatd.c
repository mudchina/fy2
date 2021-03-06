// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// combatd.c

#pragma optimize all

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define LOWER_LIMIT 2000
inherit F_DBASE;

string *guard_msg = ({
        CYN "$N注视著$n的行动，企图寻找机会一击成功。\n" NOR,
        CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
        CYN "$N以守为攻，想要找出$n的破绽。\n" NOR,
        CYN "$N缓缓地移动着脚步，等待着最佳的出招方位。\n" NOR,
        CYN "$N眼睛眨也不眨地盯着$n，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
        HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
        HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
        HIW "$N一眼瞥见$n，大叫一声冲了过来！\n" NOR,
        HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
        HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
        HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
        CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
        CYN "\n$N双手一拱，笑著说道：承让！\n\n" NOR,
        CYN "\n$N胜了这招，向後跃开三尺，笑道：承让！\n\n" NOR,
        CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
        CYN "\n$n向後退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
        CYN "\n$n向後一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

void create()
{
        seteuid(getuid());
        set("name", "战斗精灵");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;

//      return "造成 " + damage + " 点" + type + "。\n";

        if( damage == 0 ) return "结果没有造成任何伤害。\n";

        switch( type ) {
        case "拉伤":
        case "割伤":
                if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l划出一道细长的血痕。\n";
                else if( damage < 40 ) return "结果「嗤」地一声划出一道伤口！\n";
                else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
                else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
                break;
        case "刺伤":
                if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
                else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
                else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
                else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
                break;
        case "瘀伤":
                if( damage < 10 ) return  "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
                else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
                else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
                else if( damage < 160 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
                else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
                else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
                break;
        case "抓伤":
                if( damage < 10 ) return "结果只是轻轻地抓到，比抓痒稍微重了点。\n";
                else if( damage < 20 ) return "结果在$p的$l抓出几条血痕。\n";
                else if( damage < 40 ) return "结果一抓命中，$n的$l被抓得鲜血飞溅！\n";
                else if( damage < 80 ) return "结果「嗤」地一声，$l被抓得深可见骨！！\n";
                else if( damage < 120 ) return "结果一抓命中，$n的$l被抓得血肉横飞！！！\n";
                else if( damage < 160 ) return "结果这一下「嗤」地一声抓得$n连晃好几下，差一点摔倒！\n";
                else if( damage < 240 ) return "结果$n哀号一声，$l被抓得筋断骨折！！\n";
                else return "结果只听见$n一声惨嚎，$l被抓出五个血窟窿！鲜血溅得满地！！\n";
                break;
        case "反弹伤":
                if( damage < 5 ) return "$N受到$n$z的反震，闷哼一声。\n";
                else if( damage < 10 ) return  "$N被$n的$z震得气血翻腾，大惊失色。\n";
                else if( damage < 20 ) return "$N被$n的$z震得站立不稳，摇摇晃晃。\n";
                else if( damage < 40 ) return "$N被$n以$z反震，「嘿」地一声退了两步。\n";
                else if( damage < 80 ) return "$N被$n的$z反弹回来的力量震得半身发麻。\n";
                else if( damage < 120 ) return "$N被$n的$z反弹力一震，胸口有如受到一记重击，连退了五六步！\n";
                else if( damage < 160 ) return "$N被$n的$z一震，眼前一黑，身子向後飞出丈许！！\n";
                else return "$N被$n的$z一震，眼前一黑，狂吐鲜血，身子象断了线的风筝向後飞去！！\n";
                break;
        default:
                if( !type ) type = "伤害";
                if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
                else if( damage < 20 ) str = "结果造成轻微的";
                else if( damage < 30 ) str = "结果造成一处";
                else if( damage < 50 ) str = "结果造成一处严重";
                else if( damage < 80 ) str = "结果造成颇为严重的";
                else if( damage < 120 ) str = "结果造成相当严重的";
                else if( damage < 170 ) str = "结果造成十分严重的";
                else if( damage < 230 ) str = "结果造成极其严重的";
                else str =  "结果造成非常可怕的严重";
                return str + type + "！\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "精神饱满，正处于巅峰状态。" NOR;
        if( ratio > 95 ) return HIG "似乎只受了点轻伤，但无伤大体。" NOR;
        if( ratio > 90 ) return HIY "看起来可能受了几处皮肉伤。" NOR;
        if( ratio > 80 ) return HIY "受了几处创伤，不过似乎并不碍事。" NOR;
        if( ratio > 60 ) return HIY "受伤不轻，正在流着血。" NOR;
        if( ratio > 40 ) return HIR "气息粗重，动作散乱，已经在走下坡路了。" NOR;
        if( ratio > 30 ) return HIR "已经眼神散乱，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "遍体鳞伤，只剩下最后一口气了。" NOR;
        if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
        if( ratio > 5  ) return RED "瞳空放大，已经奄奄一息，命在旦夕了。" NOR;
        return RED "满身鲜血，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起来精神饱满，正处于巅峰状态。" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
        if( ratio > 90 ) return HIY "看起来可能有些不济。" NOR;
        if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
        if( ratio > 60 ) return HIY "气喘嘘嘘，脸色惨白。" NOR;
        if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
        if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
        if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
        return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}
void netscape_report_status(object player)
{
	string status;
	string fstatus="";
	object weapon,ob;
	string skill_type,parry_type;
	int tmp,attack_points,parry_points,dodge_points;
	mapping my;
	ob = player;
	my = player->query_entire_dbase();
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, parry_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
status = "";
if((int) my["gin"] != (int)ob->query_temp("ns/gin")){
	status +=sprintf("0:%d;",my["gin"]);
	ob->set_temp("ns/gin",my["gin"]);	}
if((int) my["eff_gin"] != (int)ob->query_temp("ns/eff_gin")){
        status +=sprintf("1:%d;",my["eff_gin"]);
        ob->set_temp("ns/eff_gin",my["eff_gin"]);       }
if((int) my["max_gin"] != (int)ob->query_temp("ns/max_gin")){
        status +=sprintf("2:%d;",my["max_gin"]);
        ob->set_temp("ns/max_gin",my["max_gin"]);       }
if((int) my["kee"] != (int)ob->query_temp("ns/kee")){
        status +=sprintf("3:%d;",my["kee"]);
        ob->set_temp("ns/kee",my["kee"]);       }
if((int) my["eff_kee"] != (int)ob->query_temp("ns/eff_kee")){
        status +=sprintf("4:%d;",my["eff_kee"]);
        ob->set_temp("ns/eff_kee",my["eff_kee"]);       }
if((int) my["max_kee"] != (int)ob->query_temp("ns/max_kee")){
        status +=sprintf("5:%d;",my["max_kee"]);
        ob->set_temp("ns/max_kee",my["max_kee"]);       }
if((int) my["sen"] != (int)ob->query_temp("ns/sen")){
        status +=sprintf("6:%d;",my["sen"]);
        ob->set_temp("ns/sen",my["sen"]);       }
if((int) my["eff_sen"] != (int)ob->query_temp("ns/eff_sen")){
        status +=sprintf("7:%d;",my["eff_sen"]);
        ob->set_temp("ns/eff_sen",my["eff_sen"]);       }
if((int) my["max_sen"] != (int)ob->query_temp("ns/max_sen")){
        status +=sprintf("8:%d;",my["max_sen"]);
        ob->set_temp("ns/max_sen",my["max_sen"]);       }
	if( status != "") fstatus = status +"\n";
	status = "";
if((int) my["atman"] != (int)ob->query_temp("ns/atman")){
        status +=sprintf("13:%d;",my["atman"]);
        ob->set_temp("ns/atman",my["atman"]);       }
if((int) my["max_atman"] != (int)ob->query_temp("ns/max_atman")){
        status +=sprintf("14:%d;",my["max_atman"]);
        ob->set_temp("ns/max_atman",my["max_atman"]);       }
if((int) my["force"] != (int)ob->query_temp("ns/force")){
        status +=sprintf("15:%d;",my["force"]);
        ob->set_temp("ns/force",my["force"]);       }
if((int) my["max_force"] != (int)ob->query_temp("ns/max_force")){
        status +=sprintf("16:%d;",my["max_force"]);
        ob->set_temp("ns/max_force",my["max_force"]);       }
if((int) my["mana"] != (int)ob->query_temp("ns/mana")){
        status +=sprintf("17:%d;",my["mana"]);
        ob->set_temp("ns/mana",my["mana"]);       }
if((int) my["max_mana"] != (int)ob->query_temp("ns/max_mana")){
        status +=sprintf("18:%d;",my["max_mana"]);
        ob->set_temp("ns/max_mana",my["max_mana"]);       }
	if( status != "" ) fstatus += status + "\n";
	status = "";
tmp = my["food"]* 100/player->max_food_capacity();
if((int) tmp != (int)ob->query_temp("ns/food")){
        status +=sprintf("19:%d;",tmp);
        ob->set_temp("ns/food",tmp);       }
tmp =my["water"] * 100/player->max_water_capacity();
if((int) tmp != (int)ob->query_temp("ns/water")){
        status +=sprintf("20:%d;",tmp);
        ob->set_temp("ns/water",tmp);       }
tmp = attack_points + 1;
if((int) tmp != (int)ob->query_temp("ns/offense")){
        status +=sprintf("9:%d;",tmp);
        ob->set_temp("ns/offense",tmp);       }
tmp = ob->query_temp("apply/damage");
if((int) tmp != (int)ob->query_temp("ns/damage")){
        status +=sprintf("10:%d;",tmp);
        ob->set_temp("ns/damage",tmp);       }
tmp = (dodge_points/2 + (weapon? parry_points: (parry_points/2)));
if((int) tmp != (int)ob->query_temp("ns/defense")){
        status +=sprintf("11:%d;",tmp);
        ob->set_temp("ns/defense",tmp);       }
tmp = ob->query_temp("apply/armor");
if((int) tmp != (int)ob->query_temp("ns/armor")){
        status +=sprintf("12:%d;",tmp);
        ob->set_temp("ns/armor",tmp);       }
if((int) my["combat_exp"] != (int)ob->query_temp("ns/combat_exp")){
        status +=sprintf("21:%d;",my["combat_exp"]);
        ob->set_temp("ns/combat_exp",my["combat_exp"]);       }
if((int) my["bellicosity"] != (int)ob->query_temp("ns/bellicosity")){
        status +=sprintf("22:%d;",my["bellicosity"]);
        ob->set_temp("ns/bellicosity",my["bellicosity"]);       }
	if( status != "") 
		fstatus += status + "\n";
if(fstatus)
tell_object(player,fstatus);
}

varargs void report_status(object ob, int effective)
{
	if(ob->query_temp("using_netscape"))
			netscape_report_status(ob);
        if( effective ) 
                message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("eff_kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
        else
                message_vision( "( $N" + status_msg(
                        (int)ob->query("kee") * 100 / 
(int)ob->query("max_kee") ) 
                        + " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int status, level, power;
	int enc, max;
        if( !living(ob) ) return 0;
	if(ob->query_temp("is_unconcious")) return 0;
	max = (int) ob->query_max_encumbrance();
	enc = (max  + max/10 - 1 - (int) ob->query_encumbrance() ) * 10 / max;
// npcs does not have this restrication
	if(!userp(ob)) enc = 10;
        level = ob->query_skill(skill);
        switch(usage) {
                case SKILL_USAGE_ATTACK:
                        level += ob->query_temp("apply/attack");
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
                        break;
                case SKILL_USAGE_MOVE:
                        level += ob->query_temp("apply/move");
                        break;
        }

        if( !level ) return (int)ob->query("combat_exp") / 50 * enc/10;

        if( (status = ob->query("max_sen")) > 0 )
                power = (level*(level/10)*(level/10)) / 5 * (int)ob->query("sen") / 
status;
        else
                power = (level*(level/10)*(level/10)) / 5;

        if(usage == SKILL_USAGE_MOVE) return power * enc/10;
        else return (power + ((int)(ob->query("combat_exp"))/25))* enc/10;
}
void fight_reward(object winner, object loser)
{
        object owner;

        if(owner=winner->query("possessed"))  winner = owner;
        winner->win_enemy(loser);
}
void fight_penalty(object winner, object loser)
{
        object owner;

        if(owner=loser->query("possessed"))  loser = owner;
        loser->lose_enemy(winner);
}
// do_protect()
// a function that checks to see if there is anything/anyone protects our victim

int do_protect(object me, object weapon,int ap, object victim)
{
	object *pros;
	string output;
	int pp;
	string parry_skill;
	int i;
	pros = victim->query_temp("protectors");
	i = random(sizeof(pros));
	if(!pros[i]) { 
	pros -= ({ pros[i] });
	if(!sizeof(pros)) victim->delete_temp("protectors");
	return 0;     }
	
	if(environment(pros[i]) != environment(victim)) return 0;
	if(pros[i]->is_character())
	{
                //      Check if the pros[i] can parry this attack for the victim.
                if( pros[i]->query_temp("weapon") ) {
                        pp = skill_power(pros[i], "parry", 
SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = skill_power(pros[i], "unarmed",SKILL_USAGE_DEFENSE)/2;
                        else pp = skill_power(pros[i], "unarmed", 
SKILL_USAGE_DEFENSE);
                }
                if( pros[i]->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;
                if( random(ap + pp)< pp ) {
        	if(pros[i]->query_temp("weapon")){
                parry_skill = pros[i]->query_skill_mapped("parry");
                if( !parry_skill)  parry_skill = "parry";
        	}
        	else
        	{
                parry_skill = pros[i]->query_skill_mapped("unarmed");
                if(!parry_skill) parry_skill = "unarmed";
        	}
		output = SKILL_D(parry_skill)->query_parry_msg(weapon);
        	if( pros[i]->query_temp("weapon"))
        	output = replace_string( output, "$v", (pros[i]->query_temp("weapon"))->name());
		output = replace_string( output, "$n", pros[i]->name()); 
		output = replace_string( output, "$p", pros[i]->name()); 
		victim->set_temp("protectors_msg", output);
		return 1;
		}
		else
			return 0;
	}
	else {
	victim->set_temp("protectors_msg",pros[i]->protection_msg());
	return pros[i]->protection();
	}

}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int 
attack_type, string attack_msg, string damtype)
{
        mapping my, your, action;
        string limb, *limbs, result;
        string attack_skill, force_skill, martial_skill, dodge_skill, 
parry_skill, absorb_skill;
        mixed foo;
        int ap, dp, pp;
        int damage, damage_bonus ;
        int wounded = 0;
        int absorb_vic;
	int  bounce = 0;
        // (0.5) First see if we are capable of attack
	if(me->query_temp("is_unconcious")) return 1;
	
        my = me->query_entire_dbase();
        your = victim->query_entire_dbase();

        //
        // (1) Find out what action the offenser will take.
        //
        action = me->query("actions");
        if( !mapp(action) ) {
                me->reset_action();
                action = me->query("action");
                if( !mapp(action) ) {
                        CHANNEL_D->do_channel( this_object(), "sys",
                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"), 
me->query("actions", 1)));
                        return 0;
                }
        }
        result = "\n" + action["action"] + "！\n";
	if(stringp(attack_msg)) result = "\n" + attack_msg + "\n";
        //
        // (2) Prepare AP, DP for checking if hit.
        //
        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else                                    attack_skill = "unarmed";

        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];

        ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;

        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( action["dodge"])
		dp -= dp * action["dodge"] / 1000 ;
        if( dp < 1 ) dp = 1;
        if( victim->is_busy() ) dp /= 3;
	//	(2.5)	if player is enforced, let him/her relase the force even without hit others
	if( userp(me))
	{
                        if( my["force_factor"] && (my["force"] >
			my["force_factor"]) ) 
					my["force"] -= my["force_factor"];
			else
					my["force_factor"] = 0;	
	}
	// (2.5) Let's see what/who can protect our victim, $N, $n,...all applies
   if(sizeof(victim->query_temp("protectors")) && do_protect(me,weapon,ap,victim)) 
   {
		result += victim->query_temp("protectors_msg");
		damage = RESULT_PROTECT;	
   }
   else
   {
        //
        // (3) Fight!
        //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
        //     AP and DP are greater than zero, so we always have chance to hit
        //     or be hit.
        //
        if( random(ap + dp) < dp ) {       // Does the victim dodge this hit?

                dodge_skill = victim->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

                if( dp < ap && (!userp(victim) || !userp(me)) 
                &&      random(your["gin"]*100/your["max_gin"] + your["int"]) 
> 50 ) {
                        your["potential"] += 1;
			your["combat_exp"] +=5;

                        victim->improve_skill("dodge", 1);
                }

    // This is for NPC only. NPC have chance to get exp when fail to hit.
                     if( (ap < dp) && !userp(me) ) {
                        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
                        me->improve_skill(attack_skill, random(my["int"]));
                }
                damage = RESULT_DODGE;

        } else {

                //
                //      (4) Check if the victim can parry this attack.
                //
                if( victim->query_temp("weapon") ) {
                        pp = skill_power(victim, "parry", 
SKILL_USAGE_DEFENSE);
                        if( !weapon ) pp *= 2;
                } else {
                        if( weapon ) pp = skill_power(victim, "unarmed",SKILL_USAGE_DEFENSE)/2;
                        else pp = skill_power(victim, "unarmed", 
SKILL_USAGE_DEFENSE);
                }
        if( action["parry"])
                pp -= pp * action["parry"] / 1000 ;

                if( victim->is_busy() ) pp /= 3;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp)< pp ) {

	if(victim->query_temp("weapon")){
		parry_skill = victim->query_skill_mapped("parry");
		if( !parry_skill)  parry_skill = "parry";
	}
	else
	{
		parry_skill = victim->query_skill_mapped("unarmed");
		if(!parry_skill) parry_skill = "unarmed";	
	}
		result += SKILL_D(parry_skill)->query_parry_msg(weapon);
                        if( pp < ap && (!userp(victim) || !userp(me)) 
                        &&      random(your["gin"]*100/your["max_gin"] + 
your["int"]) > 50 ) {
                                your["potential"] += 1;
				your["combat_exp"] +=5;
                                victim->improve_skill("parry", 1);
                        }
                        damage = RESULT_PARRY;
                } else {

                        //
                 //      (5) We hit the victim and the victim failed to parry
                        //

                        damage = (me->query_temp("apply/damage"))+ 2;
                        damage = (damage + random(damage)) / 2;
                        if( action["damage"] )
                                damage += action["damage"] * damage / 1000;

                        damage_bonus = me->query_str();
			damage_bonus = damage_bonus * damage_bonus / 10;
// if use weapon, effectiveness only 2/3
			if(weapon) damage_bonus -= damage_bonus/3;
                        // Let force skill take effect.
                        if( my["force_factor"] && (my["force"] > 
my["force_factor"]) ) {
                                if( force_skill = 
me->query_skill_mapped("force") ) {
                                        foo = 
SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
                                        if( stringp(foo) ) result += foo;
                                        else if( intp(foo) ) damage_bonus += 
foo;
                                }
                        }

                        if( action["force"] )
                                damage_bonus += action["force"] * 
damage_bonus / 1000;

                        if( martial_skill = 
me->query_skill_mapped(attack_skill) ) {
                                foo = SKILL_D(martial_skill)->hit_ob(me, 
victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        // Let weapon or monster have their special damage.
                        if( weapon ) {
                                foo = weapon->hit_ob(me, victim, 
damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        } else {
                                foo = me->hit_ob(me, victim, damage_bonus);
                                if( stringp(foo) ) result += foo;
                                else if(intp(foo) ) damage_bonus += foo;
                        }

                        if( damage_bonus > 0 )
                                damage += (damage_bonus + 
random(damage_bonus))/2;
                        if( damage < 0 ) damage = 0;

                        // Let combat exp take effect
				bounce = your["combat_exp"];
                        while( random(bounce) > my["combat_exp"] ) {
                                damage -= damage / 5;
                                bounce/= 2;
                        }
				bounce = 0;
			// (5.4) see how much damage our flexibility can absorb
				damage -=  ((int)victim->query_fle());
				damage -=  (int)victim->query_temp("apply/extra_fle");
                        if( damage < 0 ) damage = 0;
			//
			//	(5.5) Check if victim can absorb the damage
			//
				absorb_vic = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth") * 2  ;	
				if( victim->query_skill("iron-cloth"))
				{
                absorb_skill = victim->query_skill_mapped("iron-cloth");
                if( !absorb_skill ) absorb_skill = "iron-cloth";
                result += SKILL_D(absorb_skill)->query_absorb_msg();

				}
				damage_bonus = me->query_skill("iron-cloth");
				if( (damage - absorb_vic) < 0 )
				{
                                absorb_skill = victim->query_skill_mapped("iron-cloth");
                                if( absorb_skill)
                                bounce = 0 - ((SKILL_D(absorb_skill)->bounce_ratio()) * (damage - absorb_vic) / 10);
                                else
                                bounce = 0;
				absorb_skill = me ->query_skill_mapped("iron-cloth");
                               if( absorb_skill)
                                bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * damage_bonus / 10;
                                else
                                bounce -= 0;
				if ( bounce < 0 ) bounce = 0;
                        me->receive_damage("kee", bounce, victim );
                        result += damage_msg(bounce, "反弹伤");
				}
				else
				{

                        //
                        //      (6) Inflict the damage.
                        //
                        damage = victim->receive_damage("kee", damage, me );

                        if( (me->is_killing(victim) || weapon)
                        && random(damage) > 
(int)victim->query_temp("apply/armor") ) {
    // We are sure that damage is greater than victim's armor here.
                                victim->receive_wound("kee",
                                        damage - 
(int)victim->query_temp("apply/armor"), me);
                                wounded = 1;
                        }
		if(stringp(damtype)) 
		result += damage_msg(damage, damtype);
		else
                result += damage_msg(damage, action["damage_type"]);

				}
                        //
                        //      (7) Give experience
                        //

                        if( !userp(me) || !userp(victim) ) {
                                if( (ap < dp)
                                &&      (random(my["sen"]*100/my["max_sen"] ) 
> 50) ) {
                                        if(!random(4)) my["potential"] += 1;
					if(!random(4)) my["combat_exp"] +=5;
                                        me->improve_skill(attack_skill, 1);
                                }
                                if( random(your["max_kee"] + your["kee"]) < 
damage ) {
                                        your["potential"] += 1;
                                                your["combat_exp"] += 5;
                                }
                        }
                }
        } 
   } //protector
        result = replace_string( result, "$l", limb );
	if( victim->query_temp("weapon"))
	result = replace_string( result, "$v", (victim->query_temp("weapon"))->name());
	if( victim->query_skill_mapped("iron-cloth"))
	result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));
        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );

        message_vision(result, me, victim );
        if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
                if( damage > 0 )
                        tell_object(me, sprintf( GRN 
"AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(me, sprintf( GRN 
"AP：%d，DP：%d，PP：%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }

        if(  damage > 0  ) {
		if ( bounce > 0) report_status(me, 0);
		else
                report_status(victim, wounded);
                if( victim->is_busy() ) victim->interrupt_me(me);
                if( (!me->is_killing(your["id"])) && 
(!victim->is_killing(my["id"])) &&
((victim->query("kee")*2 <= victim->query("max_kee")) ||
(me->query("kee")*2 <= me->query("max_kee")) )) {
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
			fight_reward(me, victim);
			fight_penalty(me, victim);			
                        message_vision( 
winner_msg[random(sizeof(winner_msg))], me, victim);
                }
        }

        if( functionp(action["post_action"]) )
                evaluate( action["post_action"], me, victim, weapon, damage);
	WEAPON_D->wear_off(me,victim,weapon,damage);
// See if the attack is fast enough to make another attack!
//	if( random( (int)me->query_agi()+(int)victim->query_agi()) < ((int) me->query_agi())/2)
//		 do_attack(me, victim,me->query_temp("weapon"),TYPE_REGULAR);
        // See if the victim can make a riposte.
//        if( attack_type==TYPE_REGULAR
//        &&      damage < 1
//        &&      victim->query_temp("guarding") ) {
//                victim->set_temp("guarding", 0);
//                if( random(my["cps"]) < 2 ) {
//                        message_vision("$N一击不中，露出了破绽！\n", me);
//                        do_attack(victim, me,victim->query_temp("weapon"), 
//TYPE_QUICK);
//                } else {
//                        message_vision("$N见$n攻击失误，趁机发动攻击！\n", 
//victim, me);
//                        do_attack(victim, me, victim->query_temp("weapon"), 
//TYPE_RIPOSTE);
//                }
//        }
}

//      fight()
//
//This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
        object ob;

        if( !living(me) ) return;
// as long as we are in a fight, we are nervous, our 心神 drops
	me->add("sen",-1);
        if( !me->visible(victim)
        && (random(110 + (int)me->query_skill("perception")) < 100) )
                return;

// If victim is busy or unconcious, always take the chance to makeanattack.
        if( victim->is_busy() || !living(victim) ) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

        // Else, see if we are brave enough to make an aggressive action.
        } else if( (int) me->query_agi() > random((int) victim->query_agi()))
		{
	if( (int) me->query_cor() > random((int) victim->query_cps())) {
                me->set_temp("guarding", 0);
                if( !victim->is_fighting(me) ) victim->fight_ob(me);
                do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        // Else, we just start guarding.
        	} else if( !me->query_temp("guarding") ) {
                me->set_temp("guarding", 1);
                message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
                return;
        	} else return;
	}else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
        // Don't let NPC autofight NPC.
        if( !userp(me) && !userp(obj) ) return;

 // Because most of the cases that we cannot start a fight cannot be checked
// before we really call the kill_ob(), so we just make sure we have no 
        // aggressive callout wating here.
        if( me->query_temp("looking_for_trouble") ) return;
        me->set_temp("looking_for_trouble", 1);

        // This call_out gives victim a chance to slip trough the fierce guys.
        call_out( "start_" + type, 0, me, obj);
}
void auto_follow(object follower, object leader)
{
	int fexp, lexp;
	fexp = follower->query("combat_exp");
	lexp = leader->query("combat_exp");
	if( fexp <=0 ) fexp =0;
	if( lexp <=0 ) lexp =0;
	if( random(lexp) > fexp/10 )	
	follower->set_leader(leader);
	else
	follower->set_leader(0);
}
void start_berserk(object me, object obj)
{
        int bellicosity;

        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        bellicosity = (int)me->query("bellicosity");
        message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

        if(     ((int)me->query("force") + (int)me->query_tol() * 10)> (random(bellicosity) + 
bellicosity)/2 ) return;
        if( userp(obj) &&
                (int) obj->query("combat_exp") < LOWER_LIMIT 
          )	return;

        if( bellicosity > (int)me->query("score") 
        &&      !wizardp(obj) ) {
                message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
                        + "看你实在很不顺眼，去死吧。\n", me, obj);
                me->kill_ob(obj);
        } else {
                message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
                        + "，" + RANK_D->query_self_rude(me) + 
"正想找人打架，陪我玩两手吧！\n",
                        me, obj);
                me->fight_ob(obj);
        }
}

void start_hatred(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?         
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our hatred! Charge!
        message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, 
obj);
        me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We found our vendetta opponent! Charge!
        me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
        if( !me || !obj ) return;                               
// Are we still exist( not becoming a corpse )?

        me->set_temp("looking_for_trouble", 0);

        if(     me->is_fighting(obj)                            
// Are we busy fighting?
        ||      
!living(me)                                                     
// Are we capable for a fight?
        ||      environment(me)!=environment(obj)       
// Are we still in the same room?
        ||      environment(me)->query("no_fight")      
// Are we in a peace room?
        )       return;

        // We got a nice victim! Kill him/her/it!!!
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch(event) {
                case "dead":
                        message_vision("\n$N死了。\n\n", ob);
                        break;
                case "unconcious":
                        
message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", 
ob);
                        break;
        }
}

void winner_reward(object killer, object victim)
{
	object owner;

        if(owner=killer->query("possessed")) killer = owner;
        killer->defeated_enemy(victim);
}
void loser_penalty(object killer, object victim)
{
        object owner;

        if(owner=victim->query("possessed")) victim = owner;
        victim->defeated_by_enemy(killer);
}

void killer_reward(object killer, object victim)
{
        int bls;
        string vmark;
	int i,msize,exp, pot, score ;
	object owner;
	object *mem;
	object realkiller;
        // Call the mudlib killer apply.
	realkiller = killer;
        if(owner=killer->query("possessed")) killer = owner;
        killer->killed_enemy(victim);
        if( userp(victim) ) {
		if((int) killer->query("combat_exp") <
		   (int) victim->query("combat_exp")/10 * 9)
		killer->set("last_good_kill",(int)killer->query("mud_age"));	
                killer->add("PKS", 1);
                bls = 10;
        } else {
                killer->add("MKS", 1);
                bls = 1;
        }

        // NPC got 10 times of bellicosity than user.
        killer->add("bellicosity", bls * (userp(killer)? 1: 2));
	if(!interactive(victim))
        if( stringp(vmark = victim->query("vendetta_mark")) )
                killer->add("vendetta/" + vmark, 1);
// Now let's add the quest reward here -- Tie
	if(mapp(killer->query("quest")))
	{
	mapping quest;
        if( interactive(killer) && (quest = killer->query("quest"))
                && ( (int)killer->query("task_time") >= time())
                && (victim->name() == quest["quest"])
                && !userp(victim))
        {
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
// put a limit on max exp we can get from a quest
        if( exp > 100) exp = 100;
        exp = exp * (int) killer->query_temp("quest_number");
        pot = exp/ 10 + 1;
//      for weekly race, each quest worth same, 20
//        score = quest["score"]/2 + random(quest["score"]/2);
        score = -1;
        mem = killer->query_team();
        msize = sizeof(mem);
        if(msize < 1) msize =1;
        if( msize <= 1) {
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
        killer->add("score", score);
        tell_object(killer,HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +NOR);
        }
        else{
        exp = exp / msize;
        pot = pot / msize;
        score = -1;
        for(i=0;i<sizeof(mem);i++)
        {
                if(mem[i])
                if( (mem[i]->query_temp("ttarget") == victim->query("id"))
                || mem[i] == killer)
                if(environment(killer) == environment(mem[i])){
        mem[i]->add("combat_exp", exp);
        mem[i]->add("potential", pot);
        mem[i]->add("score", score);
        tell_object(mem[i],HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" NOR);
                          }
        }
        }
        killer->set("quest", 0 );
        }
	}
	else
	{
	string quest;
	if( interactive(killer) && (quest = killer->query("quest"))
		&& ( (int)killer->query("task_time") >= time())
		&& (victim->name() == quest)
		&& !userp(victim))
	{
	exp = random(100)+10;
// put a limit on max exp we can get from a quest
        exp = exp * (int) killer->query_temp("quest_number")/5;
	exp += 1;	
        pot = exp/ 10 + 1;
//	for weekly race, each quest worth same, 20
//        score = quest["score"]/2 + random(quest["score"]/2);
//	score = 1;
	mem = killer->query_team();
	msize = sizeof(mem);	
	if(msize < 1) msize =1;
	if( msize <= 1) {	
        killer->add("combat_exp", exp);
        killer->add("potential", pot);
        killer->add("score", -score);
	killer->add("QUEST",1);
        tell_object(killer,HIY"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" NOR);
//        chinese_number(score)+"点综合评价\n"NOR);
	}
	else{
	exp = exp / msize;
	pot = pot / msize;
	score = 1;
	for(i=0;i<sizeof(mem);i++)
	{
		if(mem[i])
		if( (mem[i]->query_temp("ttarget") == victim->query("id"))
		|| mem[i] == killer)
		if(environment(killer) == environment(mem[i])){
        mem[i]->add("combat_exp", exp);
        mem[i]->add("potential", pot);
        mem[i]->add("score", -score);
	mem[i]->add("QUEST",1);
        tell_object(mem[i],HIY"你被〔天孙〕奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" NOR);
//        chinese_number(score)+"点综合评价\n"NOR);
			  }	
	}	
	}
        killer->set("quest", 0 );
	}
	}
// let's add the hired killer things here
        if( ! userp(realkiller) && realkiller->query("hired_killer")
	&& (string)victim->query("id") == (string)realkiller->query("haunttar"))
                {
                message_vision("$N一拱手：幸不辱使命！后会有期！\n",realkiller);
                destruct(realkiller);
                }

}
 
void victim_penalty(object victim, object killer)
{
	string msg="莫名其妙地死了。";
	mapping actions;
	object env;
	if( userp(victim)){
		victim->add("KILLED",1);
	if(objectp(killer))
	{
		msg="被"+killer->name();
		actions = killer->query("actions");
		switch(actions["damage_type"]) {
		case "拉伤":
	        case "割伤":
			msg+="砍死了。";
			break;
		case "刺伤":
			msg+="刺死了。";
			break;
		case "瘀伤":
			msg+="击死了。";
                        break;
		case "抓伤":
			msg+="抓死了。";
			break;
		case "反弹伤":
                        msg+="震死了。";
                        break;
		default:
			msg+="杀死了。";
		}
	}	
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s"+msg, victim->name(1)));
	env = environment(victim);
	if(objectp(env))
	if ( env->query("no_death_penalty")) 
	{
	victim->set_temp("no_death_penalty",1);
	return;
	}
		                victim->clear_condition();
                // Give the death penalty to the dying user.
                victim->set("bellicosity", 0);
                victim->add("combat_exp", -(int)victim->query("combat_exp") /50);
                victim->delete("vendetta");
                if( victim->query("thief") )
                        victim->set("thief", (int)victim->query("thief") / 2);
                if( (int)victim->query("potential") >
(int)victim->query("learned_points"))
                        victim->add("potential",
                                ((int)victim->query("learned_points") -
(int)victim->query("potential"))/2 );
if((random(((int) victim->query("combat_exp")))+1000)>3000)
                victim->skill_death_penalty();
	}
}
