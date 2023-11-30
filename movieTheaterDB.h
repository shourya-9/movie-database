#ifndef MOVIETHEATERDB_H
#define MOVIETHEATERDB_H

// Including headers from movieTheaterDB_movie.h and movieTheaterDB_actor.h
#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"

// Structure prototypes
struct Movie;
struct Actor;

struct movie_actor_code{
    int movActCode;
    int movie_code;
    int actor_code;
    struct movie_actor_code *next;
};

// Function prototypes from movieTheaterDB_movie.c and movieTheaterDB_actor.c
void insertMov(struct Movie** head);
void printTableMov(struct Movie* head);
void searchMov(struct Movie* head, int code);
void updateMov(struct Movie* head, int code);
void eraseMov(struct Movie** head, int code);
void insertActor(struct Actor** head);
void printTableActor(struct Actor *head);
void searchActor(struct Actor *head, int code);
void updateActor(struct Actor *head, int code);
void eraseActor(struct Actor** head, int code);

#endif