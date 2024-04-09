#include "hash.c"


int main() {
    Node** hashmap = initHashMap();

    // insert(hashmap, "10.1109/ICCW.2017.175", "Computer Vision for the Visually Impaired: the Sound of Vision System",
    // "Simona Caraiman; Raju Rastogi",
    // "30 February 2004");
    printf("Welcome to the Electrical Engineering Department!\n");

    int choice;
    char doi[100];
    char description[1000];
    char authors[1000];
    char date[20];
    char doi_retrieve[100];
    do{
        printf("\nEnter a choice:\n1.Store\n2.Retrieve\n3.Exit\n");
        scanf("%d", &choice);
        getchar();
        
        switch (choice){
            case 1:
                // Prompt for DOI number
               
                printf("\nPlease provide the DOI number of the publication: ");
                fgets(doi, sizeof(doi), stdin);
                doi[strcspn(doi, "\n")] = '\0'; // remove newline character

                // Prompt for description
                
                printf("\nDescription:");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // remove newline character

                // Prompt for authors
                
                printf("\nAuthors (separated by semicolons:) ");
                fgets(authors, sizeof(authors), stdin);
                authors[strcspn(authors, "\n")] = '\0'; // remove newline character

                // Prompt for date of publication
                
                printf("\nDate of publication: ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0'; // remove newline character

                // Insert data into the hashmap
                insert(hashmap, doi, description, authors, date);

                printf("\nThank you.\n");

                break;

            case 2:

                
                printf("\nPlease provide the DOI number of the publication: ");
                fgets(doi_retrieve, sizeof(doi_retrieve), stdin);
                doi_retrieve[strcspn(doi_retrieve, "\n")] = '\0';

                // Retrieve example data
                Publication* publication = retrieve(hashmap, doi_retrieve);
                if (publication != NULL) {
                    printf("Description: %s\n", publication->description);
                    printf("Authors: %s\n", publication->authors);
                    printf("Date of Publication: %s\n", publication->date);
                } else {
                    printf("Publication not found.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter valid choice\n");
        }

    }while(choice != 3);
    
    // Free memory
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashmap[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashmap);

    return 0;
}
