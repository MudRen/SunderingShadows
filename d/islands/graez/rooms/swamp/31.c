
#include <std.h>
#include "../../graez.h"

inherit STORAGE"swamp.c";



void create(){
   ::create();

set_exits(([

"west" : SWAM"32",
"southeast" : SWAM"29",

]));

}

