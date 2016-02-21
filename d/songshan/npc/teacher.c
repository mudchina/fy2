// teacher.c

inherit NPC;

void create()
{
	set_name("梦焕", ({ "meng huan", "huan" }) );
        create_family("少林寺", 20, "弟子");
	set("title", "笔下生花");
        set("vendetta_mark","shaolin");
	set("int",1);
	set("gender", "男性" );
	set("age", 57);
        set("chat_chance", 10);
        set("chat_msg", ({
                "梦焕道：＂大江东去，浪淘尽千古风流人物！＂\n",
        }) );
	set("long",
		"梦焕是个风趣的和尚，他年轻时曾经中过秀才，但是\n"
		"因为后来仕途坎坷，出家为僧，如果你愿学读书和佛法\n"
		"梦焕总是会教的．\n");
	set("attitude", "peaceful");
	set_skill("literate", 140);
	set_skill("buddhism",100);
	setup();
}

int recognize_apprentice(object ob)
{
	return 1;
}
