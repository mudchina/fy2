#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "���Ʒɵ��غ�",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "Ҷ�º�",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�׽�",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "ͭǮ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "Ƥ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�����Ž��ס�",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "ռ������",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "exp_bonus":            100,
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�׶��ͻ�",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "����˪",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�������������",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "�������������",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "��ţ",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "Ϲ��",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "ɱ����",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "���Ʋ��",
                "quest_type":           "Ѱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "ý��",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),
        ([      "quest":                "��ū",
                "quest_type":           "ɱ",
                "exp_bonus":            60,
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

