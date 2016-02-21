// medicine.c
inherit ITEM;
void create()
{
	set_name("¹ÛÒôÏñ",({"guan yin"}));
        set_weight(6000);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "Ò»×ğ¹ÛÒôÏñ£¬¾İ´«¹ò°İ£¨knee£©ÒÔºó£¬ÁìÎòÎä¹¦»áÍ»·ÉÃÍ½ø£®\n");
	    set("unit","×ğ");
	    set("value", 20000);
	}
}

void init()
{
	add_action("apply_effect","knee");
}

int apply_effect()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("Õ½¶·ÖĞÔõÃ´ÄÜ¹ò°İ¹ÛÒô£¿\n");
		    
	message_vision("$N£¢àÛàÌ£¢Ò»Éù£¬¹òµ¹ÔÚ¹ÛÒôÏñÇ°£¬¹§¹§¾´¾´µØ¿ÄÁËÈı¸öÏìÍ·£¡\n",this_player());
	this_player()->receive_damage("kee",10);
	if(!random(500)) this_player()->add("int",-1);
	return 1;
}


