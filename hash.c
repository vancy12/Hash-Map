#include "hash.h"

// Hash function
int hash(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31 + key[i]) % HASH_SIZE;
    }
    return hash;
}

// Function to initialize a hashmap
Node** initHashMap() {
    Node** hashmap = (Node**)malloc(HASH_SIZE * sizeof(Node*));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashmap[i] = NULL;
    }
    return hashmap;
}

// Function to insert a publication into the hashmap
void insert(Node** hashmap, char* key, char* description, char* authors, char* date) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->publication.description, description);
    strcpy(newNode->publication.authors, authors);
    strcpy(newNode->publication.date, date);

    // this prevents hash collision if multiple nodes at the same index
    newNode->next = hashmap[index];
    hashmap[index] = newNode;
}

// Function to retrieve publication information from the hashmap
struct Publication* retrieve(Node** hashmap, char* key) {
    int index = hash(key);
    Node* current = hashmap[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return &(current->publication);
        }
        current = current->next;
    }
    return NULL;
}
