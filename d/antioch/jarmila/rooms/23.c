
#include <std.h>
#include "../jarmila.h"
inherit STORAGE"hill.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"22",
      "west" : ROOMS"24",
   ]));
}

