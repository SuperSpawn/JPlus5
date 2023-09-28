
#ifndef PARSE_LIST_DEF
#define PARSE_LIST_DEF

#include "defs.h"

typedef struct ParseNode
{
    struct ParseNode *next;
    uint64_t data;
    uint32_t type;
} ParseNode;

typedef struct ParseList
{
    ParseNode *root, *end;
} ParseList;

void ParseList_create(ParseList *list)
{
    if (list == NULL)
        return;
    list->root = list->end = NULL;
}
int ParseList_push(ParseList *list, uint64_t data, uint32_t type)
{
    if (list == NULL)
        return 0;
    ParseNode *node = (ParseNode *)malloc(sizeof(ParseNode));
    if (node == NULL)
        return 1;
    node->data = data;
    node->type = type;
    node->next = NULL;
    if (list->root == NULL)
    {
        list->root = node;
        list->end = node;
    }
    else
    {
        list->end->next = node;
        list->end = node;
    }
    return 0;
}
void ParseList_print(ParseList *list)
{
    ParseNode *itr;
    if (list == NULL)
        return;
    for (itr = list->root; itr != NULL; itr = itr->next)
    {
        printf("(%ld, %ld)-> ", itr->type, itr->data);
    }
}
void ParseList_destroy(ParseList *list)
{
    ParseNode *itr, *help = NULL;
    if (list == NULL)
        return;
    for (itr = list->root; itr != NULL; itr = itr->next)
    {
        if (help)
            free(help);
        help = itr;
    }
}

#endif // PARSE_LIST_DEF
