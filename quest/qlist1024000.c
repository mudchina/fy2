#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "����ʹ��",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��������������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "һ��÷��������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�̸赶������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�ڹ��ķ�����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��粽������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "ʯ��",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�Ͻ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "���Ե���",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "���ǽ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��ʱ����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�˺�����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "Ѧ����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�ҳ���",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "̫�����Ե���",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��ʿ",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "�ƿ���",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "��Ѫ�̿�",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":                "���·�",
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),
        ([      "quest":              HIG "���´�" NOR,
                "quest_type":           "Ѱ",
                "exp_bonus":            70,
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

