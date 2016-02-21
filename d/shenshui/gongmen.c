// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白水宫门");
        set("long", @LONG
湖并没你想象中的那么深，你可以很清楚的看清湖底的一切，湖底长满
了各色的珊瑚和贝壳类生物，在这中间有一个美丽的侗体，身上竟然没有丝
毫衣饰，你不由的转移了你的视线。不远处有一个石洞，洞上用珍珠拼成四
个字＂水宫之门＂。
LONG
        );
   set("exits", ([ 
      "enter" : __DIR__"gongnei",
      "up" : __DIR__"lake",
   ]));
        set("coor/x",200);
        set("coor/y",12300);
        set("coor/z",0);
	setup();
}

void init()
{
   remove_call_out("do_air");
   call_out("do_air",6, this_object());

}

int do_air(object ob) 
{
   object *inv;
   int	i, da;

   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         tell_object(inv[i], "你只觉的胸口发闷，还是快点离开这儿吧。\n");
         da = 50000 / (inv[i]->query("max_force")+1);
         if(da>100) da = 50;
         if(da<10) da = 10;
         inv[i]->receive_damage("kee", da); 
      }
   }
   call_out("do_air", 5+random(10), this_object());
}


