#include <ansi.h>
inherit NPC;
int wieldblade();
void create()
{
        set_name("茅大先生", ({ "mr da" }) );
        set("gender", "男性");
	set("age",35);
        set("combat_exp", 1000000);
        set("long",
		"一个白发苍苍的老人而已，没有什么特别的地方。\n"
	);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",30);
	set_skill("move",100);
        set_skill("parry", 250);
	set_skill("sword",250);
	set_skill("dodge",1);
	set_skill("feixian-steps",250);
	map_skill("dodge","feixian-steps");
	set_skill("feixian-sword",100);
	map_skill("sword","feixian-sword");
	map_skill("parry","feixian-sword");
        set("chat_chance", 15);
        set("chat_msg", ({
	(: random_move :),
       (: random_move :),
        (: random_move :),
     (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword");
}
int wieldblade()
{
command("wield sword");
perform_action("dodge.tianwaifeixian");
command("unwield sword");
return 1;
}
