//Added prop to prevent summon/dismissal of followers when in quest areas.  Also set to prevent summon/dismissal if room has no teleport prop - Octothorpe 8/31/10
// help expanded with guidelines regarding appropriate gear per suggestion by Cyric
// Heavily rewritten by Spade in June of 2022

// Depends on the rumors daemon for recruit pool selection

#include <std.h>
#include <magic.h>
#include <daemons.h>

#define    MAGE "/cmds/mortal/followers/mage"
#define FIGHTER "/cmds/mortal/followers/fighter"
#define  CLERIC "/cmds/mortal/followers/cleric"
#define   THIEF "/cmds/mortal/followers/thief"
#define   PSION "/cmds/mortal/followers/psion" // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
#define    BARD "/cmds/mortal/followers/bard" // this is to load a plot granted follower only - this is not a standard-issue follower! N, 1/18.
#define    MONK "/cmds/mortal/followers/monk"
#define   DUMBY "/cmds/mortal/followers/dumbyroom"



int help()
{
    write(
        "%^CYAN%^NAME%^RESET%^%^ \n\n" +

        "follower - manage your retinue \n\n" +

        "%^CYAN%^SYNOPSIS%^RESET%^%^ \n\n" +

        "follower (%^ORANGE%^%^ULINE%^list%^RESET%^)\n"+
        "follower recruit (%^ORANGE%^%^ULINE%^id%^RESET%^) \n"+
        "follower abandon [%^ORANGE%^%^ULINE%^id%^RESET%^] \n"+
        "follower rename [%^ORANGE%^%^ULINE%^id%^RESET%^] [%^ORANGE%^name%^RESET%^] \n"+
        "follower title [%^ORANGE%^%^ULINE%^id%^RESET%^] [%^ORANGE%^name%^RESET%^] \n"+
        "follower summon [%^ORANGE%^%^ULINE%^id%^RESET%^] \n"+
        "follower dismiss [%^ORANGE%^%^ULINE%^id%^RESET%^]\n"+
        "follower swap [%^ORANGE%^%^ULINE%^id%^RESET%^] [%^ORANGE%^%^ULINE%^id2%^RESET%^] (currently disabled)\n"+
        "follower [%^ORANGE%^%^ULINE%^id%^RESET%^] [%^ORANGE%^%^ULINE%^command%^RESET%^] OR follower command [%^ORANGE%^%^ULINE%^id%^RESET%^] [%^ORANGE%^%^ULINE%^command%^RESET%^]\n"+
        "follower [%^ORANGE%^%^ULINE%^id1,id2%^RESET%^] [%^ORANGE%^%^ULINE%^command%^RESET%^] \n"+
        "follower all [%^ORANGE%^%^ULINE%^command%^RESET%^] \n\n"+

        "%^CYAN%^DESCRIPTION%^RESET%^ \n\n"+

        "Your retinue is an RP tool that allows you to play as the leader of a group of NPCs. \n"+
        "These NPCs are weaker than other players, and suffer significantly more on death. \n"
        "Upon dying, an NPC follower will LOSE all enchanted gear, several levels, and become unsummonable for a time. \n"+
        "If an NPC follower dies too soon after a previous death, it will meet its final death and be removed from your retinue. \n"+
        "Additionally, it will become harder to recruit new followers for a time. \n\n"+

        "Potential new recruits can be viewed with <follower recruit>, and can be recruited with <follower recruit (id)> \n"+
        "How often NPCs can be recruited, and how often your pool of recruits cycles out, is determined by your character's influence. \n"+
        "To prevent an NPC from slipping out of your fingers, the follower pool will be prevented from cycling for thirty seconds after being viewed. \n\n"
        
        "Using the power of modern magic, new recruits can be renamed while they are inactive using <follower rename [id] [name]> \n"+
        "They can also be given a title using <follower title [id] [name]>. The title must include either $R or $N, or an $N will be added for you. \n\n"+
        "If a follower no longer fits your RP, it can be removed from your retinue with <follower abandon [ID]> \n\n"
    );
    return 1;
}

object make_follower(mapping map, int f_slot)
{
    string f_name, f_class;
    int f_level;
    string f_race;
    object follower, ob, player = this_player();

