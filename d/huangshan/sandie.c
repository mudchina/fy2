// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "三叠泉");
        set("long", @LONG
虎头岩西北的三叠岩是黄山二奇泉中的一个，因为高山下泄的泉
水流过三个陡坎形成三折而名。无论远观近看，傍着周围清幽的山林，
都是无以伦比的胜境。三叠泉不远是鸣弦泉。
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"zuishi",
  "west"	: __DIR__"mingxuan",
]));
        set("objects", ([
                __DIR__"npc/3que" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-520);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
