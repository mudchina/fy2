// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,myexp, hisexp;
	object weapon;
	extra = me->query_skill("fumostaff",1);
	if ( extra < 200) return notify_fail("你的韦陀伏魔杖法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［何去何从］只能对战斗中的对手使用。\n");
	myexp = (int) me->query("combat_exp");
	hisexp= (int)target->query("combat_exp");
	message_vision("$N展开韦陀伏魔杖法，忽然幻出个＂茫＂字！\n",me);
	if(random(hisexp) < myexp * 2)
	{
	target->start_busy(5);
	message_vision("$N被杖法所惑，动作慢了下来！\n",target);
	}
	else
	{
	me->start_busy(2);
	message_vision("$N对你的举动若视无睹！\n",target);	
	}
	return 1;
}
