inherit ROOM;
void create()
{
        set("short", "安然居");
        set("long", @LONG
这里就是小狗娃和安儿的新居了。原木为篱，青藤作绳，粗粗围就一方院落。
柴门不甚坚固，主人也似乎并不在乎。几枝青青蔓萝藤，缠绕而上，微风中柔柔摆
动。门两旁高书：花径不曾缘客扫  柴门今始为君开  正中横书：安然居。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"road3",
  	"north" : __DIR__"cyard",
	]) );

	set("objects", ([
		__DIR__"npc/dog" : 1,
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
