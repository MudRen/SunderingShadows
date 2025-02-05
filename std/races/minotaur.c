#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 15, 35, 45, 65 }); }

int *restricted_alignments(string subrace) { return ({ 1, 2, 4, 5, 7, 8 }); }

string *restricted_classes(string subrace) {
  return ({ "bard",  "paladin", "mage", "magus",  "psion", "psywarrior", "sorcerer", "monk", "druid", "warlock" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "jarmila", "kreysneothosies", "eucalia", "callamir", "edea" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 4, 0, 2, -2, 0, -2 }); }

mapping skill_mods(string subrace) { return ([ "perception" : 2, "endurance" : 2 ]); }


int natural_AC(string subrace) { return 2; }

int sight_bonus(string subrace) { return -2; }

mapping daily_uses(string subrace) { return ([]); }

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 16, 3, 8, 3, 3, 3 }); }
int *max_stats() { return ({ 20, 17, 18, 16, 16, 12 }); }
int *stat_adj() { return ({ 4, 0, 2, -2, 0, -2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 0; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "minotaur"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7500; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 2, "con" : 2, "int" : -2, "wis" : 0, "dex" : 0, "cha" : -2 ]); }

int size() { return 3; }

string *limbs() {
    return ({  "head",
               "right arm",
               "right hand",
               "left arm",
               "left hand",
               "left leg",
               "left hoof",
               "right leg",
               "right hoof",
               "waist",
           "neck"});
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    if(gender == "male") return 84;
    return 80;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 650;
    return 620;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 4;

    switch(gender)
    {
    case "male":
        map["base"] = 450;
        switch(height)
        {
        case 84..86: map["adjust"] = -20; map["die"] = 15; break;
        case 87..93: map["adjust"] = 0;   map["die"] = 10; break;
        case 94..96: map["adjust"] = 0;   map["die"] = 15; break;
        case 97..99: map["adjust"] = 10;  map["die"] = 17; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 410;
        switch(height)
        {
        case 80..82: map["adjust"] = -20; map["die"] = 15; break;
        case 83..89: map["adjust"] = 0;   map["die"] = 10; break;
        case 90..92: map["adjust"] = 0;   map["die"] = 15; break;
        case 93..95: map["adjust"] = 10;  map["die"] = 10; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }
    return map;
}

string *query_hair_colors(string who) {
    string *choices = ({});
    choices += ({"ebony", "ivory"});
    choices += ({"sable", "russet"});
    choices += ({"black", "brown", "red", "white"});
    return choices;
}

string *query_eye_colors(string who) {
    string *choices = ({});
    choices += ({"amber"});
    choices += ({"black", "yellow"});
    return choices;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"undercommon","giant",}),"optional":({"beast","dwarvish",})]);
}

string query_default_language()
{
    return "undercommon";
}
