
inherit ROOM;

void create()
{
	set("short", "山坳");
	set("long", @LONG
这里是一处山坳，往南就是风云城，一条蜿蜒的小径往北展开．
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : "/u/taoguan/road1",
  "eastdown" : "/d/laowu/road1",
]));
	set("outdoors", "taoguan");
	set("coor/x",-10);
	set("coor/y",2000);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
