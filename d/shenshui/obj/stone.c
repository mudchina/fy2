inherit ITEM;

void create()
{
   set_name("大白石", ({ "stone" , "white stone", "石头" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "块");
      set("long", "一块表面十分平滑的白石，上面平铺了一张宣纸，上面写了些字：

      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳□，随春且看归何处。

      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送□□不语，黄昏却下潇潇雨。

其中似乎少了三个字，纸边摆着现成的笔墨。
\n");
   }
}

void init()
{
   add_action("do_write", "write");
}

int do_write(string arg)
{
   object obj, me, room;
   
   obj = this_object();
   me = this_player();
   if(obj->query_temp("marks/finished"))
      return 0;
   else {
      if(!arg || (arg != "xu chun chun" && arg != "絮春春")) {
         return 0;
      }
      tell_object(me, "你略一沉吟，提笔在空格上填了几个字，又把笔放了下去。\n");
      message("vision", me->name()+"略一沉吟，从白石上提笔写了几个字，又把笔放了回去。\n",environment(me), me);
      set("long", "一块表面十分平滑的白石，上面平铺了一张宣纸，上面写了些字：

      楼外垂杨千万缕，
      欲系青春，少住春还去。
      犹自风前飘柳絮，随春且看归何处。

      绿满山川闻杜宇。
      便做无情，莫也愁人苦。
      把酒送春春不语，黄昏却下潇潇雨。

纸边摆这现成的笔墨。
\n");
      obj->set_temp("marks/finished",1);
      me->set_temp("marks/guest", 1);
      tell_object(me, "你只觉得后脑勺似乎被什么东西叮了一下。\n");
      me->unconcious();
      message("vision", "你只觉得眼前一花，似有一个人影掠过，"+ me->name() +"以失去了踪影。\n", environment(me),me);
      room = find_object("/d/shenshui/woshi2");
      if(!objectp(room)) room=load_object("/d/shenshui/woshi2");
      me->move(room);
   }
   return 1;
}

