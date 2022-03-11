#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person * next;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

// Initializing the table
// Assign memory to NULL to prevent dangling
void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    printf("Start\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];

            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {

    if (p == NULL) {
        return false;
    }

    int index = hash(p->name);

    p->next = hash_table[index];

    hash_table[index] = p;

    return true;
}

person *hash_table_lookup(char *name) {
    int index = hash(name);
    
    person *tmp =hash_table[index];

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }

    return tmp;
}

person *hash_table_delete(char *name) {
    int index = hash(name);
        
    person *tmp =hash_table[index];
    person *prev = NULL;

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return NULL;
    }

    if (prev == NULL) {
        //deleting the head
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

void isFound(person *tmp) {
    if (tmp == NULL) {
        printf("Not Found\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
}

int main() {
    init_hash_table();
    print_table();

    person mert = {.name = "Mert", .age = 23};
    person emma = {.name = "Emma", .age = 24};
    person sam = {.name = "Sam", .age = 37};
    person kayra = {.name = "Kayra", .age = 22};
    person tuna = {.name = "Tuna", .age = 17};
    person hatice = {.name = "Hatice", .age = 45};
    person ozcan = {.name = "Ozcan", .age = 57};
    person bob = {.name = "Bob", .age = 98};
    person rob = {.name = "Rob", .age = 78};

    hash_table_insert(&mert);
    hash_table_insert(&emma);
    hash_table_insert(&sam);
    hash_table_insert(&kayra);
    hash_table_insert(&tuna);
    hash_table_insert(&hatice);
    hash_table_insert(&ozcan);
    hash_table_insert(&bob);
    hash_table_insert(&rob);

    print_table();

    person *tmp = hash_table_lookup("Emma");
    isFound(tmp);

    tmp = hash_table_lookup("Clark");
    isFound(tmp);

    hash_table_delete("Sam");

    tmp = hash_table_lookup("Sam");
    isFound(tmp);

    print_table();

    return 0;
}