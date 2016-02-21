inherit ROOM;
void create()
{
        set("short", "南天门");
        set("long", @LONG
这是到达天街所必经的南天门，门前一座摩天阁，巍峨庄重，气势
不凡，门上石刻，极尽巧力，鬼斧神工，四根红木大柱，虽饱经风雨，
却颜色不改，临风远眺，不由让人想起“天门一长啸，万里清风来”
千古名句。由此向上，便到了泰山的后山，后石邬，东面是泰山山神
碧霞元君接收人间供奉之所在，而西面便是玩赏明月的观月峰。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"yueguan",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
]));

        set("item_desc", ([
                "石刻": "		
		阶		门
		崇		辟
		万		九
		级		霄
		俯		仰
		临		步
		千		三
		嶂		天
		奇		胜
		观		迹
		 。		 ，			
"        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",-480);
	set("coor/y",-310);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}
