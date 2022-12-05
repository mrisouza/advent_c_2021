#pragma once

typedef long long unsigned int ll_int;

typedef struct Lanternfish {
    int int_timer;
    struct Lanternfish* next;
} lanternfish;

lanternfish* create_lanternfish(void);
lanternfish* add_lantern_fish(lanternfish* head, int int_timer);
void create_offspring(lanternfish* head);
void print_num_lanternfish(lanternfish* head);
void print_lanternfish(lanternfish* head);
void free_lantern_fish(lanternfish* head);