    f_name = map["name"];
    f_class = map["class"];
    f_race = map["race"];
    f_level = min( ({ map["level"], 50 }) );
    switch(f_class)
    {
    case "fighter":
        follower = new(FIGHTER);
        break;
    case "cleric":
        follower = new(CLERIC);
        break;
    case "thief":
        follower = new(THIEF);
        break;
    case "mage":
        follower = new(MAGE);
        break;
    case "psion": // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
        follower = new(PSION);
        break;
    case "bard": // this is to load a plot granted follower only - this is not a standard-issue follower! N, 12/15.
        follower = new(BARD);
        break;
    case "monk":
        follower = new(MONK);
        break;
    default:
        error("Unknown class " + f_class);
    }

    follower->set_name(f_name);
    follower->set_short(capitalize(f_name) + ", a bold retainer for " + player->query_cap_name());
    follower->add_id(player->query_name() + " retainer");  // Added the id to allow tracking for perfect caster exclusion
    follower->set_level(f_level);
    follower->set_mlevel(f_class, f_level);
    follower->set_guild_level(f_class, f_level);
    follower->set_hd(f_level, 8);
    follower->set_max_hp(roll_dice(12, f_level));
    follower->set_hp(follower->query_max_hp());
    follower->set_alignment(player->query_alignment());
    follower->set_diety(player->query_diety());
    follower->equip_me();
    follower->set_race(f_race);
    follower->set_slot(f_slot);

    if (f_class == "cleric")
    {
        new ("/d/magic/symbols/holy_symbol")->move(follower);
        follower->set_stats("strength",15);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",13);
        follower->set_stats("intelligence",15);
        follower->set_stats("wisdom",20);
        follower->set_stats("charisma",13);
    } else if (f_class == "mage")
    {
        ob = new ("/d/magic/spellbook");
        ob->add_all();
        ob->move(follower);
        ob = new ("/d/magic/comp_bag");
        ob->move(follower);
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",20);
        follower->set_stats("wisdom",15);
        follower->set_stats("charisma",13);
    } else if(f_class == "thief")
    {
        follower->set_stats("strength",15);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",20);
        follower->set_stats("intelligence",14);
        follower->set_stats("wisdom",15);
        follower->set_stats("charisma",13);
    } else if(f_class == "fighter")
    {
        follower->set_stats("strength",20);
        follower->set_stats("constitution",16);
        follower->set_stats("dexterity",14);
        follower->set_stats("intelligence",10);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",12);
    } else if(f_class == "psion")
    {
        new ("/d/magic/psicrystal")->move(follower);
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",20);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",15);
    } else if(f_class == "bard")
    {
        follower->set_stats("strength",12);
        follower->set_stats("constitution",14);
        follower->set_stats("dexterity",16);
        follower->set_stats("intelligence",15);
        follower->set_stats("wisdom",13);
        follower->set_stats("charisma",20);
    }
    return follower;
}

