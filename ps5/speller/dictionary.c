// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowerWord[LENGTH + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    // Calculate hash value for the word
    int index = hash(lowerWord);

    // Search for the word in the linked list at the hashed index
    node *current = table[index];
    while (current != NULL)
    {
        // Compare the word in the current node with the lowercase word
        if (strcmp(current->word, lowerWord) == 0)
        {
            // Word found
            return true;
        }
        // Move to the next node in the linked list
        current = current->next;
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int wordLenght = strlen(word);
    int key = 0;

    // getting the key
    for (int i = 0; i < wordLenght; i++){
        key += word[wordLenght];
    }
    

    return key % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen("dictionary", "r");
    if (file == NULL){
        return false;
    }
    char word[26];
    int wordHash = 0;
    while(fscanf(file,"%s",word) != EOF){
        // Create a new node for the word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL) {
            fclose(file);
            return false;
        }
        strcpy(newNode->word, word);
        newNode->next = NULL;

        // Get hash value for the word
        unsigned int index = hash(word);

        // Insert the new node into the hash table
        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int totalSize = 0;

    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Traverse the linked list in each bucket and count the nodes
        node *current = table[i];
        unsigned int bucketSize = 0;
        while (current != NULL)
        {
            bucketSize++;
            current = current->next;
        }

        // Add the count of nodes in the current bucket to the total size
        totalSize += bucketSize;
    }

    return totalSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Free the memory for each node in the linked list
        node *current = table[i];
        while (current != NULL)
        {
            node *temp = current;
            current = current->next;
            free(temp);
        }
        // Reset the head pointer for the bucket to NULL
        table[i] = NULL;
    }

    return true; // Memory deallocation successful
}
