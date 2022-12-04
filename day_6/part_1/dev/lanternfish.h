#pragma once

#define MAX 10

typedef long long unsigned int ll_int;

typedef struct Lanternfish {
    int int_timer;
    struct Lanternfish* next;
} lanternfish;

void start_lanternfish(lanternfish* l_fish, char* filepath);
