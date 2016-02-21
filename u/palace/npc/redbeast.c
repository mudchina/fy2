// mind_beast.c

inherit NPC;

void create()
{
	set_name("怪兽", ({ "heaven lion", "lion" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这怪兽通体俱是赤红颜色，生得似狮非狮，似马非马。\n");
	
	set("str", 48);
	set("cor", 52);
	set("cps", 22);

	set("max_kee", 600);
	set("max_gin", 600);
	set("max_sen", 900);
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

		set("combat_exp", 20000);
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 140);
	set_temp("apply/damage", 200);

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( interactive(me))
                if( me->query("class") )
                if( me->query("class") != "yishi") 
		kill_ob(me);

}
