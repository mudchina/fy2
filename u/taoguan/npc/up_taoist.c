// tao_2.c

inherit NPC;

void create()
{
        set_name("护山使者", ({ "taoist guard", "guard" }) );
        set("gender", "男性");
        set("age", 32);
        set("long",
"护山使者是三清宫的护法，着一身黑色的道袍\n"
);
        set("combat_exp", 50000);
        set("score", 200);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("pursuer", 1);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("三清宫", 7, "弟子");

        set_skill("literate", 50);
        set_skill("magic", 30);
        set_skill("move", 30);
        set_skill("force", 30);
        set_skill("spells", 60);
        set_skill("unarmed", 50);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 40);
        set_skill("gouyee", 60);

        map_skill("force", "gouyee");

        set_skill("taoism", 70);
        set_skill("necromancy", 60);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("silver", 30);
        carry_object("/u/taoguan/obj/sword1")->wield();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="三清宫" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 三清宫不和别派的人过招。");
        return 0;
}
 
