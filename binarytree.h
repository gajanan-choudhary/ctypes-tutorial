/* Date: 01/14/2019
 * Author: Gajanan Choudhary
 *
 * Problem: Implement a binary tree. Must have the following:
 *     1. Insert a value
 *     2. Lookup a value
 *     3. ??? <I cannot recall this one. Smallest-to-largest traversal?>
 *
 * Assumptions:
 *     1. Binary tree is sorted.
 *     2. No repeated values allowed in the tree for now.
 *
 * */
/*****************************************************************************/
#ifndef __BINARYTREE__HEADER__
#define __BINARYTREE__HEADER__

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/* The Node */
typedef struct Node Node;
typedef struct Node{
    int id;
    int val;
    Node *left;
    Node *right;
} Node;

/*****************************************************************************/
/* The Tree */
typedef struct{
    Node *root;
} Tree;

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/* Node functions */
void freeNode(Node *node);
Node ** findNodeOfVal(Node **node, int value);
void showNode(Node *node, int parent, int leftRight);

/*****************************************************************************/
/* Tree functions; Some of these depend on Node functions. */
void allocTree(Tree **treeptr);
void freeTree(Tree *tree);
void showTree(Tree *tree);
int lookupVal(Tree *tree, int value);
void insertVal(Tree *tree, int value);

#endif //#ifndef __BINARYTREE__HEADER__
