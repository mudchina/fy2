// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白水殿");
        set("long", @LONG
一座高大的殿堂，在山腹中有如此杰作，实在让人叹为观止，可见构思人的
心机是多么的巧妙，工程是多麽的巨大。殿很大，中间却没有一根柱子，大殿的
顶上镶满了各色珍珠和珊瑚，正中间是一张雕花椅，四周静静的站了几个侍女。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"huoyan",
  "east" : __DIR__"shanfang",
  "west" : __DIR__"yaofang",
  "northeast" : __DIR__"woshi",
  "northwest" : __DIR__"qingong",
   ]));
   
   set("objects", ([
      __DIR__"npc/master" : 1,
      __DIR__"npc/girl": 3,
   ]) );
	set("coor/x",200);
	set("coor/y",12340);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
