#include <stdio.h>
#include <stdlib.h>

#include "lanternfish.h"

void start_lanterfish(lanternfish* l_fish, int timer){
    l_fish->int_timer = timer;
    l_fish->next = NULL;
}
