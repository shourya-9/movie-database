#ifndef MOVIETHEATERDB_MOVIE_H
#define MOVIETHEATERDB_MOVIE_H

// Including necessary libraries to be able to use built-in functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining maximum lengths for movie name and genre
#define MAX_NAME_LENGTH 100
#define MAX_GENRE_LENGTH 25

// Defining structure for movie
struct Movie{
    int code;
    char name[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    float rating;
    struct Movie *next; // Pointer to next movie
};

// Function prototypes from movieTheaterDB_movie.c
int existsMov(struct Movie* head, int code);
void insertMov(struct Movie** head);
void printTableMov(struct Movie* head);
void searchMov(struct Movie* head, int code);
void updateMov(struct Movie* head, int code);
void eraseMov(struct Movie** head, int code);

#endif