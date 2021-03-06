// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("shenji-blade",1);
	if ( extra < 50) return notify_fail("你的［神机刀法］还不够纯熟！\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "shenji-steps")
			return notify_fail("［计出连环］需要［神机步法］的配和！\n");
	tmp = me->query_skill("shenji-steps",1);
	if ( tmp < 50 )return notify_fail("你的［神机步法］还不够纯熟！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［计出连环］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIR  "\n\n$N挥出神机刀法中的绝天灭地的一式－－－计－出－连－环－！！\n\n\n论战篇！\n$N手中$w直劈$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "胜战篇！\n$N手中$w斜刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "敌战篇！\n$N手中$w平削$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "攻战篇！\n$N手中$w横砍$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "混战篇！\n$N手中$w狠剁$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "并战篇！\n$N手中$w反撩$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "败战篇！\n$N手中$w划向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "决战篇！\n$N手中$w加紧，旋风般向$n杀去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(6);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
