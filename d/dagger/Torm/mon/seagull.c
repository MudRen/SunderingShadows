#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("seagull");
  set_id(({ "gull", "bird","seagull","sea gull" }));
  set_short("Seagull");
  set_emotes(2,({
  "Seagull picks at something on the boardwalk.",
  "The seagull takes off momentarily to drift on the breezes before settling again on a post.",
  }),0);
  set_long("This large white bird wanders around more or less ignoring you while it searches for scraps.  Every now and then it will take flight and swoop low to try and catch a tasty fish that it spotted.");
  set_hd(1,1);
  set_max_hp(25);
  set_hp(query_max_hp());
  set_race("bird");
  set_body_type("fowl");
  set_ac(5);
  set_exp(1);
  set_damage(1,3);
  set_attack_limbs(({"beak"}));
  set_base_damage_type("slashing");
}

void reset(){
  ::reset();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_night()){
   command("emote flies away into the on coming mist.");
//   TO->move("/d/shadowgate/void.c"); 
// not needed since it doesn't have anything to drop
  TO->remove();
 }
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 25; }
string query_DC_type(){ return "survival"; }

