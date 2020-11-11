// Room: /d/oldpine/cliffside.c

inherit ROOM;

void create()
{
        set("short", "林间....不....悬崖边");
        set("long", @LONG
你现在正站在一个松树林间的小空地上，你的北边、东边、南边都
是茂密的松树，唯独西边是个悬崖，当你探头一看，立刻不由自主地倒
抽一口凉气，在这里可得千万小心，一不小心跌了下去肯定是粉身碎骨。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/oldpine/pine2",
  "north" : "/d/oldpine/pine1",
  "east" : "/d/oldpine/pine1",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "cliff" : "你定下心神一看，其实这个悬崖没有想像中那麽恐怖，也许还
可以从这里爬下山涧，只是这世界上大概没有这种白痴愿意干
这种傻事吧。
",
]));
        set("outdoors", "oldpine");

        set("coor/x",-260);
	set("coor/y",-360);
	set("coor/z",85);
	setup();
        replace_program(ROOM);
}
