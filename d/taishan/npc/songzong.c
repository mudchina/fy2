#include <ansi.h>
inherit NPC;
void create()
{
        set_name("宋中", ({ "songzong" }) );
        set("gender", "男性");
        set("combat_exp", 100000);
        set("title", HIR "一剑送终" NOR);
        set("long",
		"宋中－－一剑送终，大家都认为他拔剑的动作已经比得上荆无命。\n"
	);
        set_skill("move", 50);
        set_skill("dodge", 50);
	set_skill("sword",50);
	set_skill("sharen-sword",20);
	map_skill("sword","sharen-sword");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}
