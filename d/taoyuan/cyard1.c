inherit ROOM;
void create()
{
        set("short", "小院");
        set("long", @LONG
小小的院落，一方葡萄架遮住了半边，淡黄的阳光斜斜的照在上面，把嫩绿
的叶脉变得透明。院的中间是一口水井，咿咿呀呀的摇辘声犹如在耳；篱笆的另
一角堆着一些清扫用具。
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"cyard",
	]) );


        set("outdoors","taoyuan");
        set("coor/x",200);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_look", "look");
        add_action("do_approach", "approach");
}

int do_look(string arg)
{
	object me;
	object room;
	me = this_player();
	if(!arg || arg != "井" && arg != "well" ) return 0;
	switch ( random (2)) {
		case 0:
tell_object(me,"水井边上湿漉漉的，好象才有人打过水，还是不要靠（ａｐｐｒｏａｃｈ）的太近。\n"); 
		break;
		case 1:
message_vision("$N探头向水井里望去。 \n", me); 
tell_object(me,"黑不隆咚的水井深不见底。 \n");
                break;
	}


        return 1;
}
int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "井" && arg != "well" ) return 0;
	switch ( random (3)) {
		case 0:
message_vision("$N走近水井探头向里望去。 \n", me); 
tell_object(me,"水井深不见底，不过你似乎可以听到底下流水的声音。 \n");
                break;
		case 1:
message_vision("$N走近水井探头向里望去。哎呀！一不小心掉了进去！\n", me); 
message_vision("$N的头撞在井壁上，一下子昏了过去！\n", me);
		me->unconcious();
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
		case 2:
message_vision("$N走近水井探头向里望去。哎呀！一不小心掉了进去！\n", me); 
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
	}

        return 1;
}
