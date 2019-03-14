//
//  datatype.c
//  CS2211_Assign5
//
//  Created by Nikolas North on 2018-11-21.
//  Copyright © 2018 Nikolas North. All rights reserved.
//

// typedef int* Data;
// typedef struct {char *skey1; char *skey2;} Key_struct;
// typedef Key_struct* Key;

#include "datatype.h"

char * string_dup(char *str){
    // Duplicate string pointed to by str with dynamic memory allocation
    char *pstr = (char *)malloc(sizeof(str));
    pstr = strdup(str);
    return pstr;
}

Key key_gen(char *skey1, char *skey2){
    // Generate a key with dynamic memory allocation.
    Key key = (Key)malloc(sizeof(Key));
    key->skey1 = strdup(skey1);
    key->skey2 = strdup(skey2);
    return key;
}

int key_comp(Key key1, Key key2){
    // Returns 1 if key1 > key2, -1 if key1 < key2, 0 if key1 = key2
    if (strcmp(key1->skey1, key2->skey1) == 0) {
        return strcmp(key1->skey2, key2->skey2);
    } else {
        return strcmp(key1->skey1, key2->skey1);
    }
}

void key_print(Key key){
    // Prints a key
    printf("%s | %s | ", key->skey1, key->skey2);
}

void key_free(Key key){
    // Free memory allocated for key
    free(key->skey1);
    free(key->skey2);
    free(key);
}

Data data_gen(int idata){
    // Generate a data with dynamic memory allocation
    Data data = (Data)malloc(sizeof(Data));
    *data = idata;
    return data;
}

void data_set(Data data, int idata){
    // Assign data with idata
    *data = idata;
}

void data_print(Data data){
    // Print data
    printf("%i \n", *data);
}

void data_free(Data data){
    // Free memory allocated for data
    free(data);
}
