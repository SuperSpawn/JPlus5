#include "defs.h"
#include "state.h"
#include "ParseList.h"
#include "FileRead.h"
#include "AST.h"

void print_entire_tree(AST *tree, int level)
{
    int i;
    if (tree == NULL)
        return;
    print_entire_tree(tree->right, level + 1);
    for (i = 0; i < level; ++i)
        putchar('\t');
    printf("%d\n", tree->data);
    print_entire_tree(tree->left, level + 1);
}

int main(int argc, char **argv)
{
    State *states = NULL;
    ParseList list;
    uint32_t numberOfStates;
    FILE *file = NULL;
    int i, input, state = 0;

    list.root = list.end = NULL;

    file = fopen("input.txt", "r");
    if (file == NULL)
        goto KILL_PROC;

    states = init_state_machine(&numberOfStates);
    if (states == NULL)
        goto KILL_PROC;

    if (file_read(file, &list, states))
        goto KILL_PROC;

    ParseList_print(&list);
    AST *ast = AST_build(list.root, list.end);
    if (ast == NULL)
    {
        printf("Error building AST\n");
        goto KILL_PROC;
    }

    print_entire_tree(ast, 0);

    printf("done\n");
    free(states);
    fclose(file);
    ParseList_destroy(&list);
    AST_destroy(ast);

    return 0;
KILL_PROC:
    if (states)
        free(states);
    if (file)
        fclose(file);
    ParseList_destroy(&list);
    printf("Error\n");
    return 1;
}
