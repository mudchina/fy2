
inherit NPC;
void use_poison();

void create()
{
        set_name("��β��", ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 4);
	set("yes_carry", 1);
        set("long", "һ���綾����β�ߡ�\n");

        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 50);
        set("combat_exp", random(99999));
	set("bellicosity", 300 );
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
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
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
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

