// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "嵩阳书院");
        set("long", @LONG
在太室山南麓的“山水环抱之区，无地不染梵尘”之所，有三
教合一的建筑掩映在茂林修竹的万绿从中，他就是我国四大书院之
嵩阳书院，这里最早是佛寺，后为道观，五代后改为书院，宋代理
学家程颐兄弟曾在此讲理学，院内的将军柏，“大唐嵩阳观纪圣德
感应之颂”碑都是天下闻名的瑰宝。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shaoshi", 
  "east" : __DIR__"chongfu",
  "southeast" : __DIR__"zhongyue",
  "northeast" : __DIR__"shita",
]));
        set("objects", ([
                __DIR__"npc/teacher" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-190);
	set("coor/y",120);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
