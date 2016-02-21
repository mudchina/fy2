
inherit NPC;
void use_poison();

void create()
{
        set_name("毒蛤蟆", ({ "bad frog" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只剧毒的的癞蛤蟆\n");

        set("limbs", ({ "头部", "身体", "后腿", "前腿" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", random(999999));
	set("bellicosity", 300 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,
"你觉得身上一麻，身手已经不如刚才灵活了。\n");
		ob->receive_wound("kee",40);
                ob->apply_condition("unknown_poison", 
                (int)this_player()->query_condition("unknown_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

