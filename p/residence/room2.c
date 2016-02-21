inherit ROOM;
void create ()
{
  set ("short", "之字形小路");
  set ("long", @LONG
延山间小路越丘陵，过村庄，穿田野，约二，三里后，隐隐听见水流的轰鸣，
续前进，在一片坡地的前端，呈现倒丫字形深箐，那巨大的轰鸣声，就是从这箐
沟里传出的。延坡上的之字形小路攀藤扶石蜿蜒而下，约五百丈，至箐底，一片
雄奇壮观的瀑布，便呈现在你的眼前。
LONG);
        set("exits", ([ 
  "south" : "/d/qianfo/road1",
  "north" : __DIR__"room3",
]));
  	set("coor/x",10);
	set("coor/y",2010);
	set("coor/z",10);
	setup();
  replace_program(ROOM);

}