int cmd_follower(string raw_arguments)
{
    object player = this_player(), current_environment = environment(player);
    mapping retinue;
    string command, args_one_and_two, arg_one, arg_two, *target_followers_array, follower_score_sheet;
    object target_follower_object, temp;
    mapping controller, current_recruitables;
    int i, target_follower_key, second_target_follower_key, area_type, influence = player->query_skill("influence");

    /*  Intentionally removed before cohorts are implemented. There's absolutely no justufication for locking an RP tool behind a feat. // Spade
    if(!FEATS_D->usable_feat(player, "leadership"))
    {
        return 0;
    }*/

    player->validate_retinue_influence();
    player->init_retinue();
    retinue = player->get_retinue_mapping();

    if (!raw_arguments)
    {
        return help();
    }

    // This brings me great physical pain, but I don't know how better to do this   // Spade
    if (strsrch(raw_arguments, " ") != -1)
    {
        sscanf(raw_arguments, "%s %s", command, args_one_and_two);
        if (args_one_and_two)
        {
            sscanf(args_one_and_two, "%s %s", arg_one, arg_two);
        }
    }
    else
    {
        command = raw_arguments;
    }

    controller = player->query("current retinue");
    if (!controller)
    {
        controller = ([]);
    }

    switch(command)
    {
    case "list":
        write("");
        write("\n%^C246%^/%^C247%^///%^C248%^///%^C249%^///%^C250%^///%^C251%^///%^C252%^///%^C253%^///%^C254%^///%^C255%^/// %^C051%^Current Followers%^C255%^ ///%^C254%^///%^C253%^///%^C252%^///%^C251%^///%^C250%^///%^C249%^///%^C248%^///%^C247%^///%^C246%^/\n");
        for (i = 0; i < sizeof(retinue); ++i)
        {
            follower_score_sheet = "     %^RESET%^Lv. " + retinue[i]["level"] + " " + retinue[i]["race"] + " " + retinue[i]["class"] + " ";
            write(arrange_string(" ", 3 - strlen("" + i)) + i + ": " + arrange_string(get_full_follower_short(retinue, i), 70 - strwidth(follower_score_sheet)) + follower_score_sheet );
        }
        write("\n%^C246%^/%^C247%^///%^C248%^///%^C249%^///%^C250%^///%^C251%^///%^C252%^///%^C253%^///%^C254%^///%^C255%^////////////////////////%^C255%^/%^C254%^///%^C253%^///%^C252%^///%^C251%^///%^C250%^///%^C249%^///%^C248%^///%^C247%^///%^C246%^/\n");

        break;

    case "recruit":
        player->generate_recruit_pool(0);
        area_type = "daemon/rumours_d.c"->check_room_source_type(current_environment) - 1;
        current_recruitables = player->get_recruit_pool();

        if (area_type == -2)
        {
            write("%^C030%^It's unlikely that you'll be able to recruit anybody here.");
            return 1;
        }

        if (!args_one_and_two)
        {
            write("");
            write("\n%^C247%^//%^C248%^///%^C249%^///%^C250%^///%^C251%^///%^C252%^///%^C253%^///%^C254%^///%^C255%^///%^C051%^ Recruitable Followers%^C255%^ ///%^C254%^///%^C253%^///%^C252%^///%^C251%^///%^C250%^///%^C249%^///%^C248%^///%^C247%^//\n");
            for (i = 0; i < sizeof(current_recruitables[area_type]); ++i)
            {
                follower_score_sheet = "     %^RESET%^Lv. " + current_recruitables[area_type][i]["level"] + " " + current_recruitables[area_type][i]["race"] + " " + current_recruitables[area_type][i]["class"] + " ";
                write(arrange_string(" ", 3 - strlen("" + i)) + i + ": " + arrange_string(capitalize(current_recruitables[area_type][i]["name"]), 70 - strwidth(follower_score_sheet)) + follower_score_sheet );    // Oh god why // Spade
            }
            write("\n%^C246%^/%^C247%^///%^C248%^///%^C249%^///%^C250%^///%^C251%^///%^C252%^///%^C253%^///%^C254%^///%^C255%^////////////////////////%^C255%^/%^C254%^///%^C253%^///%^C252%^///%^C251%^///%^C250%^///%^C249%^///%^C248%^///%^C247%^///%^C246%^/\n");

            player->viewed_recruits();
        }
        else
        {
            if (influence / 5 - 1 < sizeof(retinue))
            {
                write("%^C030%^You are not influential enough to attract another follower without first abandoning one.");
                return 1;
            }
            if (!player->can_recruit())
            {
                write("%^C030%^You need some time to recollect your thoughts before trying that again.");
                return 1;
            }

            if (!sscanf(args_one_and_two, "%d", target_follower_key) || target_follower_key < 0 || sizeof(current_recruitables[area_type]) < target_follower_key)
            {
                write("%^C051%^" + args_one_and_two + "%^C030%^ is not a valid ID.");
                return 1;
            }

            for ( i = 0; i < influence / 5 - 1; ++i )
            {
                if (!mapp(retinue[i]) || !retinue[i])
                {
                    player->set_retinue_follower(i, current_recruitables[area_type][target_follower_key]["name"], current_recruitables[area_type][target_follower_key]["title"], current_recruitables[area_type][target_follower_key]["class"], current_recruitables[area_type][target_follower_key]["level"], current_recruitables[area_type][target_follower_key]["race"]);
                    tell_object(player, "%^C051%^" + capitalize(current_recruitables[area_type][target_follower_key]["name"]) + "%^C030%^ has been assigned to slot %^C051%^" + i + "%^C030%^.");
                    player->generate_recruit_pool(1);
                    player->start_recruiting_cooldown();
                    return 1;
                }
            }
            return 1;
        }
        break;

    case "abandon": // Needs a confirmation prompt. // Spade
        if (!args_one_and_two)
        {
            help();
            return 1;
        }

        target_followers_array = parse_out_target_followers(args_one_and_two);
        for (i = 0; i < sizeof(target_followers_array); ++i)
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key] || controller[target_follower_key])
            {
                tell_object(player, "%^C030%^Best to send them away first...");
                continue;
            }

            player->remove_retinue(target_follower_key);
            tell_object(player, "%^C030%^They will wake up without even remembering you.");
        }
        break;

    case "rename": // This will eventually need checks and a cooldown.  // Spade
        if (!arg_one || !arg_two)
        {
            help();
            return 1;
        }

        target_followers_array = parse_out_target_followers(arg_one);
        for (i = 0; i < sizeof(target_followers_array); ++i) // Does it make sense that you can rename multiple followers at once? No. Are we going to keep it this way? Yes.   // Spade
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key] || controller[target_follower_key]) // Active followers cannot be renamed on purpose. Needs to be split into two different error messages.    // Spade
            {
                tell_object(player, "%^C030%^Such trickery will not work with your follower so near!");
                continue;
            }
            tell_object(player, "%^C051%^" + capitalize(retinue[target_follower_key]["name"]) + "%^C030%^ will wake up believing that their name is %^C051%^" + arg_two + "%^C030%^.");
            player->set_retinue_follower(target_follower_key, lower_case(arg_two), retinue[target_follower_key]["title"], retinue[target_follower_key]["class"], retinue[target_follower_key]["level"], retinue[target_follower_key]["race"]);    // Probably deserves its own function in retinue.c
        }
        break;

    case "title":
        if (!arg_one || !arg_two)
        {
            help();
            return 1;
        }

        target_followers_array = parse_out_target_followers(arg_one);
        for (i = 0; i < sizeof(target_followers_array); ++i) 
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key])
            {
                continue;
            }
            if (strsrch(arg_two, "$N") == -1 && strsrch(arg_two, "$R") == -1 && strsrch(arg_two, "$r") == -1)
            {
                arg_two = "$N, " + arg_two;
            }
            player->set_retinue_follower(target_follower_key, retinue[target_follower_key]["name"], arg_two, retinue[target_follower_key]["class"], retinue[target_follower_key]["level"], retinue[target_follower_key]["race"]);
            if (target_follower_object = controller[target_follower_key])
            {
                target_follower_object->set_short(get_full_follower_short(retinue, target_follower_key));
            }
            tell_object(player, "%^C030%^You change %^C051%^" + capitalize(retinue[target_follower_key]["name"]) + "'s%^C030%^ short to be %^C051%^" + arg_two + "%^C030%^.");
        }
        break;

    case "summon":
        if (!args_one_and_two)
        {
            help();
            return;
        }

        target_followers_array = parse_out_target_followers(args_one_and_two);

        if(current_environment->query_property("no teleport") || current_environment->query_property("no follower"))
        {
            tell_object(player, "%^C030%^Your followers are unable to find their way to your current location.");
            return 1;
        }

        for (i = 0; i < sizeof(target_followers_array); ++i)
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (player->check_follower_status(target_follower_key))
            {
                tell_object(player, "%^C051%^" + capitalize(retinue[target_follower_key]["name"]) + "%^C030%^ has yet to return from death.");
                continue;
            }

            if (sizeof(controller) == player->query_skill("influence") / 10)
            {
                tell_object(player, "%^C030%^You simply cannot coordinate a larger group than you currently lead.");
                continue;
            }

            if (!mapp(retinue[target_follower_key]))
            {
                continue;
            }

            if (!(target_follower_object = controller[target_follower_key]))
            {
                target_follower_object = make_follower(retinue[target_follower_key], target_follower_key);
                target_follower_object->move(DUMBY); // Maybe this is the problem?
                controller[target_follower_key] = target_follower_object;
                target_follower_object->set_followee(player);
                target_follower_object->restore_follower();
                target_follower_object->set_name(retinue[target_follower_key]["name"]);
                target_follower_object->set_short(get_full_follower_short(retinue, target_follower_key));
                target_follower_object->move(DUMBY); // Make sure they're there!
                target_follower_object->set_followee(player);
                target_follower_object->add_id(strip_colors(lower_case(retinue[target_follower_key]["name"])));
                target_follower_object->add_id(strip_colors(retinue[target_follower_key]["name"]));
                target_follower_object->add_id(strip_colors(capitalize(retinue[target_follower_key]["name"])));
                target_follower_object->add_id(strip_colors(player->query_name() + " retainer"));
                target_follower_object->force_me("wearall");
            }
            tell_room(current_environment, "%^C030%^" + player->query_cap_name() + " summons a retainer.", player);
            temp = new(base_name(this_object()));
            temp->start_summoning(1, player, target_follower_object);
            write("%^C030%^You summon %^C051%^"+ target_follower_object->query_cap_name() + "%^C030%^ to you.");
        }
        break;

    case "dismiss":
        if (!args_one_and_two)
        {
            help();
            return 1;
        }

        target_followers_array = parse_out_target_followers(args_one_and_two);
        if(!objectp(player))
        {
            return 1;
        }

        if(current_environment->query_property("no teleport") || current_environment->query_property("no follower"))
		{
		    tell_object(player, "%^C030%^Your followers are unable to find their way out of your current location.");
			return 1;
		}

        for (i = 0; i < sizeof(target_followers_array); ++i)
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key] || !(target_follower_object = controller[target_follower_key]) )
            {
                continue;
            }

            tell_object(player, "%^C030%^You dismiss %^C051%^" + target_follower_object->query_cap_name() + "%^C030%^.%^RESET%^");
            tell_room(environment(target_follower_object),"%^C051%^" + target_follower_object->query_cap_name() + "%^C030%^ leaves the area.%^RESET%^");
            if(target_follower_object->query_invis()) target_follower_object->set_invis();
            target_follower_object->move(DUMBY);
            target_follower_object->remove();
            map_delete(controller, target_follower_key);
        }
        break;

    /*case "swap":
        if (!sscanf(arg_one, "%d", target_follower_key))
        {
            write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
            return 1;
        }
        if (!sscanf(arg_two, "%d", second_target_follower_key))
        {
            write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
            return 1;
        }

        if (player->swap_follower_slots(target_follower_key, second_target_follower_key))
        {
            write("%^C030%^The two have swapped places in your mental ledger.");
        }
        else
        {
            write("%^C030%^You realize that one of those places wasn't populated to begin with. How silly of you.");
        }
        break;*/

    case "command":
        if (!arg_one || !arg_two)
        {
            help();
            return 1;
        }

        target_followers_array = parse_out_target_followers(arg_one);

        for (i = 0; i < sizeof(target_followers_array); ++i)
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key] || !(target_follower_object = controller[target_follower_key]))
            {
                message("info", "%^C030%^A follower with an ID of %^C051%^" + target_follower_key + "%^C030%^ either isn't present, or isn't a part of your retinue.", player);
                continue;
            }
            tell_object(player, "%^C030%^You command %^C051%^" + target_follower_object->query_cap_name() + "%^C030%^ to %^C051%^" + arg_two);
            target_follower_object->force_me(arg_two);
        }
        break;

    default:
        target_followers_array = parse_out_target_followers(command);
        for (i = 0; i < sizeof(target_followers_array); ++i)
        {
            if (!sscanf(target_followers_array[i], "%d", target_follower_key))
            {
                write("%^C051%^" + target_followers_array[i] + "%^C030%^ is not a valid ID.");
                continue;
            }

            if (!retinue[target_follower_key] || !(target_follower_object = controller[target_follower_key]))
            {
                message("info", "%^C030%^A follower with an ID of %^C051%^" + target_follower_key + "%^C030%^ either isn't present, or isn't a part of your retinue.", player);
                continue;
            }
            tell_object(player, "%^C030%^You command %^C051%^" + target_follower_object->query_cap_name() + "%^C030%^ to %^C051%^" + args_one_and_two);
            target_follower_object->force_me(args_one_and_two);
        }
        break;
    }

    player->set("current retinue", controller);
    return 1;
}

