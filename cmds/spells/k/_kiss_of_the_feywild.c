#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("kiss of the feywild");
    set_spell_level(([ "druid" : 4, "bard" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS kiss of the feywild [on TARGET]");
    set_damage_desc("increased max hp points on living, decreases on undead");
    set_description("Lo, Their Endless Host, the Harbingers of Life, Mercy and Kindness Followed Where'er She Walked, Where Her Court Will be Held.");
	set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BLUE%^With a shout and a body wide flex, "+caster->QCN+" starts to cast a spell.";
}

int preSpell()
{
    if(!target)
        target = caster;
    if(target->query_property("spell_bonus_hp"))
    {
        tell_object(caster,"The spell is repelled by similar magic.");
        TO->remove();
        return 0;
    }
    return 1;
}

void spell_effect()
{
    if(!target)
        target = caster;

    if(!objectp(target))
    {
        TO->remove();
        return;
    }
    if(!objectp(caster))
    {
        TO->remove();
        return;
    }

    if (caster == target) {
        tell_object(caster,"%^BLUE%^You slowly summon inner strength, lending the force of your will to the strength of your body.");
        tell_room(environment(caster),"%^BLUE%^You see a wave of force surround and strengthen "+caster->QCN+"'s body.",({caster}));
    } else {
        tell_object(caster,"%^BLUE%^You slowly summon inner strength, lending the force of your will to strengthen "+target->QCN+"'s body.");
        tell_object(target,"%^BLUE%^You feel the force of "+caster->QCN+"'s will strengthen your body.");
        tell_room(environment(caster),"%^BLUE%^You see a wave of force surround and strengthen "+target->QCN+"'s body.",({target}));
    }
    bonus = 4*clevel;
    target->add_max_hp_bonus(bonus);
    target->set_property("spelled",({TO}));
    target->set_property("spell_bonus_hp",1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
       target->add_max_hp_bonus(-bonus);
       target->remove_property_value("spelled", ({TO}) );
       target->remove_property("spell_bonus_hp");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
