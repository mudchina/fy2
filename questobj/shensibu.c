#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB "生死簿" NOR, ({ "shensibu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "这是一本朱笔判官用来专勾画天下人的生死的簿子。\n");
          }

    setup();
}
