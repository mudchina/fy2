// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("wuche-axe",1);
	if ( extra < 70) return notify_fail("你的悟彻波风斧法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［三板斧］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	msg = HIY  "$N使出悟彻波风斧法中的［三板斧］，一招连环三斧，手中的"+ weapon->name()+  "劈山般向$n砍出第一斧！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第二斧！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第三斧！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
	me->start_busy(5);
	return 1;
}
