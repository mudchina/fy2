// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鲫鱼背");
        set("long", @LONG
过了探海松，便是鲫鱼背了，一段长约十余丈，宽仅半丈，两侧
凌空，下临深渊的石质刃脊，前人所谓“天都欲上路难通”指的就是
这一段，直到二仙另开一路，方才可以轻松登天都。过了鲫鱼背，再
经过前面的“仙人把洞门”，便是天都峰了。
LONG
        );
        set("exits", ([ 
  "northup"  : __DIR__"tiandu",
  "south" : __DIR__"guanyin",
  "west" : __DIR__"erxian",

]));
        set("outdoors", "huangshan");
	set("coor/x",-560);
	set("coor/y",-500);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
