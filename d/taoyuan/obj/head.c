//TIE@FY3
inherit ITEM;
void create()
{
        set_name("头颅骨", ({ "skull"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个半腐烂的头颅骨，散发出一股恶臭，从仅存的皮肉上，你
依稀看出是武当的老掌门，头骨百汇穴的地方插着一根七寸长的铁钉。铁钉从
头发里全部插入脑内，如果不是头颅骨的眼睛已经烂掉，真的没法发现老掌门
的死因。\n");
                set("value", 1);
        }
}

int is_container() { return 1; }


