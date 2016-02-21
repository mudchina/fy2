//XXDER@fy3
inherit ROOM;
void create()
{
        set("short", "ÎÔÊÒ");
        set("long", @LONG
·¿¼ä²»´ó£¬Ò²Ã»ÓĞÊ²Ã´°ÚÉè£¬Ö»ÊÇÇ½ÉÏ³¤½£ÈÇÈË×¢Ä¿£¬×¡ÔÚÕâÀïµÄÊÇ
Äª²»Çü£¬½ğ²»Î·£¬¹«Ëï²»ÖÇ£¬ºú²»³î£¬ÆäÖĞ¹«Ëï²»ÖÇ´ÏÃ÷¾ø¶¥£¬ÖÇ¼ÆÌìÏÂ
ÎŞË«£¬ºú³îĞĞÊÂ³¬ÍÑ£¬³öÈËÒâ±í£¬¸üÊÇÒ»Ê±Ö®Ñ¡£¬ËùÒÔÎİËä²»´ó£¬È´Ò²±»Õ
ÕâÁ½ÈË²¼ÖÃµÄ¾®¾®ÓĞÌõ¡£
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
]));

   set("objects", ([
      __DIR__"npc/jin": 1,
   ]) );
        set("coor/x",150);
	set("coor/y",2010);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
