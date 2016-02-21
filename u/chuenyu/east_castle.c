
inherit ROOM;

void create()
{
        set("short", "���ɳǱ��Ķ���");
        set("long", @LONG
��վ�ں���ɽ�������ɳǱ��Ķ��ࡣ���ʵĳ�ǽ�ϳ�������ɫ��
���١����ٴ�ǽ��һֱ������Ľ��¡��������ǵ�������������¡�
�������ǳǱ������š��������һ����ʯ�塣
LONG
        );
        set("exits", ([
                "west" : __DIR__"gate_castle",
        ]));
        set("item_desc", ([
                "wall": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
		"��ǽ": "��ǽ�䶸�������������١����ƺ�����������(climb)��ȥ��\n",
		"��ʯ��": "��ʯ�����ε����ڵ��£����������ƺ��ǿյġ�\n",
		"rock" : "��ʯ�����ε����ڵ��£����������ƺ��ǿյġ�\n",
		"����": "���ٳ����˳�ǽ�����ƺ�����������(climb)��ȥ��\n"	
        ]) );
       set("outdoors", "chuenyu");

        set("coor/x",140);
	set("coor/y",140);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("climbing", "climb");
}

int climbing(string arg)
{
	object obj;
	object me;
	if(!arg || arg=="")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( arg == "wall" || arg == "����" || arg == "��ǽ")
	{
	me = this_player();
        message_vision("$Nץ�����٣�������˳�ų�ǽ������ȥ��\n", me);
	me->start_busy(3);
	call_out("fliping",3,me);
	me->stop_busy();
	return 1;
	}
	else
	{
		write("�㲻������"+arg+"\n");
		return 1;
	}
}

int fliping(object me)
{
	if(!me->is_ghost()){
        me->move(__DIR__"east_garden.c");
        message_vision("$N����һ��ǽͷ�������ɵ����˹�����\n", me);
	}
	return 1;
}