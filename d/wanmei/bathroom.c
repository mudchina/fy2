// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小茅厕");
        set("long", @LONG
茅厕通风良好，干净清爽。几个带盖的白玉小马桶整齐地排列在墙边。
每个马桶上还有一个挂钩，好象是可以挂在扁担上的。墙上挂着一个马鬃
木刷还正在滴着水。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"backyard",
]));
        set("objects", ([
	__DIR__"obj/matong":2,
	__DIR__"obj/brush" : 1,
                        ]) );

        set("coor/x",190);
	set("coor/y",-410);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
