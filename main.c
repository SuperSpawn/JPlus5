#include "defs.h"
#include "state.h"
#include "ParseList.h"
#include "FileRead.h"

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

    printf("done\n");
    free(states);
    fclose(file);
    ParseList_destroy(&list);
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
