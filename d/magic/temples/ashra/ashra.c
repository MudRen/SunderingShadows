/*
  Chapel of the Primordial Darkness
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/std/temple";

void create()
{
    ::create();
    set_temple("ashra");
    set_property("indoors",1); 
    set_property("light",0);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Chapel of the Primordial Dark"); 
    set_short("%^RESET%^%^C240%^Chapel of the P%^RESET%^%^C241%^r%^C242%^i%^C243%^m%^C244%^o%^C245%^r%^C243%^d%^C242%^i%^C241%^a%^RESET%^%^C240%^l D%^RESET%^%^C241%^a%^C242%^r%^RESET%^%^C240%^k%^CRST%^");
    set_long("%^RESET%^%^C244%^Awash in %^RESET%^%^C093%^v%^C099%^i%^C105%^o%^C147%^l%^C141%^e%^C135%^t %^RESET%^%^C141%^h%^C147%^u%^C105%^e%^C099%^s %^RESET%^%^C244%^that barely manage to %^RESET%^%^C153%^illuminate %^RESET%^%^C244%^its vastness, this magnificent chapel seems as if immersed in a sea of %^RESET%^%^C241%^e%^C242%^b%^C243%^b%^C244%^i%^C245%^n%^C246%^g %^RESET%^%^C244%^and %^RESET%^%^C240%^f%^C241%^l%^C242%^o%^C243%^w%^C244%^i%^C245%^n%^C246%^g %^RESET%^%^C240%^darkness%^RESET%^%^C244%^. Great columns of %^RESET%^%^C240%^black marble %^RESET%^%^C244%^circle this room, vanishing into the %^RESET%^%^C241%^murk %^RESET%^%^C244%^overhead. The floor descends into the %^RESET%^%^C240%^deeper dark %^RESET%^%^C244%^in flowing waves, each level adorned with plush %^RESET%^%^C053%^p%^C054%^i%^C055%^l%^C056%^l%^C055%^o%^C054%^w%^C053%^s %^RESET%^%^C244%^and %^C056%^c%^C055%^u%^C054%^s%^C053%^h%^C054%^i%^C055%^o%^C056%^n%^C055%^s %^RESET%^%^C244%^before finally reaching the central landing at the lowest point in the chapel. A gently sloping path of %^RESET%^%^C056%^d%^C055%^e%^C054%^e%^C055%^p %^RESET%^%^C056%^v%^C055%^i%^C054%^o%^C055%^l%^C056%^e%^C055%^t %^RESET%^%^C054%^c%^C055%^a%^C056%^r%^C055%^p%^C054%^e%^C055%^t %^RESET%^%^C244%^provides the only passage from the door to the lower landing and grants easy access to each level of the sitting area which was obviously designed with hedonistic comfort in mind. %^RESET%^%^C093%^P%^C099%^u%^C141%^r%^C141%^p%^C135%^l%^C129%^e %^RESET%^%^C135%^m%^C141%^a%^C099%^r%^C093%^b%^C099%^l%^C105%^e %^RESET%^%^C244%^rings the main floor of the room drawing attention to the jagged chunk of unworked %^RESET%^%^C240%^obsidian %^RESET%^%^C244%^that serves as the altar resting at its center. Before the altar is a %^RESET%^%^C241%^podium %^RESET%^%^C244%^with a dark leatherbound tome laying open upon it to allow the faithful to look upon the will of %^RESET%^%^C056%^Ashra%^RESET%^%^C244%^. A %^RESET%^%^C055%^gargantuan statue %^RESET%^%^C244%^depicting the primordial in all her glory dominates the northern wall, looming over four smaller statues of her subordinate deities. Hidden between two columns on the east wall is a small %^RESET%^%^C250%^silver archway%^RESET%^%^C244%^. Against the west wall is a long %^RESET%^%^C241%^desk %^RESET%^%^C244%^occupied by several %^RESET%^%^C240%^d%^C241%^a%^C242%^r%^C243%^k%^C241%^l%^C240%^y garbed acolytes%^RESET%^%^C244%^. Behind the desk, a %^RESET%^%^C241%^dark plaque %^RESET%^%^C244%^etched with a %^RESET%^%^C250%^f%^C251%^l%^C252%^o%^C253%^w%^C252%^i%^C251%^n%^C250%^g %^RESET%^%^C251%^s%^C252%^i%^C253%^l%^C252%^v%^C251%^e%^C250%^r %^RESET%^%^C251%^s%^C252%^c%^C253%^r%^C252%^i%^C251%^p%^C250%^t %^RESET%^%^C244%^describes the services that can be provided here.%^CRST%^");
    set_smell("default","%^RESET%^%^RESET%^%^C093%^The heady, sweet aroma of an exotic incense is in the air.%^CRST%^");
    set_listen("default","%^RESET%^%^C092%^You hear the whispers of the acolytes and the faithful all around you.%^CRST%^");
    set_items(([
        ({"columns","column"}) : "%^RESET%^%^C240%^Black marble %^RESET%^%^C244%^shot through v%^C055%^e%^RESET%^%^C244%^ins of %^RESET%^%^C053%^v%^C054%^i%^C055%^o%^C056%^l%^C054%^e%^C053%^t%^RESET%^%^C244%^, these thick %^RESET%^%^C240%^columns %^RESET%^%^C244%^ascend into the waiting %^RESET%^%^C240%^darkness %^RESET%^%^C244%^overhead.%^CRST%^",
        ({"gargantuan statue","ashra","statue 1"}) : "%^RESET%^%^C244%^Rising from a roiling inferno of %^RESET%^%^C240%^black flame%^RESET%^%^C244%^, this primordial effigy at once terrifies with its %^RESET%^%^C052%^m%^C088%^o%^C124%^n%^C160%^s%^C124%^t%^C088%^r%^C052%^o%^C088%^u%^C124%^s %^RESET%^%^C244%^nature and attracts with its otherworldly %^RESET%^%^C056%^a%^C055%^l%^C054%^l%^C055%^u%^C056%^r%^C055%^e%^RESET%^%^C244%^. The c%^C245%^o%^C247%^i%^RESET%^%^C244%^ls of her %^RESET%^%^C240%^s%^C241%^e%^C243%^r%^C241%^p%^C240%^e%^C241%^n%^C243%^t%^C241%^i%^C240%^n%^C241%^e %^RESET%^%^C243%^b%^C241%^o%^C240%^d%^C241%^y %^RESET%^%^C244%^weave through the sculpted %^RESET%^%^C240%^b%^C241%^a%^C242%^l%^C243%^ef%^C242%^i%^C241%^r%^C240%^e%^RESET%^%^C244%^, the %^RESET%^%^C015%^g%^C231%^l%^C189%^e%^C231%^a%^C015%^m%^C231%^i%^C183%^n%^C231%^g %^RESET%^%^C240%^midnight scales %^RESET%^%^C244%^taking a %^RESET%^%^C055%^purplish hue %^RESET%^%^C244%^from certain angles. This powerfully %^RESET%^%^C240%^s%^C241%^i%^C242%^n%^C243%^u%^C242%^o%^C241%^u%^C240%^s %^RESET%^%^C244%^length holds aloft an %^RESET%^%^C015%^alabaster female torso%^RESET%^%^C244%^, whose %^RESET%^%^C124%^s%^C125%^e%^C126%^n%^C127%^s%^C128%^u%^C127%^o%^C125%^u%^C124%^s c%^C125%^u%^C126%^r%^C127%^v%^C125%^e%^C124%^s %^RESET%^%^C244%^are draped in swathes of %^RESET%^%^C055%^opulent cloth %^RESET%^%^C244%^and an intricate lattice of %^RESET%^%^C088%^p%^C124%^i%^C160%^e%^C124%^r%^C088%^c%^C124%^i%^C160%^n%^C124%^g%^C088%^s %^RESET%^%^C244%^and %^RESET%^%^C220%^j%^C226%^e%^C227%^w%^C228%^e%^C227%^l%^C226%^r%^RESET%^%^C220%^y%^RESET%^%^C244%^. From her shoulders, great %^RESET%^%^C240%^black wings %^RESET%^%^C244%^spread outward, and within them can be seen the %^RESET%^%^C231%^twinkle %^RESET%^%^C244%^of %^RESET%^%^C087%^s%^C123%^t%^C159%^a%^C195%^r%^C159%^l%^C123%^i%^C087%^g%^C123%^h%^C159%^t %^RESET%^%^C244%^as though they contain the %^RESET%^%^C241%^night sky %^RESET%^%^C244%^itself. Ridged %^RESET%^%^C241%^o%^C242%^b%^C243%^s%^C244%^i%^C245%^d%^C243%^i%^C242%^a%^C241%^n h%^C244%^o%^C243%^r%^C242%^n%^C241%^s %^RESET%^%^C244%^crown her head, one pair swept back over the %^RESET%^%^C240%^midnight tresses %^RESET%^%^C244%^of hair that cascade down around her body, and the other pair curled like a ram. A %^RESET%^%^C252%^h%^RESET%^%^C253%^a%^C252%^u%^C251%^n%^C250%^t%^C249%^i%^C250%^n%^C251%^g%^C252%^l%^C253%^y %^RESET%^%^C244%^beautiful %^RESET%^%^C015%^i%^C231%^v%^C255%^o%^C231%^r%^C015%^y m%^C231%^a%^C255%^s%^C015%^k %^RESET%^%^C244%^hides the face of this divine being, its full lips painted %^RESET%^%^C055%^purple %^RESET%^%^C244%^and its eyes an endless sea of %^RESET%^%^C240%^darkness%^RESET%^%^C244%^. Marring the perfection of this %^RESET%^%^C015%^mask %^RESET%^%^C244%^are the many %^C254%^c%^C255%^r%^C244%^a%^C255%^c%^C254%^ks %^RESET%^%^C244%^throughout from which a %^RESET%^%^C240%^black substance %^RESET%^%^C244%^drips as if it is barely containing a deluge of %^RESET%^%^C241%^darkness%^RESET%^%^C244%^. Her arms are outstretched, inviting you into her embrace...%^CRST%^",
        ({"nilith","statue 2"}) : "%^RESET%^%^C244%^Standing among the lengthy %^RESET%^%^C240%^s%^C241%^e%^C243%^r%^C241%^p%^C240%^e%^C241%^n%^C245%^t%^C241%^i%^C240%^n%^C241%^e %^RESET%^%^C243%^c%^C241%^o%^C240%^i%^C241%^l%^C245%^s %^RESET%^%^C244%^and %^RESET%^%^C240%^dark flames %^RESET%^%^C244%^of the massive primordial is an unnaturally tall, %^RESET%^%^C241%^dark-skinned %^RESET%^%^C244%^woman decorated in a lattice of %^C251%^scarification %^RESET%^%^C244%^and %^RESET%^%^C220%^g%^C226%^o%^C227%^l%^C226%^d %^RESET%^%^C220%^p%^C226%^a%^C227%^i%^C226%^n%^C220%^t%^RESET%^%^C244%^. Her hands and chest are devoid of flesh, %^C231%^s%^C230%^k%^C255%^e%^C230%^l%^C231%^e%^C230%^t%^C255%^a%^C230%^l %^RESET%^%^C231%^f%^C230%^i%^C255%^n%^C230%^g%^C231%^e%^C255%^r%^C231%^s %^RESET%^%^C244%^clutching the handle of a %^RESET%^%^C088%^h%^C124%^o%^C160%^r%^C124%^r%^C088%^i%^C124%^f%^C160%^i%^C124%^c %^RESET%^%^C231%^s%^C230%^c%^C255%^y%^C230%^t%^C231%^h%^C230%^e %^RESET%^%^C244%^that appears to have been crafted from the %^RESET%^%^C218%^flesh %^RESET%^%^C244%^and %^RESET%^%^C230%^bone %^RESET%^%^C244%^of %^RESET%^%^C052%^s%^C088%^u%^C124%^f%^C160%^f%^C124%^e%^C088%^r%^C124%^i%^C160%^n%^C124%^g %^RESET%^%^C244%^mortal creatures. Her %^RESET%^%^C230%^rib cage %^RESET%^%^C244%^is splayed open and carved to resemble a %^RESET%^%^C088%^m%^C124%^a%^C160%^c%^C124%^a%^C088%^b%^C124%^r%^C088%^e maw %^RESET%^%^C244%^and trapped within %^C255%^g%^C253%^h%^C251%^o%^C249%^s%^C251%^t%^C253%^l%^C255%^y %^RESET%^%^C244%^faces contorted in %^RESET%^%^C124%^agony%^RESET%^%^C244%^.%^CRST%^",
        ({"lord shadow","statue 3"}) : "%^RESET%^%^C244%^Standing among the lengthy %^RESET%^%^C240%^s%^C241%^e%^C243%^r%^C241%^p%^C240%^e%^C241%^n%^C245%^t%^C241%^i%^C240%^n%^C241%^e %^RESET%^%^C243%^c%^C241%^o%^C240%^i%^C241%^l%^C245%^s %^RESET%^%^C244%^and %^RESET%^%^C240%^dark flames %^RESET%^%^C244%^of the massive primordial is a %^RESET%^%^C241%^figure %^RESET%^%^C244%^clad in %^RESET%^%^C240%^f%^C241%^l%^C242%^o%^C243%^w%^C242%^i%^C241%^n%^C240%^g robes %^RESET%^%^C244%^of %^RESET%^%^C240%^midnight%^RESET%^%^C244%^. %^RESET%^%^C240%^R%^C241%^o%^C242%^i%^C243%^l%^C242%^i%^C241%^n%^C240%^g s%^RESET%^%^C241%^h%^C243%^a%^C242%^d%^C241%^o%^C240%^w %^RESET%^%^C244%^has been meticulously rendered, clinging to his tall, slender frame. His statuesque features are %^RESET%^%^C240%^pure obsidian%^RESET%^%^C244%^, his expression %^RESET%^%^C226%^i%^C227%^m%^C228%^p%^C229%^e%^C230%^r%^C229%^i%^C228%^o%^C227%^u%^C226%^s%^RESET%^%^C244%^, and there is a %^RESET%^%^C245%^j%^C247%^a%^C249%^g%^C245%^g%^C247%^e%^C249%^d %^RESET%^%^C245%^a%^C247%^d%^C249%^a%^C245%^m%^C247%^a%^C249%^n%^C245%^t%^C247%^i%^C249%^n%^C245%^e %^RESET%^%^C247%^c%^C249%^r%^C245%^o%^C247%^w%^C249%^n %^RESET%^%^C244%^resting upon his proud brow. In one hand, he grasps a sphere of %^RESET%^%^C240%^darkness %^RESET%^%^C244%^while the other holds an %^RESET%^%^C241%^iron rod %^RESET%^%^C244%^inscribed with %^RESET%^%^C039%^g%^C045%^l%^C051%^o%^C087%^w%^C051%^i%^C045%^n%^C039%^g a%^RESET%^%^C045%^r%^C051%^c%^C087%^a%^C045%^n%^C039%^e r%^RESET%^%^C045%^u%^C051%^n%^C045%^e%^C039%^s%^RESET%^%^C244%^.%^CRST%^",
        ({"khyron","statue 4"}) : "%^RESET%^%^C244%^Standing among the lengthy %^RESET%^%^C240%^s%^C241%^e%^C243%^r%^C241%^p%^C240%^e%^C241%^n%^C245%^t%^C241%^i%^C240%^n%^C241%^e %^RESET%^%^C243%^c%^C241%^o%^C240%^i%^C241%^l%^C245%^s %^RESET%^%^C244%^and %^RESET%^%^C240%^dark flames %^RESET%^%^C244%^of the massive primordial is an otherworldly %^RESET%^%^C094%^beast%^RESET%^%^C244%^ ensconced in %^RESET%^%^C052%^e%^C088%^l%^C124%^e%^C160%^m%^C196%^e%^C202%^n%^C220%^t%^C226%^a%^C220%^l %^RESET%^%^C202%^e%^C196%^n%^C160%^e%^C124%^r%^C088%^g%^C052%^y%^RESET%^%^C244%^. A %^RESET%^%^C124%^r%^C124%^a%^C160%^g%^C196%^i%^C202%^n%^C214%^g %^RESET%^%^C226%^i%^C220%^n%^C214%^f%^C202%^e%^C196%^r%^C160%^n%^C124%^o %^RESET%^%^C244%^forms the mane of a ferocious %^RESET%^%^C094%^l%^C130%^e%^C136%^o%^C220%^n%^C136%^i%^C130%^n%^C094%^e f%^RESET%^%^C130%^a%^C136%^c%^C094%^e%^RESET%^%^C244%^. Its muscular body is covered in c%^RESET%^%^C214%^r%^C244%^a%^C214%^c%^C226%^k%^RESET%^%^C244%^s from which an %^RESET%^%^C202%^o%^C208%^r%^C214%^a%^C202%^n%^C208%^g%^C202%^e g%^RESET%^%^C208%^l%^C208%^o%^C202%^w %^RESET%^%^C244%^can be seen, indicative of its %^RESET%^%^C220%^molten core%^RESET%^%^C244%^. Tines of %^RESET%^%^C226%^l%^C227%^i%^C228%^g%^C229%^h%^C230%^t%^C229%^n%^C228%^i%^C227%^n%^C226%^g %^RESET%^%^C244%^fork between its %^RESET%^%^C040%^three tails%^RESET%^%^C244%^, each ending in a %^RESET%^%^C022%^s%^C028%^e%^C034%^r%^C040%^p%^C046%^e%^n%^RESET%^%^C034%^t%^C028%^'%^C022%^s h%^RESET%^%^C028%^e%^C028%^a%^C022%^d%^RESET%^%^C244%^, as well as from the tips of its %^RESET%^%^C241%^claws %^C244%^and out of the furrowed %^RESET%^%^C247%^stone %^RESET%^%^C244%^beneath its %^RESET%^%^C241%^cloven hooves%^RESET%^%^C244%^.%^CRST%^",
        ({"faceless","the faceless one","statue 5"}) : "%^RESET%^%^C244%^Sitting casually upon the lengthy %^RESET%^%^C240%^s%^C241%^e%^C243%^r%^C241%^p%^C240%^e%^C241%^n%^C245%^t%^C241%^i%^C240%^n%^C241%^e %^RESET%^%^C243%^c%^C241%^o%^C240%^i%^C241%^l%^C245%^s %^RESET%^%^C244%^of the massive primordial is a relatively small, %^RESET%^%^C240%^cloaked %^RESET%^%^C244%^and %^RESET%^%^C240%^hooded figure%^RESET%^%^C244%^. %^RESET%^%^C241%^D%^C242%^a%^C243%^r%^C244%^k %^RESET%^%^C243%^l%^C242%^e%^C241%^a%^C242%^t%^C243%^h%^C244%^e%^C243%^r %^RESET%^%^C242%^a%^C241%^r%^C242%^m%^C243%^o%^C244%^r %^RESET%^%^C244%^hugs tightly to a lean, athletic body whose size and shape is completely %^RESET%^%^C250%^androgynous%^RESET%^%^C244%^. Straps on the arms and legs bristle with %^RESET%^%^C241%^throwing weapons %^RESET%^%^C244%^and the hilts of a pair of ornate, %^RESET%^%^C240%^jet-handled daggers %^RESET%^%^C244%^peek from beneath the cloak at their sides. When you attempt to look upon their face you find a %^RESET%^%^C124%^g%^C160%^o%^C196%^r%^C124%^y m%^RESET%^%^C160%^a%^C196%^s%^C124%^k %^RESET%^%^C088%^d%^C124%^r%^C160%^i%^C196%^p%^C160%^p%^C124%^i%^C088%^n%^C124%^g %^RESET%^%^C160%^b%^C196%^l%^C160%^o%^C124%^o%^C088%^d%^RESET%^%^C244%^, sewn together from the %^RESET%^%^C144%^faces %^RESET%^%^C244%^of various beings. The lips of this %^RESET%^%^C144%^p%^C095%^a%^C174%^t%^C131%^c%^C130%^h%^C094%^w%^C181%^o%^C101%^r%^C150%^k %^RESET%^%^C217%^m%^C181%^a%^C174%^s%^C136%^k %^RESET%^%^C244%^are twisted into a %^RESET%^%^C052%^cruel grin %^RESET%^%^C244%^and the %^RESET%^%^C088%^c%^C124%^r%^C160%^i%^C124%^m%^C088%^s%^C124%^o%^C160%^n %^RESET%^%^C124%^e%^C088%^y%^C124%^e%^C160%^s %^RESET%^%^C244%^are full of malevolence.%^CRST%^",
        ({"shadow","shade","darkness"}) : "%^RESET%^%^C244%^All around you, the air is filled with a %^RESET%^%^C241%^pervasive gl%^C242%^o%^C243%^o%^C241%^m %^RESET%^%^C244%^that whirls and flows like a sea of %^RESET%^%^C240%^darkness%^RESET%^%^C244%^. %^RESET%^%^C241%^Dark shapes %^RESET%^%^C244%^swim through this sea just beyond your vision revealed only barely by the soft %^RESET%^%^C129%^glow %^RESET%^%^C244%^of the %^RESET%^%^C129%^w%^C128%^i%^C127%^n%^C126%^d%^C127%^o%^C128%^w%^C129%^s%^RESET%^%^C244%^.%^CRST%^",
        ({"altar"}) : "%^RESET%^%^C244%^A boulder of unworked and jagged %^RESET%^%^C240%^obsidian %^RESET%^%^C244%^rests in the center of the landing like the %^RESET%^%^C087%^c%^C159%^o%^C123%^l%^C087%^d %^RESET%^%^C240%^black heart %^RESET%^%^C244%^of this temple. Its %^RESET%^%^C255%^r%^C254%^e%^C253%^f%^C252%^l%^C251%^e%^C252%^c%^C253%^t%^C254%^i%^C255%^v%^C254%^e %^RESET%^%^C244%^surface seems to capture the images in it, only slowly allowing them to fade. The air around the altar is charged with a %^RESET%^%^C129%^p%^C128%^o%^C127%^w%^C126%^e%^C125%^r%^C124%^f%^C088%^u%^C089%^l %^RESET%^%^C090%^e%^C091%^n%^C092%^e%^C093%^r%^C141%^g%^C135%^y %^RESET%^%^C244%^that tingles across your skin as you approach it, and its %^C051%^s%^C087%^m%^C123%^o%^C159%^o%^C087%^t%^C051%^h %^RESET%^%^C244%^surface is %^RESET%^%^C088%^w%^C124%^a%^C160%^r%^RESET%^%^C088%^m %^RESET%^%^C244%^to the touch.%^CRST%^",
        ({"archway" }) : "%^RESET%^%^C244%^This %^RESET%^%^C250%^silver archway %^RESET%^%^C244%^has a painstakingly detailed %^RESET%^%^C240%^raven %^RESET%^%^C244%^molded at its head. The %^RESET%^%^C240%^raven's wings %^RESET%^%^C244%^are outstretched and tiny %^RESET%^%^C129%^a%^C128%^m%^C127%^e%^C126%^t%^C125%^h%^C126%^y%^C127%^s%^C128%^t%^C129%^s %^RESET%^%^C244%^dot its %^RESET%^%^C241%^wing tips %^RESET%^%^C244%^and form its %^RESET%^%^C129%^eyes%^RESET%^%^C244%^.%^CRST%^",
        ({"cushions","pillows"}) : "%^RESET%^%^C244%^Plush velvet %^C056%^c%^C055%^u%^C054%^s%^C053%^h%^C054%^i%^C055%^o%^C056%^n%^C055%^s %^RESET%^%^C244%^adorn each level of the sitting area, each displaying a matching %^RESET%^%^C015%^w%^C231%^e%^C255%^b%^RESET%^%^C244%^-like design of %^RESET%^%^C055%^deep violet%^RESET%^%^C244%^.%^CRST%^",
        ({"desk"}) : "%^RESET%^%^C244%^A long curving %^RESET%^%^C241%^desk %^RESET%^%^C244%^dominates the west wall, its surface freshly %^RESET%^%^C255%^polished %^RESET%^%^C244%^to a %^RESET%^%^C255%^m%^C254%^i%^C253%^r%^C252%^r%^C254%^o%^C255%^r s%^RESET%^%^C254%^h%^C253%^e%^C254%^e%^C255%^n%^RESET%^%^C244%^. Behind it sit several acolytes tending to the racks of %^RESET%^%^C250%^holy water%^RESET%^%^C244%^, %^RESET%^%^C015%^symbols%^RESET%^%^C244%^, and %^RESET%^%^C220%^donations %^RESET%^%^C244%^which they slip into a %^RESET%^%^C055%^purple%^RESET%^%^C244%^-trimmed %^RESET%^%^C240%^black box%^RESET%^%^C244%^. The %^RESET%^%^C241%^dark plaque %^RESET%^%^C244%^hanging over the racks displays the services that can be provided in %^RESET%^%^C250%^f%^C251%^l%^C252%^o%^C253%^w%^C252%^i%^C251%^n%^C250%^g %^RESET%^%^C251%^s%^C252%^i%^C253%^l%^C252%^v%^C251%^e%^C250%^r %^RESET%^%^C251%^s%^C252%^c%^C253%^r%^C252%^i%^C251%^p%^C250%^t %^RESET%^%^C244%^.%^CRST%^",
        ({"podium"}) : "%^RESET%^%^C244%^This sturdy %^RESET%^%^C240%^podium %^RESET%^%^C244%^is engraved with the images of the %^RESET%^%^C240%^Dark Unity%^RESET%^%^C240%^; %^RESET%^%^C241%^Lord Shadow%^RESET%^%^C244%^, %^RESET%^%^C052%^The Faceless One%^RESET%^%^C244%^, %^RESET%^%^C015%^Nilith%^RESET%^%^C244%^, %^RESET%^%^C160%^Khyron %^RESET%^%^C244%^and %^RESET%^%^C056%^Ashra %^RESET%^%^C244%^herself. Resting open upon the podium is a dark tome, the %^RESET%^%^C055%^Libram of the %^RESET%^%^C240%^Eternal Night%^RESET%^%^C244%^, open to the passage of Ashra's charge upon her faithful.%^CRST%^",
    ]));
    set_exits(([
        "south" : "/d/magic/temples/ashra/salon",
        "east" : "/d/magic/temples/ashra/roost",
    ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^RESET%^C240%^The darkness of Ashra grows and soon shall cloak this world in eternal night. Her essence is within us all as we are all born of Her. Only those who embrace this truth can rise above their fear to become one of Her true children. Heed Her sweet whispers for all She asks is that you embrace your most forbidden desires and become a manifestation of Her great nightmare. Darkness begets darkness and so as you spread terror and suffering others shall turn to Her in their hatred and grief and be liberated from their own shackles. Seek always to satisfy your desires so that others can look upon your pleasure and know the rewards that await those who succumb to Ashra's embrace. Make your supplications to Her in flesh and blood for Her hunger is limitless and only those with the strength to act on their desires are worthy to serve Her.
CHARGE
   );
   return 1;
}