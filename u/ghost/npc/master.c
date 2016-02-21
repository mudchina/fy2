
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("�ϵ�����", ({ "master lao dao", "lao dao"}) );
	set("gender", "����" );
	set("age", 45);
	set("int", 30);
	set("str", 30);
	set("per", 30);
        set("apprentice_available", 50);
        create_family("����ɽׯ", 1, "ׯ��");
        set("class", "ghost");
	set("long", "���������ۣ�ͷ�����ң�������������ʵĹ��ꡣ\n" );
        set("force_factor", 200);
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
        set("chat_chance", 1);
        set("combat_exp", 9999999);
        set("score", 90000);
        set("skill_public", 1);
        set_skill("foreknowledge", 120);
        set_skill("changelaw", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("move", 150);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("three-sword", 100);
	set_skill("taiji", 100);

	map_skill("unarmed", "taiji");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");

	setup();
        carry_object(__DIR__"obj/cloth3")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/swordd")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ��ׯ�������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
	if((int)ob->query_temp("marks/���Ʒ�")) {
        	command("stare " + ob->query("id"));
        	command("say �㲻��������ϸ�İɣ�\n");
		return;
        }
        else  if((int)ob->query_temp("marks/����ɽׯ")) {
		say("\n");
        	command("say �ã�����䵱����ɽ���Ǳ����������ң��ٽ���ʯ�϶�ɱ�ˣ����ð�ʦ����Ҳ������һ���书��\n");
		ob->set("marks/�����Ǳ���", 1);
	}
        else {

                command("say ���պ���д�ɣ�");
                command("smile");
                command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ghost");
        add("apprentice_availavble", -1);
}

int recognize_apprentice(object ob)
{
        if( ob->query("marks/�ϵ�����") ||(string) ob->query("class") == "ghost")
			return 1;
        return 0;
}

int accept_object(object who, object ob)
{
	if((string)ob->name() != "���ǽ�") return 0;
	if(!who->query("marks/�����Ǳ���")) return 0;
	if(ob->query("real") && (object)ob->query_temp("marks/owner") == who &&
	ob->query_temp("killed_master_shi")) {
		who->delete("marks/�����Ǳ���");
		command("spank " + who->query("id"));
                command("say ����Ҫ�书�ؼ�����������ѧ�䣿(accept book/teach?)");
		who->set_temp("marks/�õ����Ǳ���", 1);
		add_action("do_accept", "accept");
	}
	else {
		say("�ϵ����ӽӹ����ǽ�����ϸ�ؿ��˿���\n");
		command("sigh");
                command("say ��һ�����Ǽٵģ�");
	}
	return 1;
}

int do_accept(string arg)
{
	object		me, book;

	if(!arg || (arg != "book" && arg != "teach")) 
		return notify_fail("ʲ�᣿\n");
	me = this_player();
	if(!me->query_temp("marks/�õ����Ǳ���"))
		return notify_fail("ʲ�᣿\n");
	me->set_temp("marks/�õ����Ǳ���", 0);
	if(arg == "book") {
		book = new(__DIR__"obj/book");
		book->move(this_object());
		command("give book to " + me->query("id"));
	}
	else 
		command("say �ӽ��쿪ʼ�������ͬ��ѧ���ˡ�");
		me->set("marks/�ϵ�����", 1);
	return 1;
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","����ɽׯ����");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","����ɽׯ���");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","����ɽׯС�ܼ�");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","����ɽׯ�ܼ�");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","����ɽׯ��ܼ�");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","����ɽׯ�ܹ�");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","����ɽׯ���ܹ�");
                return ;
        } else
                student->set("title","����ɽׯ��ׯ��");
                return ;

}
