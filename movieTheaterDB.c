// Including all function prototypes and headers in movieTheaterDB.h 
#include "movieTheaterDB.h"

// Function to print help message
void help(){
    printf("Enter m to control movies\nEnter a to control actors\nEnter q to quit\n");
}

// To check if movie/actor relationship already exists
int existsMovActCode(struct movie_actor_code* head, int movActCode){
    while(head != NULL){
        if(head->movie_code == movActCode)
            return 1; // Returning 1 if exists
        head = head->next;
    }
    return 0; // Returning 0 if does not exist
}

// Function to insert new movie/actor relationship into linked list
void insertMovActor(struct movie_actor_code** head,int movActCode, int movCode, int actCode){
    struct movie_actor_code* newMovActCode = (struct movie_actor_code*)malloc(sizeof(struct movie_actor_code));
    newMovActCode->movActCode = movActCode;
    newMovActCode->movie_code = movCode;
    newMovActCode->actor_code = actCode;
    
    newMovActCode->next = NULL;  // Setting the next pointer to NULL

    // If the list is empty, setting the new node as the head
    if (*head == NULL) {
        *head = newMovActCode;
    } else {
        // Traversing to the end of the list
        struct movie_actor_code* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Linking the new node to the end of the list
        current->next = newMovActCode;
    }
}

// Function to search for movies with a given actor
void searchMovieRel(struct Movie* head, int code){
    // Running loop through linked list to search for movie
    while (head != NULL)
    {
        // If movie found
        if(head->code == code){
            // Printing movie info of the movie being searched
            printf("%-15d%-40s%-25s%.1f\n",head->code,head->name,head->genre,head->rating);
            return;
        }
        head = head->next; // Updating head
    }
    printf("Movie not found\n");
}

// Function to search for actors with a given movie
void searchActorRel(struct Actor* head, int code){
    // Running loop through linked list to search for actor
    while (head != NULL)
    {
        // If actor found
        if(head->code == code){
            // Printing actor info of the actor being searched 
            printf("%-15d%-40s%-25d%s\n",head->code,head->name,head->age,head->url);
            return;
        }
        head = head->next; // Updating head
    }
    printf("Actor not found\n");
}

// Function to print all movie/actor relationships
void printAll(struct movie_actor_code* head){
    printf("Relationship Code\tMovie Code\tActor Code\n");
    while(head != NULL){
        printf("%-24d%-17d%d\n",head->movActCode,head->movie_code,head->actor_code);
        head = head->next;
    }
}

// Function to print movies with a given actor
void printMovies(struct movie_actor_code* head,struct Movie* movHead, int actCode){
    printf("\n%-15s%-40s%-25s%-15s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");
    while(head != NULL){
        // If actor found
        if(head->actor_code == actCode){
            searchMovieRel(movHead,head->movie_code);
        }
        head = head->next;
    }
}

// Function to print actors with a given movie
void printActors(struct movie_actor_code* head,struct Actor* actHead, int movCode){
    printf("\n%-15s%-40s%-25s%-15s\n", "Actor Code", "Actor Name", "Actor Age", "Actor IMDB URL");
    while(head != NULL){
        // If movie found
        if(head->movie_code == movCode){
            searchActorRel(actHead,head->actor_code);
        }
        head = head->next;
    }
}

// Function to search for a movie/actor relationship with a given code
void searchMovActCode(struct movie_actor_code* head){
    printf("Enter movie/actor relationship code: ");
    int movActCode;
    scanf("%d",&movActCode);
    // Running loop through linked list to search for movie/actor relationship
    while(head != NULL){
        if(head->movActCode == movActCode){
            printf("Relationship Code\tMovie Code\tActor Code\n");
            printf("%-24d%-17d%d\n",head->movActCode,head->movie_code,head->actor_code);
            return;
        }
        head = head->next;
    }
    printf("Movie/Actor relationship does not exist in the database\n");
}