// Spade TODO: Surely we can do better than this?
void start_summoning(int time, object tp, object whichmob)
{
    return call_out("summoning", time, tp, whichmob);
}

void summoning(object summoner, object summonee)
{
    if(!objectp(summoner) || !objectp(summonee))
    {
        return;
    }

    tell_room(environment(summoner),"%^C051%^" + summonee->query_cap_name() + "%^C030%^ arrives.");
	summonee->move(environment(summoner));
    summonee->remove_all_properties();
	summonee->set_property("knock unconscious", 1);
    destruct(this_object());
}

string parse_out_target_followers(string string_of_followers)
{
    object player = this_player();
    mapping retinue = player->get_retinue_mapping();
    string *retinue_keys_string = ([]);
    int *retinue_keys_int = ([]);
    int i;

    if (string_of_followers == "all")
    {
        retinue_keys_int = keys(retinue);
        for(i = 0; i < sizeof(retinue_keys_int); ++i)
        {
            retinue_keys_string[i] = retinue_keys_int[i] + "";
        }
        return retinue_keys_string;
    }
    // Make sure character is a number  // Spade (Todo)
    else
    {
        // Is this typecast really necessary?   // Spade
        
        return explode((string)string_of_followers, ",");
    }
}

string get_full_follower_short(mapping retinue, int slot)
{
    return replace_string(replace_string(replace_string(retinue[slot]["title"], "$r", lower_case(retinue[slot]["race"])), "$N", capitalize(retinue[slot]["name"])), "$R", capitalize(retinue[slot]["race"]));
}