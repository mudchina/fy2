// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "山道");
        set("long", @LONG
两边阴云相夹，东西难辨，黑雾迷空，漫漫黑雾，是鬼祟口中喷出
气，“一望高低无影踪，相看左右尽猖亡”说得便是这里了，你战战兢
兢的继续前行，心中忐忑不安。
LONG
        );
        set("exits", ([
		"northup" : __DIR__"beiyin",
		"south" : __DIR__"diyu",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-60);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
