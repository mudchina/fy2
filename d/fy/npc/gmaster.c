// teacher.c

inherit NPC;
#include <ansi.h>

int test_dart();
void create()
{
	set_name("查猛", ({ "meng", "cha meng" }) );
	set("title", HIY "金狮掌" NOR);
	set("gender", "男性" );
	set("age", 42);
	set("skill_public",1);
	set("inquiry",	([
		"mission" : (: test_dart :),
		"护镖" : (: test_dart :),
	]) );
	set("int", 30);
        create_family("少林俗家", 21, "弟子");
	set("long",
		"金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
		 凡是想向他求教的，只要为镖局出点力，他就肯教．\n"
		);
       set("chat_chance", 10);
        set("chat_msg", ({
                "查猛说道：这个月镖局生意不错！\n",
		"查猛说道：护镖（ｍｉｓｓｉｏｎ）的事．．．．\n",
        }) );
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	set_skill("literate", 30);
	set_skill("force", 30);
	set_skill("dodge",30);
	set_skill("parry",30);
	map_skill("unarmed", "changquan");
	set("combat_exp", 90000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int recognize_apprentice(object ob)
{
        if((time() - ob->query("marks/金狮") ) > 1800  ){
                say("查猛说道：你．．你好象很久没为镖局出过力了....\n");
                return 0;
        }

        return 1;
}
int test_dart()
{
	object me;
	
	me=this_player();
	if (random(100)>50  || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say 我们镖局现在没有你要护的镖。");
		return 1;
	}
	
	command("say 现在南宫钱庄有一笔镖银需要运到沉香镇，你可愿意协助我们？(accept mission)");
	return 1;
}
int do_accept(string arg)
{    
	object ob,cart,biaotou;
	object me,*team;
	int i;	
	if (arg != "mission") return 0;
	me=this_player();
	team=me->query_team();
	if (sizeof(team)==0) team=({me});
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("combat_exp")<10000)
		{
			command("say 护镖路途危险，我看这位"+RANK_D->query_respect(team[i])+"似乎不宜！");
			return 1;
		}
		if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
		{
			command("say 护镖是危险的事，我看"+RANK_D->query_respect(team[i])+"没有赔偿能力。");
			return 1;
		}
	}
	if (random(100)>50 || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say 你来晚了，已经有人接下这支镖了。");
		return 1;
	}
	
	if (sizeof(team) != 0 && (team[0]!=me)) 
			return notify_fail("say 只有队伍首领才能提出接镖。\n");
	set("marks/gived",1);
	command("say 好吧。跟着李镖头走吧。");
	command("say 丢镖可是要赔双份的，一路小心。");
	
	say("一队镖车从内院驶出。\n");
	
	ob=new(__DIR__"obj/cart");
	ob->move(environment());
	cart=ob;
	
	biaotou=new(__DIR__"biaotou");
	biaotou->move(environment());
	biaotou->get_quest("/obj/dartway1");
	biaotou->set_cart(cart);
	biaotou->set_protector(team);
	
	
	ob=new(SILVER_OB);
	ob->set_amount(10000+random(10000));
	ob->set("name","镖银");
	ob->move(cart);
	
	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
	
	ob=new(__DIR__"biaoshi1");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
	
	ob=new(__DIR__"biaoshi1");
	ob->move(environment());
	ob->set_leader(biaotou);
	ob->set_temp("protecting",cart);
    
    for(i=0;i<sizeof(team);i++)
       	team[i]->set_temp("protecting",cart);
    	
    me->set_temp("protecting",cart);
    me->set_leader(biaotou);
    biaotou->go_now();
    return 1;	
}
void reset()
{
delete("marks/gived");
}
