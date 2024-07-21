#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to set node values
void setNode(struct node* node, char* key, char* value) {
    node->key = malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

// Initialize the hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = (sum + ((int)key[i] * factor)) % mp->capacity;
        factor = (factor * 31) % __INT16_MAX__;
    }
    bucketIndex = sum % mp->capacity;
    return bucketIndex;
}

// Insert key-value pair into hash map
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);
    
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

// Delete key from hash map
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Search for a key in hash map
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];
    
    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.";
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);
    
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");
    
    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));
    
    printf("\nAfter deletion : \n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));
    
    // Free allocated memory
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* nextNode = currNode->next;
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
