// go.c
#pragma optimize all
#include <ansi.h>
inherit F_CLEAN_UP;
mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"out":			"外",
]);

void create() { seteuid(getuid()); }
int drop_things(object me)
{
	int i,max;
	object *inv;
	object env;
	env = environment(me);
	max = me->query_max_encumbrance();
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("equipped")) continue;
		if(inv[i]->query("owner")) continue;
		if(random(max) < inv[i]->weight())
		{
			tell_object(env,"在慌乱中，");
			me->ccommand("drop "+inv[i]->query("id"));
		}
		
	}				

}
int check_flee(object me, string arg) 
{
   mapping 	my, your;
   object 	*enemy;
   int		fp, bp, i;

   i = me->query("combat_exp");
   if ( (random(i) < 300) && userp(me) ) return 1;
   enemy = me->query_enemy();
   for(i=0; i<sizeof(enemy); i++) {
      if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) { 
         fp = COMBAT_D->skill_power(me, "move", 3);
         if(fp<1) fp = 1;
         bp = COMBAT_D->skill_power(enemy[i], "move", 3);
         if(bp<1) bp = 1;
         if(random(fp*2+bp) > fp*2) {
            message_vision(YEL "$N向" + arg + "逃去！\n" NOR, me);
            message_vision(RED "$N身影一闪，挡在了$n的面前！\n" NOR, enemy[i], me);
            return 0;
         }
      }
   }
   return 1;
}


int main(object me, string arg)
{
	string dest, mout, min, dir, blk;
	object env, obj, blocker;
	mapping exit;
	mapping block;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你现在忙得很，不能移动。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}
        if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
		if( objectp(blocker = present(blk, env)) &&  living(blocker))	
		return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 。\n");	
        }

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		if(check_flee(me, dir) == 0) {
			return notify_fail("你被挡了回来。\n");
		} 
		drop_things(me);
		mout = "往" + dir + "落荒而逃了。\n";
		min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
               
	} else {
// Let's add this messages here to make go and come more interesting...
		if( mout = me->query("leave_msg"))
		mout = "往" + dir + mout +" 。\n";
		else mout = "往" + dir + "离开。\n";
		if( min = me->query("arrive_msg"))
		min = min + " 。\n";
		else
		min = "走了过来。\n";
	}
	if (!userp(me) && obj->query("NONPC"))
			return notify_fail("你不可去那里。\n");
	else
	if(obj->valid_enter(me))
			return notify_fail("你不可去别人的私宅。\n");
	if(!me->is_ghost())
	message( "vision", me->name() + mout, environment(me), ({me}) );
	if( me->move(obj) ) {
		me->remove_all_enemy();
		if(!me->is_ghost())
		message( "vision", me->name() + min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
