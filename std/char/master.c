#include <dbase.h>
#include <login.h>
#include <ansi.h>
int prevent_learn(object me, string skill)
{
	mapping 	my_family, family;
        int 		betrayer, mylvl, lvl;

	lvl = this_object()->query_skill(skill, 1);
	mylvl = me->query_skill(skill, 1);
        if( betrayer = me->query("betrayer") ) {
                if( mylvl >= lvl - betrayer * 20 ) {
			message_vision("$N神色间似乎对$n不是十分信任，\n也许是想起$p从前背叛师门的事情\n...。\n", this_object(), me );
                        command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
                        return 1;
                }
        }

        if( !me->is_apprentice_of(this_object())) {
		if( !mapp(my_family = me->query("family")) ) 
			return 0;
		if( !mapp(family = this_object()->query("family")) ) 
			return 0;
		if((my_family["family_name"] == family["family_name"]) ) {
                	command("hmm");
                	command("pat " + me->query("id"));
                	command("say 虽然你我同门，可是你并非我的弟子，你还是去找你师父学吧....");
                	return 1;
		}
        }

        return 0;
}
