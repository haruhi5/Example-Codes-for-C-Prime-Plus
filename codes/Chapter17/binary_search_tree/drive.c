#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree *pt);
void dropitem(Tree *pt);
void showitem(const Tree *pt);
void finditem(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main(void)
{
    Tree pets;
    char choice;

    InitializeTree(&pets);

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            addpet(&pets);
            break;
        case 'l':
            showitem(&pets);
            break;
        case 'f':
            finditem(&pets);
            break;
        case 'n':
            printf("%d items in tree.\n", TreeItemCount(&pets));
            break;
        case 'd':
            dropitem(&pets);
            break;
        default:
            puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.\n");
    return 0;
}

char menu(void)
{
    int ch;
    puts("Enter menu choice:");
    puts("a) add item       l) show list of items");
    puts("n) number of item f) find item");
    puts("d) delete item    q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter a l, r, f, n, d or q:");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;
    puts("Please enter the name of item: ");
    s_gets(temp.name, SLEN);
    puts("Please enter the kind of item: ");
    s_gets(temp.kind, SLEN);
    uppercase(temp.name);
    uppercase(temp.kind);
    AddItem(&temp, pt);
}

void showitem(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Name: %-19s  Kind: %-19s\n", item.name, item.kind);
}

void finditem(const Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of item you wish to drop: ");
    s_gets(temp.name, SLEN);
    puts("Please enter item kind: ");
    s_gets(temp.kind, SLEN);
    uppercase(temp.name);
    uppercase(temp.kind);
    printf("%s the %s ", temp.name, temp.kind);
    if (InTree(&temp, pt))
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

void dropitem(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of item you wish to find: ");
    s_gets(temp.name, SLEN);
    puts("Please enter item kind: ");
    s_gets(temp.kind, SLEN);
    uppercase(temp.name);
    uppercase(temp.kind);
    printf("%s the %s ", temp.name, temp.kind);
    if (DeleteItem(&temp, pt))
        printf("is dropping from the tree.\n");
    else
        printf("is not a member.\n");
}

void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
