#include <std.h>
#include "../../serakii.h"

inherit STORAGE"white_hall.c";



void create(){
   ::create();



set_exits(([
"southwest" : WHITE"1",
"north" : WHITE"4",

]));


}
