/* Date: 01/14/2019
 * Author: Gajanan Choudhary
 *
 * Problem: Implement a binary tree. Must have the following:
 *     1. Insert a value
 *     2. Lookup a value
 *     3. Smallest-to-largest tree traversal
 *
 * Assumptions:
 *     1. Binary tree is sorted.
 *     2. No repeated values allowed in the tree for now.
 *
 * */
/*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

static int DEBUG = 0;
static int globalid = 0;

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/* Node functions */
/*****************************************************************************/
void freeNode(Node *node){
    if (node){
        if (node->left)  {
            freeNode(node->left);
        }
        if (node->right) {
            freeNode(node->right);
        }
        free(node);
        node=NULL;
        globalid--; /* globalid MUST be zero at this point. */
    }
}

/*****************************************************************************/
/* Searches for a value recursively in the sub-tree below a node */
/* If input node is NULL, returns the empty node, else
 * If input value is found, returns that node, else
 * If input value is not found, returns the node where that value would ideally exist.
 * */
Node ** findNodeByVal(Node **node, int value){
    if      ((*node)==NULL){
        return node;
    }
    else if (value < (*node)->val){
        return findNodeByVal(&((*node)->left), value);
    }
    else if (value > (*node)->val){
        return findNodeByVal(&((*node)->right), value);
    }
    else if (value == (*node)->val){
        return node; /* No duplicate values allowed */
    }
    printf("Error! Control reached a point it should never have.\n");
    printf("Aborting from Function %s, line %d\n", __func__, __LINE__);
    exit(-1);
}

/*****************************************************************************/
/* Displays the tree traversed in ascending order according to stored values.
 * */
void showNodeOrdered(Node *node, int parent, int leftRight){
    if(DEBUG==1) printf("Checkpoint: Function %s, line %d\n", __func__, __LINE__);
    if (node->left)  showNodeOrdered(node->left, node->id, 0);
    if (node){
            printf("Node: ID = % 4i, value = % 4i, parent ID = % 4i", 
                    node->id, node->val, parent);
        if (leftRight==0){
            printf(", Type: Left.\n");
        }
        if (leftRight==1){
            printf(", Type: Right.\n");
        }
        if (leftRight==-1){
            printf(", Type: Root.\n");
        }
    }
    if (node->right) showNodeOrdered(node->right, node->id, 1);
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/* Tree functions */
/*****************************************************************************/
void allocTree(Tree **treeptr){
    *treeptr=malloc(sizeof(Tree));
    if (!(*treeptr)){
        /* Throw error */
        if(DEBUG==1) printf("Error! Function %s, line %d\n", __func__, __LINE__);
            exit(-1);
    }
    (*treeptr)->root=NULL;
}

/*****************************************************************************/
void freeTree(Tree *tree){
    if (tree){
        freeNode(tree->root);
        free(tree);
        tree=NULL;
    }
    if (globalid!=0){
        printf("Something went wrong with the tree. Recheck implementation\n");
    }
}

/*****************************************************************************/
void showTree(Tree *tree){
    Node *node=tree->root; /* Alias for traversal */
    if (node) showNodeOrdered(node, -1, -1);
}

/*****************************************************************************/
/* Inserts node with a given value */
void insertVal(Tree *tree, int value){
    Node **node=findNodeByVal(&(tree->root), value); /* Alias for traversal */
    if (!(*node)){
        (*node) = (Node *) malloc(sizeof(Node));
        (*node)->id = globalid++;
        (*node)->val = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        if(DEBUG==1) printf("Checkpoint: Function %s, line %d\n", __func__, __LINE__);
    }
    else { /* Possible only if value already exists in the tree. */
        /* Throw error */
        printf("Error! Function %s, line %d\n", __func__, __LINE__);
        exit(-1);
    }
}

/*****************************************************************************/
/* Searches for node with a given value */
int lookupVal(Tree *tree, int value){
    Node **foundNode=NULL;
    if (tree && tree->root){
        foundNode = findNodeByVal(&(tree->root), value);
        if (*foundNode){
            printf("    Found node: ID = %i\n", (*foundNode)->id);
            return (*foundNode)->id;
        }
    }
    printf("    Did not find %i in the tree\n", value);
    return -1;
}

/*****************************************************************************/

