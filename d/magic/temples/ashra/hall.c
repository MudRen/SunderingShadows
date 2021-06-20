/*
  Hall of Nightmares
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/std/templemisc";

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",1);
    set_temple("ashra");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_light(1);
    set_name("Hall of Nightmares"); 
    set_short("%^BOLD%^%^BLACK%^H%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ll %^RESET%^%^RED%^o%^BOLD%^%^BLACK%^f N%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ghtm%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Massive, lavishly gilded walls of solid onyx stand on either side of this lengthy corridor and rise forty feet before reaching the ceiling. The floor, a gl%^WHITE%^a%^BLACK%^ss%^WHITE%^y %^BLACK%^obs%^WHITE%^i%^BLACK%^di%^WHITE%^a%^BLACK%^n, casts a dark reflection and makes the enormous corridor seem truly expansive as if it extends to some unknown depth in the void below. Columns of %^CYAN%^cold %^BLACK%^bl%^CYAN%^a%^BLACK%^ck m%^CYAN%^a%^BLACK%^rble stand in rows along each wall, decorated alcoves set between them to house exquisitely detailed %^WHITE%^ang%^BLACK%^e%^WHITE%^l%^BLACK%^i%^WHITE%^c eff%^BLACK%^i%^WHITE%^g%^BLACK%^i%^WHITE%^es%^BLACK%^. Glowing windows of %^WHITE%^s%^BLACK%^t%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^i%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^d g%^MAGENTA%^l%^RESET%^%^MAGENTA%^a%^BOLD%^%^WHITE%^s%^BLACK%^s are set above alcove, all depicting scenes of ravens in flight spiraling upward towards the deep shadows of the ceiling. Cutting a path down the center of the corridor from the g%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^a%^GREEN%^t %^BOLD%^%^BLACK%^g%^RESET%^%^MAGENTA%^a%^GREEN%^r%^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^n archway to the smaller inner doors is a thick %^RESET%^%^MAGENTA%^d%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^rk v%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^t %^BOLD%^%^BLACK%^carpet with decorative black trim, passing across the reflective floor like a bridge across a chasm. Above the inner door with grand wings outstretched stands an a%^WHITE%^ng%^BLACK%^e%^WHITE%^l %^BLACK%^crafted of pristine %^RESET%^a%^BOLD%^la%^BLACK%^b%^RESET%^a%^BOLD%^ste%^BLACK%^r, its body lightly clad in smoky shadows. All around the gloom is pervasive and the shadows flicker and move of their own accord.%^RESET%^");
    set_smell("default","%^MAGENTA%^A light floral aroma wafts in from the courtyard.%^RESET%^");
    set_listen("default","%^MAGENTA%^A haunting wordless song full of sorrow and loss drifts through the air around you.%^RESET%^");
    set_items(([
        ({"floor"}) : "%^BOLD%^%^BLACK%^This gl%^WHITE%^a%^BLACK%^ssy %^RESET%^o%^BOLD%^%^BLACK%^bs%^WHITE%^i%^BLACK%^di%^WHITE%^a%^BLACK%^n floor gives the illusion of absolute darkness extending beyond sight to some endless unknown depth beneath your feet. As you look more closely into the void you begin to make out images in the murk, %^CYAN%^f%^BLACK%^l%^CYAN%^a%^BLACK%^sh%^CYAN%^e%^BLACK%^s of h%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^rr%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^rs and %^RED%^a%^BLACK%^tr%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^c%^RED%^i%^BLACK%^t%^RESET%^%^RED%^i%^BOLD%^e%^BLACK%^s beyond description and %^RESET%^%^MAGENTA%^seductive %^BOLD%^%^BLACK%^im%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^g%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s that b%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ck%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^n to you, urging you to cast aside your %^RESET%^%^RED%^r%^BOLD%^%^BLACK%^e%^RED%^v%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^l%^RED%^s%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^on and join them in %^RESET%^%^MAGENTA%^un%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^gin%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^bl%^BOLD%^%^BLACK%^e %^RESET%^%^MAGENTA%^pl%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^as%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^re%^BOLD%^%^BLACK%^...%^RESET%^",
        ({"columns","column"}) : "%^BOLD%^%^BLACK%^Black marble shot through v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ins of %^RESET%^%^MAGENTA%^violet%^BOLD%^%^BLACK%^, these thick columns ascend into the waiting darkness overhead.%^RESET%^",
        ({"alcove","effigy"}) : "%^BOLD%^%^BLACK%^Set between the columns are arched alcoves bordered in %^RESET%^%^MAGENTA%^dark amethyst%^BOLD%^%^BLACK%^. Within these alcoves wrapped in the vise like grip of dark tendrils are %^WHITE%^alabaster eff%^BLACK%^i%^WHITE%^g%^BLACK%^i%^WHITE%^es %^BLACK%^of %^RED%^agonized %^WHITE%^angels. %^BLACK%^The tentacles that enwrap the bodies burrow into their flesh creating dark veins that all converge on their pitch black empty eye sockets. Their wings are broken and bent beneath the crushing power of the darkness that holds them. All of their empty eyes seem to be drawn to the %^WHITE%^an%^BLACK%^g%^WHITE%^el%^BLACK%^i%^WHITE%^c%^BLACK%^ form standing over the inner doors.%^RESET%^",
        ({"windows","window"}) : "%^BOLD%^%^BLACK%^These d%^CYAN%^i%^BLACK%^ml%^CYAN%^y %^BLACK%^gl%^CYAN%^o%^BLACK%^w%^CYAN%^i%^BLACK%^ng w%^WHITE%^i%^BLACK%^nd%^WHITE%^o%^BLACK%^ws of %^WHITE%^s%^BLACK%^t%^RESET%^%^MAGENTA%^a%^BOLD%^i%^BLACK%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^d g%^BLACK%^l%^MAGENTA%^a%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^s %^BLACK%^depict a murder of %^RED%^crimson e%^BLACK%^y%^RED%^e%^BLACK%^d ravens spiraling upward into the st%^CYAN%^a%^BLACK%^r-st%^CYAN%^u%^BLACK%^dd%^CYAN%^e%^BLACK%^d darkness of the night sky.%^RESET%^",
        ({"carpet","bridge"}) : "%^BOLD%^%^BLACK%^The thick fabric of this %^RESET%^%^MAGENTA%^violet carpet %^BOLD%^%^BLACK%^walkway is exceptionally soft, cushioning every footfall without a sound. A design of d%^MAGENTA%^a%^BLACK%^rk fl%^MAGENTA%^a%^BLACK%^m%^MAGENTA%^e%^BLACK%^s lick at the edges of the carpet forming a border along the path.%^RESET%^",
        ({"angel"}) : "%^BOLD%^%^BLACK%^Standing tall on a ledge over the inner doors, this %^WHITE%^alabaster %^BLACK%^masterpiece looms over the pathway into the temple. His %^WHITE%^visage %^BLACK%^is that of a fallen %^WHITE%^celestial%^BLACK%^, %^WHITE%^flawless %^BLACK%^statuesque features etched on the smoothest %^WHITE%^alabaster%^BLACK%^. His %^GREEN%^e%^BLACK%^y%^GREEN%^e%^BLACK%^s are equally compelling yet disturbing, black pools of darkness in which his %^GREEN%^brilliant emerald coronas gleam %^BLACK%^like some %^GREEN%^u%^BLACK%^nh%^GREEN%^o%^BLACK%^l%^GREEN%^y e%^BLACK%^cl%^GREEN%^i%^BLACK%^ps%^GREEN%^e%^BLACK%^. Thick shadows pour from his scalp like a bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck fl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^me, fl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng and undulating upward in hypnotic waves. His powerfully muscled body is lean and pristine, contrasted by the network of black veins that grow thicker toward his extremities. About halfway down his forearms and calves his flesh darkens to a solid black with r%^WHITE%^a%^BLACK%^z%^WHITE%^o%^BLACK%^r sh%^WHITE%^a%^BLACK%^rp c%^WHITE%^l%^BLACK%^aw%^WHITE%^s %^BLACK%^tipping his fingers and toes. Encircling his waist and flowing down to creep across the ground like a fine mist is a roiling mass of sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^dow that serves as his only form of clothing. From his shoulders great wings stretch out, sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^dow stuff leaking from between the night black feathers. Around him the light itself seems to dim and the sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^dows fl%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r and writhe in excitement. The empty eyes of every %^RED%^s%^RESET%^%^RED%^u%^BOLD%^ff%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^ng %^WHITE%^a%^BLACK%^n%^WHITE%^g%^BLACK%^e%^WHITE%^l %^BLACK%^are drawn to this figure.%^RESET%^",
        ({"archway"}) : "%^BOLD%^%^BLACK%^Columns of black marble entwined with %^RESET%^%^GREEN%^thorny v%^RED%^i%^GREEN%^nes %^BOLD%^%^BLACK%^form the arched entryway from the courtyard. Bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck r%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^ses bloom among the %^RESET%^%^GREEN%^vines %^BOLD%^%^BLACK%^and a %^WHITE%^cr%^BLACK%^a%^WHITE%^ck%^BLACK%^e%^WHITE%^d p%^BLACK%^o%^WHITE%^rcel%^BLACK%^a%^WHITE%^in m%^BLACK%^a%^WHITE%^sk %^BLACK%^of a beautiful %^RESET%^%^MAGENTA%^female %^BOLD%^%^BLACK%^f%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ce leaking a black ichor is prominently displayed at the center of the arch.%^RESET%^",
    ]));
    set_exits(([
        "north" : "salon",
        "south" : "courtyard",
    ]));
           
    set_door("dark doors","salon","north",0);
    set_door_description("dark doors","%^BOLD%^%^BLACK%^These large intimidating adamantium doors are of exquisite craft, their smooth surfaces glistening as though the metal had been freshly polished. On each door are engravings depicting %^RESET%^%^RED%^demonic %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^otherworldly %^BOLD%^%^BLACK%^creatures, some utterly %^RED%^monstrous %^BLACK%^and others unspeakably %^MAGENTA%^alluring%^BLACK%^. The creatures are intertwined in a mass with mortal beings, some in the throes of %^RESET%^%^MAGENTA%^ecstasy %^BOLD%^%^BLACK%^and others contorted in %^RESET%^%^RED%^suffering%^BOLD%^%^BLACK%^. As your eyes linger upon the engravings, they seem to shift... blurring the lines between %^RED%^agony %^BLACK%^and %^MAGENTA%^pleasure%^BLACK%^, between %^RESET%^%^RED%^monstrous %^BOLD%^%^BLACK%^and %^RESET%^mundane%^BOLD%^%^BLACK%^.%^RESET%^");
}