// Function to switch between menu options
void switchFunc(char c, struct Movie** headMov, struct Actor** headActor, struct movie_actor_code** headMovActCode){
    // Switching between menu options
    switch (c)
    {
        // Calling help function if h is chosen
        case 'h':
            help();
            break;
        // Calling functions from movieTheaterDB_movie.c if m is chosen
        case 'm':
            printf("Enter i to insert a movie, p to print the movie table, s to search for a movie, u to update a movie, e to erase a movie\n");
            printf("Enter your choice: ");
            char c;
            scanf(" %c",&c); // Taking input of choice
            // Switching between choices
            switch (c)
            {
                // Calling insertMov function if i is chosen
                case 'i':
                    insertMov(headMov);
                    break;
                // Calling printTableMov function if p is chosen
                case 'p':
                    printTableMov(*headMov);
                    break;
                // Calling searchMov function if s is chosen
                case 's':
                    printf("Enter movie code: ");
                    int code;
                    scanf("%d",&code);
                    searchMov(*headMov,code);
                    break;
                // Calling updateMov function if u is chosen    
                case 'u':
                    printf("Enter movie code: ");
                    int code1;
                    scanf("%d",&code1);
                    updateMov(*headMov,code1);
                    break;
                // Calling eraseMov function if e is chosen
                case 'e':
                    printf("Enter movie code: ");
                    int code2;
                    scanf("%d",&code2);
                    eraseMov(headMov,code2);
                    break;
                // Printing error message if invalid choice is entered
                default:
                    printf("Invalid operation code\n");
                    break;
            }
            break;
        // Calling functions from movieTheaterDB_actor.c if a is chosen
        case 'a':
            printf("Enter i to insert an actor, p to print the actor table, s to search for an actor, u to update an actor, e to erase an actor\n");
            printf("Enter your choice: ");
            char c1;
            scanf(" %c",&c1); // Taking input of choice
            // Switching between choices
            switch (c1)
            {
                // Calling insertActor function if i is chosen
                case 'i':
                    insertActor(headActor);
                    break;
                // Calling printTableActor function if p is chosen
                case 'p':
                    printTableActor(*headActor);
                    break;
                // Calling searchActor function if s is chosen
                case 's':
                    printf("Enter actor code: ");
                    int code;
                    scanf("%d",&code);
                    searchActor(*headActor,code);
                    break;
                // Calling updateActor function if u is chosen
                case 'u':
                    printf("Enter actor code: ");
                    int code1;
                    scanf("%d",&code1);
                    updateActor(*headActor,code1);
                    break;
                // Calling eraseActor function if e is chosen
                case 'e':
                    printf("Enter actor code: ");
                    int code2;
                    scanf("%d",&code2);
                    eraseActor(headActor,code2);
                    break;
                // Printing error message if invalid choice is entered
                default:
                    printf("Invalid operation code\n");
                    break;
            }
            break;
        // Calling helper functions from this file if r is chosen
        case 'r':
            printf("Enter i to insert a new movie/actor relationship, p to print the movie/actor relationship table, s to search for a movie/actor relationship, a to print movies with a given actor, m to print actors in a given movie, e to erase a movie/actor relationship\n");
            printf("Enter your choice: ");
            char c2;
            scanf(" %c",&c2); // Taking input of choice
            // Switching between choices
            switch (c2)
            {
                // Inserting new movie/actor relationship if i is chosen
                case 'i':
                    printf("Enter movie/actor relationship code: ");
                    int movActCode;
                    scanf("%d",&movActCode); // Taking input for movie/actor relationship code
                    // Checking if movie/actor relationship code exists
                    if(existsMovActCode(*headMovActCode,movActCode) == 1)
                    {
                        printf("Movie/Actor relationship already exists in the database\n");
                        break;
                    }
        
                    printf("Enter movie code: ");
                    int movCode;
                    scanf("%d",&movCode);
                    // Checking if movie code exists
                    if(existsMov(*headMov,movCode) == 0)
                    {
                        printf("Movie does not exist in the database\n");
                        return;
                    }
                    printf("Enter actor code: ");
                    int actCode;
                    while((getchar() !='\n'));
                    scanf("%d%*c",&actCode);
                    // Checking if actor code exists
                    if(existsActor(*headActor,actCode) == 0)
                    {
                        printf("Actor does not exist in the database\n");
                        return;
                    }
                    // Inserting new movie/actor relationship by calling insertMovActor function
                    insertMovActor(headMovActCode,movActCode,movCode,actCode);
                    break;

                // Printing movie/actor relationship table if p is chosen
                case 'p':
                    printAll(*headMovActCode);
                    break;

                // Searching for movie/actor relationship if s is chosen
                case 's':
                    searchMovActCode(*headMovActCode);
                    break;

                // Printing movies with a given actor if a is chosen
                case 'a':
                    printf("Enter actor code: ");
                    int actCode1;
                    scanf("%d",&actCode1);
                    printMovies(*headMovActCode,*headMov,actCode1);
                    break;

                // Printing actors with a given movie if m is chosen
                case 'm':
                    printf("Enter movie code: ");
                    int movCode1;
                    scanf("%d",&movCode1);
                    printActors(*headMovActCode,*headActor,movCode1);
                    break;

                // Erasing movie/actor relationship if e is chosen
                case 'e':
                    printf("Enter movie/actor relationship code: ");
                    int movActCode1;
                    scanf("%d",&movActCode1);
                    // // Checking if movie/actor relationship code exists
                    // if(existsMovActCode(*headMovActCode,movActCode1) == 0)
                    // {
                    //     printf("Movie/Actor relationship does not exist in the database\n");
                    //     break;
                    // }
                    // Erasing movie/actor relationship by updating linked list
                    struct movie_actor_code* curr = *headMovActCode;
                    struct movie_actor_code* prev = NULL;
                    // If head node itself holds the relationship to be deleted
                    if(curr != NULL && curr->movActCode == movActCode1){
                        *headMovActCode = curr->next;
                        free(curr);
                        printf("Movie/Actor relationship erased successfully\n");
                        return;
                    }
                    // Searching for the relationship to be deleted
                    while(curr != NULL && curr->movActCode != movActCode1){
                        prev = curr;
                        curr = curr->next;
                    }
                    // If relationship not found
                    if (curr == NULL)
                    {
                        printf("Movie/Actor relationship does not exist in the database\n");
                        return;
                    }
                    // Updating linked list
                    prev->next = curr->next;
                    free(curr);
                    printf("Movie/Actor relationship erased successfully\n");
                    break;

                // Printing error message if invalid choice is entered
                default:
                    printf("Invalid operation code\n");
                    return;
            }
            break;

        // Printing error message if invalid choice is entered
        default:
            printf("Invalid operation code\n");
            break;
    }
}
// Main function
int main(){
    // Initializing head pointers for movie and actor linked lists
    struct Movie* headMov = NULL;
    struct Actor* headActor = NULL;
    struct movie_actor_code* headMovActCode = NULL;
    // Printing introductory message
    printf("*********************\n* 2211 Movie Cinema *\n*********************\n");
    printf("Enter operation code(h for help): ");
    char c;
    scanf(" %c",&c); // Taking input of operation code
    // Taking input till 'q' is entered to terminate execution
    while(c != 'q'){
        switchFunc(c,&headMov,&headActor,&headMovActCode);
        printf("\nEnter operation code(h for help): ");
        scanf(" %c",&c);
    }
    return 0;
}