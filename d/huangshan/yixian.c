// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "一线天");
        set("long", @LONG
天都下来，越磴道往文殊院去，经小心坡，蒲团松，便达沿垂直
裂系风化的“一线天”。这里十分狭长，高达三十余米的石壁紧紧夹
峙最宽处不过两米，窄处只有半米，仰望长空，蓝天一线。一线天西
北便是文殊院了。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"wenzhu",
  "eastup" : __DIR__"tiandu",
]));
        set("outdoors", "huangshan");
	set("coor/x",-570);
	set("coor/y",-490);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
