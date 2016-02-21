
inherit ROOM;

void create()
{
	object box, matter;
        set("short", "八角街");
        set("long", @LONG
城市赤如皮革，有光滑美丽的一面，也有粗糙丑陋的一面。这段八角街
上垃圾粪便狼藉。成群结队的年老乞丐，穿着破旧褴褛的衣服，剃光头打赤
足，匍匐在尘土中，等待着行人香客的施舍。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"octo13",
  "east" : __DIR__"octo15",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"obj/trash" : 1,
		__DIR__"obj/junkblade" : 2,
		__DIR__"obj/junkstaff" : 1,
		"/obj/money/silver" : 1,
		__DIR__"npc/crazy_dog" : 2,
		__DIR__"npc/beggar" : 3,
		__DIR__"obj/junksword" : 1,
                __DIR__"obj/fake-tooth" : 1,
        ]) );
        set("coor/x",-1210);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        box = present("trash", this_object());
        matter = present("blade", this_object());
	matter->move(box);
        matter = present("staff", this_object());
        matter->move(box);
        matter = present("blade", this_object());
        matter->move(box);
        matter = present("silver", this_object());
        matter->move(box);
        matter = present("sword", this_object());
        matter->move(box);
        matter = present("tooth", this_object());
        matter->move(box);


}

