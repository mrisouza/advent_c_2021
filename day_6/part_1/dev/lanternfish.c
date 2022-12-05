#include <stdio.h>
#include <stdlib.h>

#include "lanternfish.h"

lanternfish* create_lanternfish(void){
    lanternfish* l = (lanternfish *) malloc(sizeof(lanternfish));
    l->int_timer = -1;
    l->next = NULL;
    return l;
}

lanternfish* add_lantern_fish(lanternfish* head, int int_timer){
    lanternfish* tmp, *p;
    tmp = create_lanternfish();
    tmp->int_timer = int_timer;
    if(head == NULL){
        head = tmp;
    } else {
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

void create_offspring(lanternfish* head){
    lanternfish* p = head;
    while (p->next != NULL){
        if(p->int_timer == -1){
            p = p->next;
        } else {
            if(p->int_timer == 0){
                p->int_timer = 6;
                add_lantern_fish(head, 9);
            } else {
                p->int_timer--;
            }
            p = p->next;
        }
    }
    if(p->int_timer == 0){
        add_lantern_fish(head, 8);
        p->int_timer = 6;
    } else {
        p->int_timer--;
    }
}

void print_num_lanternfish(lanternfish* head){
    lanternfish* p = head;
    ll_int total = 0;
    while (p->next != NULL){
        if(p->int_timer != -1){
            total++;
        }
        p = p->next;
    }
    total++;
    printf("%lld\n", total);
}

void print_lanternfish(lanternfish* head){
    lanternfish* p = head;
    while(p->next != NULL){
        int timer = p->int_timer;
        if(p->int_timer != -1){
            printf("%d, ", timer);
        }
        p = p->next;
    }
    printf("%d\n", p->int_timer);
}

void free_lantern_fish(lanternfish* head){
    lanternfish* p, *q;
    p = head;
    q = head->next;
    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
    free(q);
}
