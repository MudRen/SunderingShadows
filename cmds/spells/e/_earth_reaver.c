// Earthenair
// renamed to earth reaver
// Lowered damage after we all agreed, it does too much Dinji 11/13
//swapped with strength of stone for L5 - as we all figured it was a better balance. Nienne, 11/07
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

object sword;
int iter=0;

void create() {
    ::create();
    set_spell_name("earth reaver");
    set_spell_level(([ "innate" : 5, "mage" : 5, "cleric" : 5, "druid" : 5 ]));
    set_spell_sphere("alteration");
    set_domains("earth");
    set_syntax("cast CLASS earth reaver on TARGET");
    set_damage_desc("bludgeoning damage on target for clevel/4 + 1 rounds, shatters stoneskin on target");
    set_description("This spell will cause the ground around the target to erupt and throw dirt and rocks at the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    tell_object(caster,"%^ORANGE%^Looking to the ground, you begin to chant in a "+
        "deep voice, lowering your hands with each syllable.");
    tell_room(place,"%^ORANGE%^Looking to the ground, "+caster->QCN+" begins"+
        " to chant in a deep voice, "+caster->QP+" lowering with each"+
        " syllable.",caster);
    return "display";
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if (caster->query_property("earth reaver"))
    {
        tell_object(caster,"You are already concentrating on a earth reaver spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int num,skinned,dam;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(target)){
        dest_effect();
        return;
    }
    if (environment(caster) != place)
    {
        dest_effect();
        return;
    }
    if (target->query_ghost() || caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    num = roll_dice(1,clevel);
    tell_object(target,"%^ORANGE%^The ground around you surges up violently and "+
		"you are pelted with dirt and rocks.");
    tell_room(environment(target),"%^ORANGE%^The ground around "+target->QCN+" "+
                "surges up violently and "+target->QS+" is pelted with dirt and"+
		" rocks.%^RESET%^",target);

    if(!do_save(target))
    {
        if (skinned = (int)(target->query_stoneSkinned()))
        {
            if (skinned > num)
                target->set_stoneSkinned(skinned - num);
            else
                target->set_stoneSkinned(0);
        }
    }

    dam=sdamage;
    if(iter) { //ongoing hits
        define_base_damage(0);//lazy reroll
        dam = sdamage / 4;
    }

    if(!do_save(target)) damage_targ(target,"torso",dam,"bludgeoning");
    else if(!evade_splash(target)) damage_targ(target,"torso",dam/2,"bludgeoning");
    if(!iter){ //initial hit
        spell_successful();
        caster->set_property("earth reaver",1);
        caster->set_property("spelled", ({TO}) );
        addSpellToCaster();
        spell_duration = (clevel / 4 + 1) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
    iter++;
    call_out("spell_effect",ROUND_LENGTH);
}

void dest_effect(){
    if(objectp(caster))
    {
        caster->remove_property("earth reaver");
        caster->remove_property_value("spelled", ({TO}) );
        remove_call_out("spell_effect");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
