// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if(environment()==this_player())
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int avai,remain;
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	this_player()->start_busy(1);
	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什麽好吃的了。\n");
	if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
	remain = (int) query("food_remaining") * (int) query("food_supply");
	avai = (int)this_player()->max_food_capacity() - (int)this_player()->query("food");
        if( remain > avai )
        {
        this_player()->add("food", avai);
        add("food_remaining", -(avai/(int)query("food_supply")));
        }
        else
        {
        this_player()->add("food",remain);
        set("food_remaining", 0);
        }

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	if( !query("food_remaining") ) {
		message_vision("$N将剩下的" + name() + "吃得乾乾净净。\n", this_player());
		if( !this_object()->finish_eat() )
			destruct(this_object());
	} else 
		message_vision("$N拿起" + name() + "咬了几口。\n", this_player());

	return 1;
}

