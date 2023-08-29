#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the huge array
#define ARRAY_SIZE 1000000

// Sparse array structure
typedef struct {
    int *values;
    bool *initialized;
} SparseArray;

// Hash table structure
typedef struct {
    unsigned int *hashes;
    size_t *indices;
} HashTable;

// Hash function
unsigned int hash(unsigned int index) {
    return index % ARRAY_SIZE; // Simple modulus hashing
}

// Initialize sparse array
void initSparseArray(SparseArray *sparseArray) {
    sparseArray->values = NULL;
    sparseArray->initialized = NULL;
}

// Read operation
int read(SparseArray *sparseArray, HashTable *hashTable, unsigned int index) {
    unsigned int hashedIndex = hash(index);
    size_t actualIndex = hashTable->indices[hashedIndex];
    if (sparseArray->initialized[actualIndex]) {
        return sparseArray->values[actualIndex];
    } else {
        return 0; // Return initialized value
    }
}

// Write operation
void write(SparseArray *sparseArray, HashTable *hashTable, unsigned int index, int value) {
    unsigned int hashedIndex = hash(index);
    size_t actualIndex = hashTable->indices[hashedIndex];
    if (!sparseArray->values) {
        sparseArray->values = (int *)calloc(ARRAY_SIZE, sizeof(int));
        sparseArray->initialized = (bool *)calloc(ARRAY_SIZE, sizeof(bool));
    }
    if (!sparseArray->initialized[actualIndex]) {
        sparseArray->values[actualIndex] = 0;
        sparseArray->initialized[actualIndex] = true;
    }
    sparseArray->values[actualIndex] = value;
}

int main() {
    // Create and initialize the sparse array and hash table
    SparseArray sparseArray;
    initSparseArray(&sparseArray);
    
    HashTable hashTable;
    hashTable.hashes = (unsigned int *)calloc(ARRAY_SIZE, sizeof(unsigned int));
    hashTable.indices = (size_t *)calloc(ARRAY_SIZE, sizeof(size_t));
    
    // Populate the hash table with hash-index mappings
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        hashTable.hashes[i] = hash(i);
        hashTable.indices[hashTable.hashes[i]] = i;
    }
    
    // Perform read and write operations
    write(&sparseArray, &hashTable, 12345, 42); // Write to index 12345
    int value = read(&sparseArray, &hashTable, 12345); // Read from index 12345
    printf("Value at index 12345: %d\n", value);
    
    // Clean up memory
    free(hashTable.hashes);
    free(hashTable.indices);
    
    return 0;
}
