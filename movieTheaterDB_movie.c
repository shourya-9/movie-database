// Including header from movieTheaterDB_movie.h
#include "movieTheaterDB_movie.h"

// Function to check if movie already exists
int existsMov(struct Movie* head, int code){
    while (head != NULL)
    {
        if(head->code == code)
            return 1; // Returning 1 if movie exists
        head = head->next;
    }
    return 0; // Returning 0 if movie does not exist
}

// Function to insert new movie into linked list
void insertMov(struct Movie** head){
    // Allocating memory for new movie
    struct Movie* newMov = (struct Movie*)malloc(sizeof(struct Movie));
    if(newMov == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter movie code: ");
    int code;
    scanf("%d",&code); // Taking input for movie code
    // Checking if movie code is valid
    if(code < 0){
        printf("Invalid code, please enter a positive number\n");
        return;
    }
    // Checking if movie already exists
    if(existsMov(*head,code)){
        printf("Movie already exists.\n");
    }  
    // If movie does not exist, taking input for movie name, genre and rating 
    else{
        newMov->code = code;
        while((getchar() !='\n')); // removing \n from buffer
        printf("Enter movie name: ");
        fgets(newMov->name,100,stdin); //input for movie name
        newMov->name[strcspn(newMov->name, "\n")] = '\0';

        printf("Enter movie genre: ");
        fgets(newMov->genre,25,stdin); // input for movie genre
        newMov->genre[strcspn(newMov->genre, "\n")] = '\0';

        printf("Enter movie rating: ");
        float rating;
        scanf("%f",&rating); // input for movie rating
        // Checking if rating is valid
        while(rating<0.0f || rating>10.0f){
            printf("Enter a rating between 0.0-10.0: ");
            scanf("%f",&rating);
        }
        newMov->rating = rating;
        // Updating linked list
        newMov->next = NULL;  // Setting the next pointer to NULL

        // If the list is empty, setting the new node as the head
        if (*head == NULL) {
            *head = newMov;
        } else {
            // Traversing to the end of the list
            struct Movie* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }

            // Linking the new node to the end of the list
            current->next = newMov;
        }
    }
}

// Function to print movie table
void printTableMov(struct Movie* head){
    // Printing headings with proper format
    printf("\n%-15s%-40s%-25s%-15s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");
    // Running loop to print movie info
    while (head != NULL)
    {
        printf("%-15d%-40s%-25s%.1f\n",head->code,head->name,head->genre,head->rating);
        head = head->next;
    }
}

// Function to search for a movie with a given code
void searchMov(struct Movie* head, int code){
    // Running loop through linked list to search for movie
    while (head != NULL)
    {
        // If movie found
        if(head->code == code){
            // Printing headings with proper format
            printf("\n%-15s%-40s%-25s%-15s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");
            // Printing movie info of the movie being searched
            printf("%-15d%-40s%-25s%.1f\n",head->code,head->name,head->genre,head->rating);
            return;
        }
        head = head->next; // Updating head
    }
    printf("Movie not found\n");
}

// Function to update movie info
void updateMov(struct Movie* head, int code){
    // Running loop through linked list to search for movie
    while (head != NULL)
    {
        // If movie found
        if(head->code == code){
            printf("Enter movie name: ");
            while((getchar() !='\n')); // Removing \n from buffer
            fgets(head->name,100,stdin); // Taking input for movie name
            head->name[strcspn(head->name, "\n")] = '\0';

            printf("Enter movie genre: ");
            fgets(head->genre,25,stdin); // Taking input for movie genre
            head->genre[strcspn(head->genre, "\n")] = '\0';

            printf("Enter movie rating: ");
            float rating;
            scanf("%f",&rating); // Taking input for movie rating
            // Checking if rating is valid
            while(rating<0.0f || rating>10.0f){
                printf("Enter a rating between 0.0-10.0");
                scanf("%f",&rating);
            }
            head->rating = rating; // Updating movie rating
            return;
        }
        head = head->next; // Updating head
    }
    printf("Movie not found\n");
}

// Function to erase movie
void eraseMov(struct Movie** head, int code){
    struct Movie* curr = *head;
    struct Movie* prev = NULL;
    // If movie to be erased is the first in the linked list
    if(curr != NULL && curr->code == code){
        *head = curr->next;
        free(curr); // Freeing memory
        printf("Movie erased successfully\n");
        return;
    }
    // Running loop through linked list to search for movie
    while (curr != NULL && curr->code != code)
    {
        prev = curr;
        curr = curr->next;
    }
    // If movie not found
    if(curr == NULL){
        printf("Movie not found\n");
        return;
    }
    // Updating linked list
    prev->next = curr->next;
    free(curr); // Freeing memory
    printf("Movie erased successfully\n");
}
