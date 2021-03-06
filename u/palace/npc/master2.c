
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("蓝天锤", ({ "master lan", "lan","master" }) );
	set("gender", "男性" );
        set("title",HIB "蓝大先生" NOR);
	set("age", 45);
	set("int", 30);
	set("str",700);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("天锤山庄", 1, "庄主");
	set("long",
		"蓝天锤的一柄大锤用的出神入化．．．
每年都和帝王谷主绝顶一战，致今胜负不分． 
蓝天锤的脾气爆如烈火，经常无缘无故的将弟子打成死伤或逐出墙门．\n"
		);
        set("force_factor", 60);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("skill_public",1);
        set("chat_chance", 1);
        set("chat_msg", ({
"蓝天锤笑骂道：这个箫老儿，又和他不分胜负．\n",
        }) );
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("hammer", 150);
        set_skill("force", 200);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("pangu-hammer", 150);
	set_skill("pofeng-strike", 120);
	set_skill("putiforce", 50);
	set_skill("nodust-steps", 100);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
	set_skill("magic",100);
	set_skill("qiankunwuxing",100);
	map_skill("magic","qiankunwuxing");
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.kaitianpidi" :),
		(: cast_spell, "shrink" :),
        }) );
	setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/jumbohammer")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 4);
	set("try", random(10)+1);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了四个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
	if((int)ob->query_temp("xiao_failed") )
        {
        command("laugh");
	if( !random(10) && !ob->query("lan_failed")){
        command("say 箫老儿不收你？好！老夫也不收你，但我这身功夫你随便学．\n");
        ob->set("marks/lan",1);
	}
	else
	{
        command("say 箫老儿不收你？你真是朽木不可雕也．．．．\n");
	ob->set("lan_failed",1);
	}
	return;
        }
        else {

                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lishi");
        add("apprentice_availavble", -1);
}

int recognize_apprentice(object ob)
{
        if( (string) ob->query("class") == "lishi")
		return 1;
        if( ob->query("marks/lan") )
	{
		if( !random(10)) {
		command("say 老夫今天心情不好！你还是走吧．．．");
		ob->set("marks/lan",0);
		return 0;
		}
		return 1;
	}
        return 0;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","天锤派弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","天锤派小侠");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","天锤派少侠");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","天锤派大侠");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","天锤派奇侠");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","天锤派长老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","天锤派元老");
                return ;
        } else
                student->set("title","天锤派副掌门");
                return ;
}

