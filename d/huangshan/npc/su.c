// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��ݦ", ({ "bai hong", "bai"}) );
        set("gender", "Ů��" );
        set("age",22);
        set("long", "һ���彣�Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 6, "����");
        set("combat_exp", random(500000)+500000);
        set("attitude", "friendly");
        set_skill("sword", 60+random(10));
	set_skill("siqi-sword",random(50)+30);
	set_skill("move",60);
	set_skill("force",20);
	map_skill("sword", "siqi-sword");
	set_skill("dodge",100);
	set_skill("liuquan-steps",40+random(40));
	map_skill("dodge","liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
name()+"�����Ͼ��ǻ�ɽ�ɵĽ��أ���������߶���\n",
        }) );
        set("chat_chance_combat", 30);
	set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );
        set("max_force",500);
	set("force_factor",2);
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}
