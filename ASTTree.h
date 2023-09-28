#ifndef ASTTREE_DEF
#define ASTTREE_DEF

#include "defs.h"

typedef struct AST
{
    AST *left, *right;
    char *word;
} AST;

#endif // ASTTREE_DEF
