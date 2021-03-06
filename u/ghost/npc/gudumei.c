#include <ansi.h>
inherit NPC;

void create()
{
        set_name("孤独美", ({ "gu du mei", "gu du" }) );
        set("nickname", "六亲不认");
        set("title", "独行大盗");
        set("gender", "男性");
        set("age", 56);
        set("no_arrest",1);
        set("long",
		"一个两鬓斑白的人，衰老、憔悴、疲倦、悲伤而恐惧。\n"
	);
        setup();
	carry_object(__DIR__"obj/sword")->wield();
}

void init()
{
        object          me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
		add_action("do_agree", "agree");
		add_action("do_go", "go");
        }
}

void greeting(object ob)
{
	object		leader, room;
	string		*dirc = ({ "东", "南", "西", "北" });
	string		*dirg = ({ "east", "south", "west", "north" });
	string		*dire = ({ "exits/east", "exits/south", "exits/west", "exits/north" });
	string		*rooms = ({ "/u/ghost/forest4", "/u/ghost/forest1", "/u/ghost/forest2", "/u/ghost/forest3", "/u/ghost/forest8", "/u/ghost/forest5", "/u/ghost/forest6", "/u/ghost/forest7", "/u/ghost/forest9" });
	string		leave, sleave, oldroom;
	int		i;

	if( !ob || environment(ob) != environment() ) return;
	i = (int)this_object()->query_temp("marks/路");
	if(objectp(room = (object)this_object()->query_temp("marks/room"))) {
		if(oldroom = (string)this_object()->query_temp("marks/lastroom")) {
			room->set(dire[i], oldroom);
		}
	}
	room = environment();
	this_object()->set_temp("marks/room", room);
	if( leader = this_object()->query_leader()) {
		sleave = (string)dirg[i];
		leave = (string)this_object()->query_temp("marks/走");
		if(environment(leader) == room) {
			if( sleave != leave) {
				tell_object(leader, HIR "孤独美面带不愉地说道：为甚么不听我话？这样乱走是走不出的！\n" NOR);
				this_object()->set("exits", 0);
			}
			if( (int)this_object()->query("exits") == 8 ) {
				tell_object(leader, HIY "孤独美说道：到了。\n" NOR);
		                leader->set_temp("marks/okleave", 0);
				this_object()->set_leader();
			}
			else {
				i = random(4);
				this_object()->set_temp("marks/路", i);
				this_object()->add("exits", 1);
				oldroom = room->query(dire[i]);
				this_object()->set_temp("marks/lastroom", oldroom);
				room->set(dire[i], rooms[this_object()->query("exits")]);
				tell_object(leader, HIY "孤独美说道：向" + dirc[i] + "走。\n" NOR);
			}
		}
		else {
			this_object()->set("exits", 0);
			this_object()->set_leader();
		}
	}
	else {
		this_object()->set_leader();
		this_object()->set("exits", 0);
		say(HIY "孤独美的喉结上下滚动着，充满了恐惧的眼里露出了一丝希望，喘息着道：\n" NOR);
		say(HIY "你．．．是谁？帮我！没有我，你走不出的！(agree to help)\n" NOR);
	}
	return;
}

int do_agree(string arg)
{
	object		me;

	if(arg == "to help") {
		me = this_player();
		me->set_temp("marks/okleave", 0);
		say("孤独美充满了恐惧的眼里露出了一丝笑意，喘息着对"+ me->name() +"道：谢谢你。\n");
		this_object()->set_leader(me);
		tell_object(me, "孤独美说道：向东走。\n" NOR);
		this_object()->set_temp("marks/路", 0);
		return 1;
	}
	else
		return 0;
}

int do_go(string arg)
{
	this_object()->set_temp("marks/走", arg);
	return 0;
}
