// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "影壁");
        set("long", @LONG
山门进来，一青石影壁遮住了你的视线，唯一可见的是门上石龛中
的泥塑弥勒佛像，据说弥勒乃是指“慈”，弥勒佛乃佛灭后转生之后世
佛，笑容可掬，普渡着天下苍生。后面一座护法韦驮像，高大威猛，转
过影壁，便是少林名扬天下的四行碑林。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"shanmen",
  "north" : __DIR__"yonglu",
  "northeast" : __DIR__"bei3",
  "northwest" : __DIR__"bei2",
  "southeast" : __DIR__"ye1",
  "southwest" : __DIR__"ye2",
]));
        set("objects", ([
                __DIR__"obj/budd" : 1,
                __DIR__"obj/budd2" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",170);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
