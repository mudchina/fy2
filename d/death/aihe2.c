// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "奈何桥");
        set("long", @LONG
此桥桥边便是焦都驿驿，桥和驿站一样，通跨阴阳，左段青天白日，
右段却隐没在黑雾之中，桥下的泾河形式险恶，奔流不息，浪声不
绝，在黑水之中隐约可见人影幢幢，古来到此因惊吓落水者不计其
数。再往前便是鬼门关了。
LONG
        );
        set("exits", ([
                "west" : __DIR__"gate",
		"east" : __DIR__"ghostinn",
        ]) );
        set("objects", ([
                __DIR__"npc/niutou":1,
		__DIR__"npc/mamian":1,
		__DIR__"npc/ghost" : 5
        ]) );
	set("coor/x",-1010);
	set("coor/y",0);
	set("coor/z",-100);
	setup();
        replace_program(ROOM);
}
 
