
inherit ROOM;

void create()
{
        set("short", "奈何桥");
        set("long", @LONG
掠过这座石像，笔直而行！ 只见前面竞是一道溪流。上架黑石小桥，
桥上赫然写著： ＂奈何桥＂ 三字！ 极目望去，＂奈何桥＂那边，弥布著一
片鬼气。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"river",
  "north" : __DIR__"stonelin",
  "south" : __DIR__"ghost",
]));
        set("objects", ([
        __DIR__"obj/mirror" : 1,
                        ]) );

        set("outdoors", "palace");

        set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

