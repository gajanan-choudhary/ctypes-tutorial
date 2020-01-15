/* Date: 01/14/2019
 * Author: Gajanan Choudhary
 * */
/*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"
#include"testcases.h"

/*****************************************************************************/
void testGeneralTree(){
    Tree *tree;
    int i, foundNodeID;

    int notvalues[10]        ={0, 1, 3, 4, -2, 5, 13, 11, 343, 341};
    int values[10]           ={124, 87, 342, 12, 7, 125, 89, 2, 121, -254};
    //int correctLeftRights[10]={ -1,  0,   1,  0, 0,   0,  1, 0,   1,    0};
    /* -1:root, 0:left, 1:right */

    printf("\n/***********************************************************/\n");
    printf("/******************** General tree test ********************/\n");
    printf("Allocating tree...\n");
    allocTree(&tree);

    printf("Inserting values in the tree...\n    [");
    for (i=0; i<10; i++){
        insertVal(tree, values[i]);
        printf(" %i ",values[i]);
    }
    printf("]\n");

    printf("\nVerifying that inserted values exist in the tree...\n");
    for (i=0; i<10; i++){
        printf("Searching for value % 4i...", values[i]);
        foundNodeID = lookupVal(tree, values[i]);
        if (foundNodeID!=i){
            printf("Test case failed! Couldn't find value that should exist.");
            printf("Function %s, line %d\n", __func__, __LINE__);
            exit(-1);
        }
    }

    printf("\nVerifying that non-existent values are not wrongly "
            "reported to exist in the tree...\n");
    for (i=0; i<10; i++){
        printf("Searching for value % 4i...", notvalues[i]);
        foundNodeID = lookupVal(tree, notvalues[i]);
        if (foundNodeID!=-1){
            printf("Test case failed! Found value that shouldn't exist.");
            printf("Function %s, line %d\n", __func__, __LINE__);
            exit(-2);
        }
    }
    
    printf("\nDisplaying tree...\n");
    showTree(tree);

    printf("Freeing tree...\n");
    freeTree(tree);

    printf("Finished testing.\n");
    printf("Check tree node arrangement manually using printed data.\n");
}

/*****************************************************************************/
void testSortedTraversal(){
    Tree *tree;
    int i;

    int values[24] ={124,  53,  21,  94, 626, 846, 352, 731, 234, 1, -23,    0,
                     942,   9, 654,  87, 342,  12,   7, 125,  89, 2, 121, -254};

    printf("\n/***********************************************************/\n");
    printf("/****************** Sorted traversal test ******************/\n");
    allocTree(&tree);

    printf("Inserting values in the tree...\n    [");
    for (i=0; i<24; i++){
        insertVal(tree, values[i]);
        printf(" %i ",values[i]);
    }
    printf("]\n");

    showTree(tree);

    freeTree(tree);

    printf("Finished testing.\n");
    printf("Check printed data to ensure sorted ascending traversal.\n");
}

/*****************************************************************************/
