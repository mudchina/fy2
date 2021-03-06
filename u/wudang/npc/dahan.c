inherit NPC;

void create()
{
        set_name("大汉", ({ "man" }) );
        set("gender", "男性");
        set("age", 32);
        set("long",
		"一位彪型大汉呆呆地坐在这里，望着飞来飞去的麻雀。\n"
	);
	set_skill("sword", 50);
	set_skill("three-sword", 50);
	set_skill("dodge", 50);
	set_skill("move", 50);
	set_skill("five-steps", 50);

	map_skill("sword", "three-sword");
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");

        setup();
        add_money("silver", 1);
	carry_object(__DIR__"obj/shuzhi")->wield();
}

int accept_object(object who, object ob)
{
	object		shu;
	if( ob->name() == "铁剑") {
		say("大汉看了你一眼，说道：谢谢。\n");
		if( shu = present("shu zhi", this_object()) ) {
			say("大汉接过铁剑，顺手把树枝丢在地上。\n");
			shu->move(environment(this_object()));
		}
		return 1;
	}
	return 0;
} 

