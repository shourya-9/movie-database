#ifndef MOVIETHEATERDB_ACTOR_H
#define MOVIETHEATERDB_ACTOR_H

// Including necessary libraries to be able to use built-in functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining maximum lengths for actor name and url
#define MAX_ACTOR_NAME_LENGTH 50
#define MAX_ACTOR_URL_LENGTH 50

// Defining structure for actor
struct Actor
{
    int code;
    char name[MAX_ACTOR_NAME_LENGTH];
    int age;
    char url[MAX_ACTOR_URL_LENGTH];
    struct Actor *next; // Pointer to next actor
};

// Function prototypes from movieTheaterDB_actor.c
int existsActor(struct Actor* head, int code);
void insertActor(struct Actor** head);
void printTableActor(struct Actor *head);
void searchActor(struct Actor *head, int code);
void updateActor(struct Actor *head, int code);
void eraseActor(struct Actor** head, int code);

#endif