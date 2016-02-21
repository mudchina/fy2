// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("suiyuan-sword",1) ;
	if ( extra < 150) return notify_fail("你的随缘无忧剑法不够纯熟！\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［一切随缘］只能对战斗中的对手使用。\n");
	weapon = target->query_temp("weapon");
	myexp = (int)me->query("combat_exp");
	hisexp= (int)target->query("combat_exp");
	if(random(hisexp) < myexp  && weapon)	
	{
	message_vision(
HIW "\n\n$N使出一式［一切随缘］，剑身似灵蛇般缠住$n手中的兵刃，"+ 
weapon->name()+  "脱手而飞！\n\n" NOR, me,target);
	if( weapon->unequip()) weapon->move(environment(target));
	}
	else
	{
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra*2);
	msg = HIR+ "\n\n$N使出一式［一切随缘］，手中的"+(me->query_temp("weapon"))->name()+"如闪电般直刺$n的$l！\n\n"+ NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra*2);
	me->start_busy(3);
	}
	return 1;
}
