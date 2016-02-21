inherit ITEM;

void create()
{
        set_name("Ä¢¹½", ({ "mushroom" , "Ä¢¹½"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "°×°×ÅÖÅÖµÄÄ¢¹½¡£ \n");
                set("value", 1);
        }
}

