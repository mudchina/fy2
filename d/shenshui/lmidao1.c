// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
透过昏暗的光线，你终于看清了周围的环境，山洞并没有你想象的那么
大，只是里面的道路十分曲折，在黑暗中给人以错觉。墙壁上还有铜做的壁
灯，不远处有一堆白骨，不知是什么人最终没能逃出秘道，而被困死在此，
不由心里暗自为自己庆幸，但也感到了前途的坚难。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"lmidao2",
]));
        set("coor/x",90);
        set("coor/y",12070);
        set("coor/z",0);
	setup();
        replace_program(ROOM);
}
