//mac's qianyuan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","ǰԺ");
  set("long",@LONG
��ʯ�̵ĵ�����������ͭ��¯��¯��ʢ������ң������Ǵ�
�����ǳ��ȣ�������ǧ�𶴡������Ǳ�ɽ�������򶫿ɼ���ֱ���͵�
ɽ�ң��ͱ���Ҳ�����˷���ΡΪ׳�ۣ�����̾Ϊ��ֹ��
LONG
  );
  set("exits",([
         "north":__DIR__"dadian.c",
         "west" :__DIR__"changlang.c",
         "east" :__DIR__"changlang2.c",
         "south":__DIR__"jinggang.c"
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  set("coor/x",50);
	set("coor/y",2030);
	set("coor/z",30);
	setup();
  replace_program(ROOM);
}