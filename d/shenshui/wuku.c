// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "武库");
        set("long", @LONG
白水宫内皆是女子，武功独特，所用武器也特地定做，专为女子打造，使
将开来，轻灵无比，姿态曼妙，房内陈设着几排兵器架，上面刀，枪，剑，指
环，应有尽有，最怪在于居然还有一盒绣花针，不知道有何用处。。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yaofang",
]));
	set("coor/x",190);
	set("coor/y",12345);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
