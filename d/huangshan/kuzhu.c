// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "苦竹溪");
        set("long", @LONG
沿途盛产苦竹，所以溪水也有淡淡的涩味，但是良药苦口，苦竹更
是入药的上品，所以来往之人依然爱饮此泉，对于解乏提神极有帮助。
更有人特地来此取竹根入药。于是便有山民在此伐竹贩卖。
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       ]) );
        set("item_desc", ([
                "苦竹溪": "你可以试着从溪（xi）中喝（drink）一口。\n",
                "kuzhuxi": "你可以试着从溪（xi）中喝（drink）一口。\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-480);
	set("coor/z",10);
	setup();
}
init()
{
add_action("do_drink","drink");
}
int do_drink(string arg)
{
object me;
me=this_player();
if(!arg || arg != "xi") return 0;
if(me->query("water") >= me->max_water_capacity())
return notify_fail("你似乎并不渴。\n");
message_vision("$N弯下腰，在苦竹溪中喝了一大口苦水！\n",me);
me->add("water",50);
me->apply_condition("kuzhu",3+random(5));
return 1;
}
