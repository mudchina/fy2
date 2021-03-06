// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "老云寨");
        set("long", @LONG
这里应该是老云寨了，虽然围绕著你的墙都是木头搭成的，但是仔
细一看，在许多险要的位置都放了不少沙包石堆，後面显然是埋伏人手
的好地方，如果有人贸然从大门口攻进来，肯定会吃大亏的，大寨的门
在你的西边，东边越过一排木桩之後就是大厅。
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
//                __DIR__"npc/bandit_guard" : 2,
//                __DIR__"npc/bandit_leader" : 1
        ]) );

        set("coor/x",-210);
	set("coor/y",-350);
	set("coor/z",90);
	setup();
}

int valid_leave(object me, string exit)
{
        int i;
        object ob;

        if( exit != "east"
        ||      !query("exits/west") )
                return 1;

        message("vision",
                HIY "你听到你身後有几个声音大叫：把门关上！把门关上！一个也不许让他们溜走！\n" NOR
                        "接著「轰」地一声，通往外面的大门已经被一块大石堵死了。\n",
                this_object() );
        delete("exits/west");
        if( ob = find_object(__DIR__"keep15") )
                ob->delete("exits/east");
	if(!me->query("m_success/老云寨"))
        {
                me->set("m_success/老云寨",1);
                me->add("score",100);

        }
        i = 5;
        while(i--) {
                ob = new(__DIR__"npc/bandit_guard");
                ob->move(this_object());
                ob->kill_ob(me);
        }
        return 1;
}

void reset()
{
        object ob;

        ::reset();
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
        
}

void pipe_notify()
{
        object ob;

        message("vision",
                "你听到一阵轧轧的轮盘绞动声，堵住门口的大石慢慢地被移开了。\n",
                this_object() );
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
}
