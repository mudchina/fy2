// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "玉屏楼");
        set("long", @LONG
这群高大的建筑，因为背靠玉屏峰，所以又称玉屏楼。在此可以
尽收玉屏，莲花两峰秀色。东观天都，从山顶直落山脚，近乎垂直，
西看莲花，恰似“突兀撑青穹”的盛开芙蓉。玉屏峰地处三大主峰中
心，集黄山奇景大成，“四海”烟云气吞山河，“三奇”美景叠现不
穷。又称“黄山绝胜处”。
LONG
        );
        set("exits", ([ 
  "northeast"  : __DIR__"yingke",
  "west" : __DIR__"lianhua",
  "southeast" : __DIR__"lianrui",
]));
        set("objects", ([
        __DIR__"npc/wang" : 1,
                        ]) );

        set("outdoors", "huangshan");
	set("coor/x",-580);
	set("coor/y",-520);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
