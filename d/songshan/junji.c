// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "峻极峰");
        set("long", @LONG
太室山滂礴如卧，“峻极于天”，有卧龙之称，峻极峰是太室
山的主峰，高耸入云，两面悬崖，下面则是险关要隘，顺此下去便
是大大有名的箕山，巢父，许由皆避官于此。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"laomu",
]));
        set("outdoors", "songshan");
	set("coor/x",-180);
	set("coor/y",140);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
