// Including header from movieTheaterDB_actor.h
#include "movieTheaterDB_actor.h"

// Function to check if actor already exists
int existsActor(struct Actor* head, int code){
    while (head != NULL)
    {
        if(head->code == code)
            return 1; // Returning 1 if actor exists
        head = head->next;
    }
    return 0; // Returning 0 if actor does not exist
}

// Function to insert new actor into linked list
void insertActor(struct Actor** head)
{
    // Allocating memory for new actor
    struct Actor* newActor = (struct Actor*)malloc(sizeof(struct Actor));
    if(newActor == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter actor code: ");
    int code;
    scanf("%d",&code); // Taking input for actor code
    // Checking if actor code is valid
    if(code < 0){
        printf("Invalid code, please enter a positive number\n");
        return;
    }
    // Checking if actor already exists
    if(existsActor(*head,code) == 1){
        printf("Actor with code already exists.\n");
    }   
    // If actor does not exist, taking input for actor name, age and url
    else{
        newActor->code = code;
        while((getchar() !='\n')); // removing \n from buffer
        printf("Enter actor name: ");
        fgets(newActor->name,50,stdin); //input for actor name
        newActor->name[strcspn(newActor->name, "\n")] = '\0';

        printf("Enter actor age: ");
        int age;
        scanf("%d",&age); // input for actor age
        // Checking if age is valid
        while(age<0 || age>120){
            printf("Enter an age between 0-120");
            scanf("%d",&age);
        }
        newActor->age = age;

        printf("Enter url for IMDB profile page of the actor: ");
        while((getchar() !='\n')); // removing \n from buffer
        fgets(newActor->url,50,stdin); // input for actor url
        newActor->url[strcspn(newActor->url, "\n")] = '\0';

        // Updating linked list
        newActor->next = NULL;  // Setting the next pointer to NULL

        // If the list is empty, setting the new node as the head
        if (*head == NULL) {
            *head = newActor;
        } else {
            // Traversing to the end of the list
            struct Actor* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }

            // Linking the new node to the end of the list
            current->next = newActor;
        }
    }
}

// Function to print actor table
void printTableActor(struct Actor* head){
    // Printing headings with proper format
    printf("\n%-15s%-40s%-25s%-15s\n", "Actor Code", "Actor Name", "Actor Age", "Actor IMDB URL");
    // Running loop to print actor info
    while (head != NULL)
    {
        printf("%-15d%-40s%-25d%s\n",head->code,head->name,head->age,head->url);
        head = head->next;
    }
}

// Function to search for an actor with a given code
void searchActor(struct Actor* head, int code){
    // Running loop through linked list to search for actor
    while (head != NULL)
    {
        // If actor found
        if(head->code == code){
            // Printing headings with proper format
            printf("\n%-15s%-40s%-25s%-15s\n", "Actor Code", "Actor Name", "Actor Age", "Actor IMDB URL");
            // Printing actor info of the actor being searched 
            printf("%-15d%-40s%-25d%s\n",head->code,head->name,head->age,head->url);
            return;
        }
        head = head->next; // Updating head
    }
    printf("Actor not found\n");
}

// Function to update actor info
void updateActor(struct Actor* head, int code){
    // Running loop through linked list to search for actor
    while (head != NULL)
    {
        // If actor found
        if(head->code == code){
            printf("Enter actor name: ");
            while((getchar() !='\n')); // removing \n from buffer
            fgets(head->name,50,stdin); // Taking input for actor name
            head->name[strcspn(head->name, "\n")] = '\0';

            printf("Enter actor age: ");
            int age;
            scanf("%d",&age); // Taking input for actor age
            // Checking if age is valid
            while(age<0 || age>120){
                printf("Enter an age between 0-120: ");
                scanf("%d",&age);
            }
            head->age = age;

            printf("Enter url for IMDB profile page of the actor: ");
            while((getchar() !='\n')); // removing \n from buffer
            fgets(head->url,50,stdin); // Taking input for actor url
            head->url[strcspn(head->url, "\n")] = '\0';
            return;
        }
        head = head->next; // Updating head
    }
    printf("Actor not found\n");
}

// Function to erase actor
void eraseActor(struct Actor** head, int code){
    struct Actor* curr = *head;
    struct Actor* prev = NULL;
    // If actor to be erased is the first in the linked list
    if (curr != NULL && curr->code == code)
    {
        *head = curr->next;
        free(curr); // Freeing memory
        printf("Actor erased successfully\n");
        return;
    }
    // Running loop through linked list to search for actor
    while (curr != NULL && curr->code != code)
    {
        prev = curr;
        curr = curr->next;
    }
    // If actor not found
    if (curr == NULL){
        printf("Actor not found\n");
        return;
    }
    // Updating linked list
    prev->next = curr->next;
    free(curr); // Freeing memory
    printf("Actor erased successfully\n");
}