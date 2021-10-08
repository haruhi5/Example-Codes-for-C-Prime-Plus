#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SLEN 20
#define MAXITEMS 10
typedef struct item
{
    char name[SLEN];
    char kind[SLEN];
} Item;

typedef struct trnode
{
    Item item;
    struct trnode *left; // struct cannot contain the same struct
    struct trnode *right;
} Trnode;
typedef struct tree
{
    Trnode *root;
    int size; // count the item in the Tree
} Tree;       // Tree is a pointer point to Node
/* function prototypes */
/* operation: initialize a Tree */
/* preconditions: pTree points to a Tree */
/* postconditions: the Tree is initialized to empty */
void InitializeTree(Tree *pTree);

/* operation: determine if Tree is empty */
/* pTree points to an initialized Tree */
/* postconditions: function returns True if Tree is empty */
/* and returns False otherwise */
bool TreeIsEmpty(const Tree *pTree);

/* operation: determine if Tree is full */
/* pTree points to an initialized Tree */
/* postconditions: function returns True if Tree is full */
/* and returns False otherwise */
bool TreeIsFull(const Tree *pTree);

/* operation: determine number of items in Tree */
/* pTree points to an initialized Tree */
/* postconditions: function returns number of items in Tree */
int TreeItemCount(const Tree *pTree);

/* operation: add item to rear of Tree */
/* precondition: pq points to previously initialized Tree */
/* item is to be placed at rear of Tree */
/* postcondition: if Tree is not empty, item is placed at */
/* rear of Tree and function returns */
/* True; otherwise, Tree is unchanged and */
/* function returns False */
bool InTree(const Item *pi, const Tree *ptree);

/* operation: remove item from front of Tree */
/* precondition: pq points to previously initialized Tree */
/* postcondition: if Tree is not empty, item at head of */
/* Tree is copied to *pitem and deleted from */
/* Tree, and function returns True; if the */
/* operation empties the Tree, the Tree is */
/* reset to empty. If the Tree is empty to */
/* begin with, Tree is unchanged and the */
/* function returns False */
bool DeleteItem(const Item *pitem, Tree *pq);

/* operation: apply a function to each item in */
/* the tree */
/* preconditions: ptree points to a tree */
/* pfun points to a function that takes*/
/* an Item argument and has no return */
/* value */
/* postcondition: the function pointed to by pfun is */
/* executed once for each item in tree */
void Traverse(const Tree *ptree, void (*pfun)(Item item));

/* operation: delete everything from a tree */
/* preconditions: ptree points to an initialized tree */
/* postconditions: tree is empty */
void DeleteAll(Tree *ptree);
#endif