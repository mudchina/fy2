inherit ROOM;
void create()
{
        set("short", "桃林");
        set("long", @LONG
这是一片茂密的桃树林，林中芳草鲜美，落英缤纷，一层淡淡的薄雾，混
合着青青的草香，弥漫在空气之中。偶尔的一两声鸟鸣，愈发地显出幽静来。
这里的小路已被落花铺满，早已辨不出痕迹来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin2",
  "west" : __DIR__"taolin",
]));

	set("item_desc", ([
	    "桃树": "粉云彩霞般的桃花，热热闹闹地开满了枝头。\n",
	    "peach tree": "粉云彩霞般的桃花，热热闹闹地开满了枝头。\n",
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",120);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init() 
{
   add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   object me, zhi;

   me = this_player(); 
   if(!arg || arg != "taozhi" && arg != "桃枝") return 0;	
   if(me->query_temp("marks/taozhi")){
      tell_object(me, "\n再摘桃树就秃了! \n");	
      return 1;
   }	
   zhi = new(__DIR__"obj/taozhi");
   zhi->move(me);
   me->set_temp("marks/taozhi", 1);
   message_vision("\n$N伸手摘了一枝桃花下来。\n", me);
	
   return 1;	
}

