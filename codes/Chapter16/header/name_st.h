#include <string.h>
#ifndef NAMES_H_
#define NAMES_H_
#define SLEN 32

struct name_st
{
    char first[SLEN];
    char last[SLEN];
};

typedef struct name_st names;

void get_names(names *);
void show_names(const names *);
char *s_gets(char *st, int n);
#endif