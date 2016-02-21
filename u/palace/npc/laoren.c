

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("驼背老人", ({ "laoren" }) );
        set("gender", "男性" );
        set("age", 68);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
        set("max_atman", 300);
        set("atman", 300);
        set("max_mana", 300);
        set("mana", 300);

        set("max_force", 100);
        set("force", 50);
        set("force_factor", 5);
        set("attitude", "aggrensive");

        set("long","这是一位久经风霜的驼背老人。\n");
	set("bellicosity",1000000);
        set("combat_exp", 2000);
        set("score", -50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 10);
        set_skill("zuixian-steps", 10);
	set_skill("thunderwhip",10);
	set_skill("iceheart",10);
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");


	setup();
	carry_object("/obj/cloth")->wear();
        add_money( "silver" , 50);
}

void init()
{
        object me;
        me = this_player();
        if( interactive(me))
                if( me->query("class") != "yishi")
                kill_ob(me);

}

