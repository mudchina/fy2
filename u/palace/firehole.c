// Room: /d/chuenyu/trap_castle.c
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火窟");
	set("long", @LONG
才入洞口(hole)，就觉的一阵热气(air)扑面而来。入洞越深，四周空气越热，
渐渐热如火窟。你不禁汗如雨下，转目四望，只见四面山壁(rock)，竞以变作了
暗赤之色，仿佛随时会有火炎涌出。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"interroad",
]));

	set("outdoors", "palace");

	set("coor/x",180);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	remove_call_out("arrowing");
	call_out("arrowing", random(10)+5, ob);
}

int arrowing(object ob)

{
	int i;
	int damage;
	if(ob)
        if( environment(ob) == this_object())
	{
	message_vision(HIR"一股炽热的熔炎形成一个大火球向$N激射而出！！\n", ob);
	message_vision("$N被炽热的熔炎喷得焦偷烂额，奄奄一息！\n"NOR, ob);
 	i = (int)ob->query("eff_kee");
	damage = random(20)+25	;
        ob->set("eff_kee",(int) i - damage );
	i =  (int)ob->query("kee");
	ob->set("kee",(int) i - damage);
	if( environment(ob) == this_object())
	call_out("arrowing",5, ob);	
	}
	else

	return 1;
}

