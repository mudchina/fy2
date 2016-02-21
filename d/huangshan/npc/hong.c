//TIE@FY3`
inherit NPC;
void create()
{
        set_name("李红樱", ({ "hongying" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个红袍老人，须发都已经白了，腰杆却还是挺的笔直，眼睛发出的光芒远比
剑锋还逼人。\n");
        set("combat_exp", 7000000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 90);
        set("chat_chance", 10);
        set("chat_msg", ({
"李红樱道：红樱绿柳，剑中之精。\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
	set_skill("throwing",10);
	set_skill("feidao",10);
	map_skill("throwing","feidao");
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
	carry_object(__DIR__"obj/7inch")->wield();
}
int heal_up()
{
	if(!query_temp("right_hand")) carry_object(__DIR__"obj/7inch")->wield();
	return ::heal_up() + 1;

}
