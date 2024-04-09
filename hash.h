#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1000 // Size of the hashmap

// Struct to hold the publication information
typedef struct Publication {
    char description[1000];
    char authors[1000];
    char date[20];
}Publication;

// Struct for a hashmap node
typedef struct Node {
    char key[100];
    struct Publication publication;
    struct Node* next;
}Node;


