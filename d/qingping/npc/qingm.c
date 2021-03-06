//XXDER/TIE
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("中年书生", ({ "shu sheng","master","master shu sheng" }) );
	set("gender", "男性" );
	set("age", 39);
	set("skill_public",1);
	set("int", 30);
	set("long",
"一个英俊挺拔的中年人，看上去书生味道很重，手上拿着笔，正在对着一
幅画陷入沉思。\n"
		);
        set_skill("unarmed", 70);
        set_skill("sword", 100);
        set_skill("force", 80);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("perception", 10);

        set_skill("bai-quan", 70);
        set_skill("chaos-steps", 100);
        set_skill("qingpingforce", 100);
        set_skill("qingpingsword", 120);

        map_skill("dodge", "chaos-steps");
        map_skill("unarmed", "bai-quan");
        map_skill("force", "qingpingforce");
        map_skill("sword", "qingpingsword");
        create_family("清平山庄", 2, "弟子");
	set("combat_exp", 900000);
	setup();
        carry_object(__DIR__"obj/pcloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/pen")->wield();
}

void attempt_apprentice(object me)
{
        command("smile");
        command("recruit " + me->query("id") );

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","清平山庄剑童");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","清平山庄剑童");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","清平山庄剑手");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","清平山庄剑手");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","清平山庄剑士");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","清平山庄剑老");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","清平山庄剑仙");
                return ;
        } else
                student->set("title","清平山庄剑神");
                return ;

}

