inherit ITEM;

void create()
{
        set_name("���", ({ "���", "��","chi" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "ˮɫΪ��ĳ�̶\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

