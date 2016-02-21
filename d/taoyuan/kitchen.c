inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
厨房里的光线很暗，乍一进来除了灶台下跳动着的暗红的火苗，几乎什么也看不
见。安儿常常在这里给小狗旦做他最喜欢吃的葱油饼，整个屋里飘动着浓郁的葱香和
淡淡的炊烟。收拾得整整齐齐的灶台上还留着几片葱花，阴影中仿佛有一些炊具。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"cyard",
	]) );

	set("objects", ([
		__DIR__"obj/oven" : 1,
		__DIR__"obj/pot" : 1,
	]) );

        set("coor/x",220);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
        }
        con = present("oven", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/scallion");
                item->move(con);
                item = new(__DIR__"obj/caidao");
                item->move(con);
                item = new(__DIR__"obj/lighter");
                item->move(con);
        }
}

