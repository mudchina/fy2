// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
转了几个弯，入洞以深，面前是伸手不见五指，周围不时传来小动物
掠过的沙沙声，令人生畏，你想回头却以不知来时的道路。在这里你也分
不清东西南北，只好揣策着方向，壮着胆子摸索着往前走。
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"midao6",
      "east" : __DIR__"midao2",
   ]));
	set("coor/x",90);
	set("coor/y",12060);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
