inherit ITEM;

void create()
{
        set_name("碗", ({ "bowl", "rice bowl" }) );
        set("no_shown", 1);
	set("no_get",1);
        set_weight(500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "in");
                set("long", "一个青花瓷碗，碗周围的米粒都被舔得干干净净。\n");
                set("unit", "个");
                set("value", 20);
        }
}

int is_container() { return 1; }
