
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("扁担", ({ "biandan" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根两丈长的扁担。\n");
		set("value", 200);
		set("material", "wood");
		set("rigidity", 10);
		set("wield_msg", "$N拿出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	init_staff(11);
	setup();
}
