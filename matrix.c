//
//  matrix.c
//  CS2211_Assign5
//
//  Created by Nikolas North on 2018-11-21.
//  Copyright © 2018 Nikolas North. All rights reserved.
//

#include "matrix.h"

Matrix matrix_construction(void) {
    // Matrix construction using bstree_ini().
    Matrix matrix = bstree_ini();
    return matrix;
}

unsigned char matrix_isin(Matrix m, Index index1, Index index2) {
    // If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
    Key search_key = key_gen(index1, index2); // create new key object
    Data search_result = bstree_search(m, search_key);
    if (search_result == NULL) {
        return 0; // location is undefined
    } else {
        return 1; // location is defined
    }
}

Value *matrix_get(Matrix m, Index index1, Index index2) {
    // If location (index1, index2) is defined in Matrix m, then return a pointer to the associated value. Otherwise, return NULL.
    Key search_key = key_gen(index1, index2);
    Data search_result = bstree_search(m, search_key);
    if (search_result == NULL) {
        return NULL;
    } else {
        return search_result;
    }
}

void matrix_set(Matrix m, Index index1, Index index2, Value value) {
    // Assign value to Matrix m at location (index1, index2). If that location already has a value, then overwrite.
    Key key = key_gen(index1, index2);
    // check if key already exists in matrix
    Data data = bstree_search(m, key);
    if (data == NULL) {
        // key does not exist in matrix
        data = data_gen(value);
        bstree_insert(m, key, data); // create new entry
    } else {
        // key already exists in matrix
        data_set(data, value); // overwrite data
    }
}

void matrix_inc(Matrix m, Index index1, Index index2, Value value) {
    // If location (index1, index2) is defined in Matrix m, then increase the associated value by value. Otherwise, report error.
    Key key = key_gen(index1, index2);
    Data data = bstree_search(m, key);
    if (data == NULL) {
        printf("Error: (%s, %s) is not defined in Matrix.", index1, index2);
    } else {
        data_set(data, *data + value);
    }
}

void matrix_list(Matrix m) {
    // Print the indices and values in the Matrix m.
    bstree_traversal(m);
}

void matrix_destruction(Matrix m) {
    // Free allocated space.
    bstree_free(m);
}
