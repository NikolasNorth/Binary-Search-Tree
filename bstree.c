//
//  bstree.c
//  CS2211_Assign5
//
//  Created by Nikolas North on 2018-11-21.
//  Copyright © 2018 Nikolas North. All rights reserved.
//

#include "bstree.h"

BStree bstree_ini(void){
    // Allocate memory of type BStree_node*, set the value to NULL, and return a pointer to the allocated memory
    BStree bst = (BStree)malloc(sizeof(BStree_node *));
    *bst = NULL;
    return bst;
    /*
    BStree_node *pnode = malloc(sizeof(BStree_node));
    BStree bst = &pnode;
    return bst;
     */
}

void bstree_insert(BStree bst, Key key, Data data){
    // Insert data with key into bst. If key already exists in bst, then do nothing.
    if (*bst == NULL) {
        // bst is empty
        BStree_node *pnode = new_node(key, data); // create new node with key and data
        *bst = pnode; // point *bst to new node's address
    } else {
        int key_comp_result = key_comp((*bst)->key, key); // compare keys
        if (key_comp_result < 0) {
            return bstree_insert(&((*bst)->right), key, data); // traverse right subtree
        } else if (key_comp_result > 0) {
            return bstree_insert(&(*bst)->left, key, data); // traverse left subtree
        } else {
            // key already exists in bst
            return; // do nothing
        }
    }
}

BStree_node *new_node(Key key, Data data){
    // bstree_insert helper function creates a pointer to a tree node from key and data
    BStree_node *pnode = (BStree_node *)malloc(sizeof(BStree_node));
    pnode->key = key;
    pnode->data = data;
    pnode->left = NULL;
    pnode->right = NULL;
    return pnode;
}

Data bstree_search(BStree bst, Key key){
    // If key is in bst, return key's associated data. Otherwise return NULL.
    if (*bst == NULL){
        // key not in bst
        return NULL;
    } else if (key_comp((*bst)->key, key) == 0) {
        // key is found
        return (*bst)->data;
    } else {
        if (key_comp((*bst)->key, key) < 0) {
            return bstree_search(&(*bst)->right, key); // traverse right subtree
        } else {
            return bstree_search(&(*bst)->left, key); // traverse left subtree
        }
    }
}

void bstree_traversal(BStree bst) {
    // In order traversal of bst and print each node's key and data.
    if (*bst == NULL) {
        return;
    } else {
        bstree_traversal(&(*bst)->left); // traverse left subtree
        key_print((*bst)->key);
        data_print((*bst)->data);
        bstree_traversal(&(*bst)->right); // traverse right subtree
    }
}

void bstree_free(BStree bst) {
    // Free all dynamically allocated memory of bst. (Post order implementation)
    if (*bst == NULL) {
        return;
    } else {
        bstree_free(&(*bst)->left);
        bstree_free(&(*bst)->right);
        key_free((*bst)->key);
        data_free((*bst)->data);
        free(*bst);
    }
}
