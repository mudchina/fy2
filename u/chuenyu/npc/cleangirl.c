// worker.c

inherit NPC;

void create()
{
        set_name("ŮӶ��", ({ "cleaning maid", "maid" }) );
        set("gender", "Ů��" );
        set("age", 43);
        set("long", "������˪��ŮӶ��\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set_skill("parry", 25);
	set_skill("dodge", 35);
	set_skill("throwing", 20);

        set("inquiry", ([
		"С��" : "��Ҫ������ȥ�ҡ�", 
		"����" : "��Ҫ������ȥ�ҡ�",
		"���ڻ�̫" : "��Ҫ������ȥ�ҡ�",
		"����" :"��Ҫ������ȥ�ҡ�",
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/feather")->wield();
}
