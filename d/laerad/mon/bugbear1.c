//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit "/d/laerad/mon/wander/bbwander.c";

object *attackers;
void move_me();
object num;



void create(){
    ::create();
    set_id(({"bugbear","warrior","champion"}));
    set_name("bugbear champion");
    set_short("Bugbear champion");
    set_long(
	"Standing before you is a very imposing creature.  The beast stands "+
	"nearly 9 feet tall and must weigh 500 pounds at least.  He is covered "+
	"in scraps of armor, probably torn from his former victims bodies' like "+
	"trophies.  He wields a massive two handed sword that is slung over "+
	"his shoulder."
    );
    set_body_type("human");
    set_race("bugbear");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(17+(random(8)),2);
   set_hp(138+(random(64)));
    set_exp(5000)+random(2000);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",21);
    set_stats("strength",22);
    set_stats("dexterity",9);
    set_stats("charisma",5);
    set_stats("constitution",20);
    set_stats("intelligence",7);
    set_stats("wisdom",8);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    add_money("gold",random(1200)+500);
    add_money("copper",random(2500)+2500);
    new("/d/laerad/mon/obj/2sword")->move(TO);
    command("wield sword in right hand and left hand");
    set_emotes(3,({"The Bugbear flexes.","%^MAGENTA%^Bugbear says%^RESET%^: No one will ever defeat me in combat."}),0);
    add_search_path("/cmds/fighter");
    move_me();
    num = random(5)+2;
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}

void init(){
    string race;
    ::init();
    race = (string)TP->query_race();
    if(wizardp(TP) || TP->query_true_invis()) return 1;
	if(race == "human" || race == "elf" || race == "half-elf" || race == "dwarf" || race == "gnome" || race == "halfling"){
	    if(interactive(TP)){
	    force_me("say I'll stomp you into the ground ugly!");
	    }
         force_me("kill "+TPQN);
            return 1;
        }
	if(interactive(TP)){
	force_me("say Move along wimp.");
	}
	return 1;
}

void heart_beat(){
        int i, j;
        object *att;
        ::heart_beat();
   if(!objectp(TO)) return;

        if((att = (object *)TO->query_attackers()) != ({})){
                j = sizeof(att);
                for(i = 0;i <j;i++){
                        call_out("force_me",2,"rush "+att[i]->query_name());

                }
        }
}

void move_me(){
    force_me("north");
    call_out("go_north",5,TP);
}
void go_north(){
    force_me("north");
    call_out("go_north1",num,TP);
}
void go_north1(){
    force_me("north");
    call_out("go_north2",num,TP);
}
void go_north2(){
    force_me("north");
    call_out("go_north3",num,TP);
}
void go_north3(){
    force_me("north");
    call_out("go_north4",num,TP);
}
void go_north4(){
    force_me("north");
    call_out("go_north5",num,TP);
}
void go_north5(){
    force_me("north");
    call_out("go_north6",num,TP);
}
void go_north6(){
    force_me("north");
    call_out("go_north7",num,TP);
}
void go_north7(){
    force_me("west");
    call_out("go_sw",num,TP);
}
void go_sw(){
    force_me("southwest");
    call_out("go_west",num,TP);
}
void go_west(){
    force_me("west");
    call_out("go_west2",num,TP);
}
void go_west2(){
    force_me("west");
    call_out("go_west3",num,TP);
}
void go_west3(){
    force_me("west");
    call_out("go_west4",num,TP);
}
void go_west4(){
    force_me("west");
}