#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

typedef struct pair
{
    Trnode *parent;
    Trnode *child;
} Pair;

/* protototypes for local functions */
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

void InitializeTree(Tree *ptree) // cannot return a local variable
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsFull(const Tree *ptree)
{
    return ptree->size == MAXITEMS;
}

bool TreeIsEmpty(const Tree *ptree)
{
    return ptree->root == NULL;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node;
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;
    return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree->root != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item)) // &(root->item): address of item
    {                                         // because it point to a string
        if (root->left == NULL)
            root->left = new_node; // no return and this line is equal to return
        else                       // because all if statements
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr, "location error in AddNode() (i.e. duplication)\n");
        exit(1);
    }
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    int compl ;

    if ((compl = strcmp(i1->name, i2->name)) < 0)
        return true;
    else if (compl == 0 && strcmp(i1->kind, i2->kind) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
    int compl ;

    if ((compl = strcmp(i1->name, i2->name)) > 0)
        return true;
    else if (compl == 0 && strcmp(i1->kind, i2->kind) > 0)
        return true;
    else
        return false;
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;

    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            break;
    }
    return look;
}

static void DeleteNode(Trnode **ptr)
{ /* ? -> To modify the pointer, the code must pass the address of that pointer to the deleting function.*/
    // because you don't return the pointer back
    // go to see swap.c
    // you want to change the content in Node.left
    // so you need the address of the left
    // and left itself is also a pointer
    // so its a pointer point to the trnode pointer
    // which is Trnode **ptr
    /* ptr is address of parent member pointing to target node */
    Trnode *temp;

    if ((*ptr)->left == NULL) // got the ptr's value, which is an address
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}