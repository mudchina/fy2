// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("李神童", ({ "li", "tong" }) );
        set("long","一个带着绿高帽的李神童\n");
	set("title", HIG "绿高帽" NOR);
        set("attitude", "heroism");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("age",55);
        set("combat_exp", 100000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/bigcloth")->wear();
}
