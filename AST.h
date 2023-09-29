#ifndef AST_DEF
#define AST_DEF

#include "defs.h"
#include "ParseList.h"
#include "operators.h"

typedef struct AST *ast_ptr;
typedef struct AST
{
    ast_ptr left, right;
    uint64_t data;
    uint32_t type;
} AST;

AST *AST_build(ParseNode *list_begin, ParseNode *list_end)
{
    AST *result;
    ParseNode *curr, *target = list_begin;
    int level = 0;

    if (list_begin == list_end)
        return NULL;
    for (curr = list_begin; curr != list_end; curr = curr->next)
    {
        if (curr->data == CLOSE_PARENTHESIS_INDEX) // close parenthesis
            --level;
        if ((curr->priority < target->priority) && (level == 0))
            target = curr;
        if (curr->data == OPEN_PARENTHESIS_INDEX) // open parenthesis
            ++level;
    }
    result = (AST *)malloc(sizeof(AST));
    if (result == NULL)
        return NULL;
    result->data = target->data;
    result->left = AST_build(list_begin, target);
    result->right = AST_build(target->next, list_end);
    return result;
}

void AST_destroy(AST *tree)
{
    if (tree == NULL)
        return;
    AST_destroy(tree->left);
    AST_destroy(tree->right);
    free(tree);
}

#endif // AST_DEF
