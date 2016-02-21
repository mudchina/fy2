// Room: /d/wiz/courthouse.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
	set("short", "¼àÓü");
	set("long", @LONG
[31m
·çÔÆÎ¨Ò»µÄÒ»¸ö¼àÓü£¬ÄÜµ½ÕâÀïÀ´µÄÈËÒ»¶¨¶¼ÊÇÁîÈËÍ·Í´µÄ½ÇÉ«¡£
µ«ÊÇÒ»µ½ÕâÀï£¬±ðÈËµÄÍ·¾Í²»Í´ÁË£¬ÄãµÄÍ·Ó¦¸Ã¿ªÊ¼Í´ÁË°É£®£®£®
[37m
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jobroom"
]));

	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",10);
	setup();
}
void init()
{
        if(!wizardp(this_player()))
	{
	"/cmds/std/look"->look_room(this_player(),this_object());
	this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
	add_action("do_quit","quit");
	}
}	

int do_nothing()
{
write("¼àÓüµÄÉú»îÕæ¿à°¡£®£®£®£®£¡\n");
return 1;
}

int do_quit()
{
"/cmds/usr/quit"->main(this_player(),"");
return 1;
}
