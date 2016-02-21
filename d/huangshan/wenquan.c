// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "温泉");
        set("long", @LONG
黄山温泉古称汤泉，古人云“紫云峰下藏太阳，不施炉灶自成汤”，
更兼有医药功能名闻天下。因为曾多次涌出红色泉水，误为朱
砂，所以又称朱砂泉，多有山民在此建庐舍，设盆圩，游人沐
浴后，无不精神百倍。温泉西上便是慈光阁，北边远远可见观
瀑亭。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"ciguang", 
  "northup" : __DIR__"guanpu",
  "eastdown" : __DIR__"shanmen", 
]));
        set("objects", ([
        __DIR__"obj/tangquan" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-520);
	set("coor/y",-510);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
