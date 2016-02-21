// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "星星小楼");
        set("long", @LONG
进得楼来，只见四周陈设皆为黑色，除了南边有一扇窗，微微有些亮
色外，就只有屋中桌子上的油灯发出微弱的光，靠窗边有一床榻，上面铺
着简单的被褥。
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"ruanhong",
   ]));
   set("objects", ([
      __DIR__"npc/lingyu" : 1,
   ]) );
  
   set("item_desc", ([
      "window": "临窗下看，只见危崖百尺，黑色的海浪拍打着岸边的乱石。 \n",
      "窗": "临窗下看，只见危崖百尺，黑色的海浪拍打着岸边的乱石。 \n",
   ]) );
   set("coor/x",200);
	set("coor/y",12310);
	set("coor/z",-10);
	setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int ml, cl;

   me = this_player();
   cl = (int)me->query_cor();
   ml = (int)me->query_skill("move");
   if(!arg || (arg != "window" && arg != "窗")) return 0;
   if (cl >= 20) {
      message_vision("$N跳到窗口，纵身向窗外跳去。\n\n", me);
      if (ml >= 100)
         tell_object(me, "你只觉的身子向下坠落，慌乱中你伸出右脚踏向一颗从岩缝中长出的小
树，咔喳一声小树断了，你下降的势力也缓了缓，扑通一声你落入了水中。。\n\n");
      else {
         tell_object(me, "你只觉的身子向下坠落...坠落....似乎坠向无底的深渊，终于扑通一
声你落入了水中。\n");
         me->unconcious();
      }
      room = find_object(__DIR__"yadi");
      if(!objectp(room)) room = load_object(__DIR__"yadi");
      me->move(room);
      message("vision", "你觉得有一团黑忽忽的事物从上面落下，扑通一声落入你身旁的水中。\n", environment(me), me);
      return 1;
   }
   else {
      tell_object(me, "你跳到窗口，向外看了看又跳了下来。\n\n", me);
      message("vision", me->name()+"跳到窗口，向外看了看，脸色煞白地又跳了下来。\n\n", environment(me), me);
      return 1;
   }
} 
