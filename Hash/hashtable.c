#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
    //...
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

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {

    printf("Start\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }

    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL) {
        return false;
    }

    int index = hash(p->name);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;

        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name) {
    int index = hash(name);
    

    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL) {
            return false; // Not here
        }

        if (hash_table[try] == DELETED_NODE) {
            continue;
        }

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        } 
    }
    return NULL;
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;


        if (hash_table[try] == NULL) {
            return NULL;
        }

        if (hash_table[try] == DELETED_NODE) {
            continue;
        }

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            person * tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        } 
    }
    return NULL;
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

    if (tmp == NULL) {
        printf("Not Found\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    tmp = hash_table_lookup("Clark");

    if (tmp == NULL) {
        printf("Not Found\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    hash_table_delete("Sam");

    tmp = hash_table_lookup("Sam");

    if (tmp == NULL) {
        printf("Not Found\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    print_table();

    return 0;
}