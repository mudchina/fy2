// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "醉石");
        set("long", @LONG
这是李白醉酒卧眠的醉石，石上一人形依稀可见，观其形状恰似
酒至鼾处，石侧有醉石二字，笔力遒劲，边上立有牌坊一座，历代文
人题字皆在此处。由醉石继续南行便是试剑石。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"shijian",
  "northup" : __DIR__"banshan",
  "northeast" : __DIR__"qingluan",
  "westdown" : __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone2" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-520);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
