
inherit ROOM;

void create()
{
	set("short", "ԭʼ����");
	set("long", @LONG
������һƬ�ڰ����ڰ��г����˸�ʽ������Σ�գ�ÿһ�ֶ�����
�����������ڴ�������ʧ�˷��򣬼��ʾ�����������
LONG
	);
	set("exits", ([
		"north" : __DIR__"forest5",
		"south" : __DIR__"forest6",
		"east" : __DIR__"forest4",
		"west" : __DIR__"forest5",
	]));
	set("outdoors", "ghost");
	set("coor/x",-1160);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}