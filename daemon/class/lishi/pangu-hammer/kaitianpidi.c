// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query("force")/10 ;
	if ( extra < 30) return notify_fail("你的内力太弱，还运用不出［开天辟地］这绝招！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［开天辟地］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);
	msg = HIY  "$N高高得举起手中的"+ weapon->name()+  "集全身之内力，向$n猛然挥下！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->set("force",0);
	me->add_temp("apply/damage", -extra);
	me->start_busy(3);
	return 1;
}
