// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
秘道在这里突然变宽变大，形成了一个巨大的石室，室内长满了各种千奇
百怪的钟乳石，在光线的照耀下闪烁着迷人的色彩，如果没有光线你很难从这
里绕出去。石室一角有一个巨大的白石，象一张天然的书桌。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lmidao1",
  "north" : __DIR__"lmidao3",
  "northeast" : __DIR__"lmidao4",
]));

   set("objects", ([
      __DIR__"obj/stone": 1,
   ]) );
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
	setup();
        replace_program(ROOM);
}
