//
//  bstree.h
//  CS2211_Assign5
//
//  Created by Nikolas North on 2018-11-21.
//  Copyright © 2018 Nikolas North. All rights reserved.
//

#ifndef bstree_h
#define bstree_h

#include "datatype.h"

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;

// Function prototype declarations:
BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);

#endif /* bstree_h */
