// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"算","余","时","格","已","的","争","那","所","落","们","史"});
        set_name("一"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(20)+ 32);
	create_family("少林寺", 18, "弟子");
        set("long", "这是少林寺的和尚\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(300000)+300000);
        set("attitude", "friendly");
        set_skill("hammer", 70+random(100));
	set_skill("liuxing-hammer",random(100)+150);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：是时候了吧？\n",
        }) );
	set_skill("move",80);
	set_skill("force",200);
	set_skill("parry",300);
	map_skill("parry","liuxing-hammer");
	map_skill("hammer", "liuxing-hammer");
        set("chat_chance_combat", 10);
	set("force",500);
        set("chat_msg_combat", ({
		name()+"笑道：在少林寺撒野？\n",
                (: perform_action, "hammer.fanbei" :),
        }) );
        set("max_force",500);
	set("force_factor",15);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/hammer")->wield();
}
void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
string what;
if(!arg) return 0;
if(sscanf(arg,"%s",what) !=1) return 0;
if(what== "all" || what== "mugui" )
{
message_vision("$N对$n大吼一声：大胆！竟敢打少林寺东西的主意！\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}
