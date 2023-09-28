
#ifndef STATE_DEF
#define STATE_DEF

#include "defs.h"
#include "operators.h"

#define MAX_STATES 200

typedef struct State
{
    uint16_t inputs[UCHAR_MAX];
} State;

int add_word(State *states, char *word, uint32_t *numberOfStates, int32_t id)
{
    uint32_t i, state = 0;
    for (i = 0; word[i]; ++i)
    {
        if (states[state].inputs[word[i]] == 0)
        {
            states[state].inputs[word[i]] = (*numberOfStates)++;
        }
        state = states[state].inputs[word[i]];
    }
    states[state].inputs[0] = id;
    return 0;
}
int search_word(State *states, char *sentence)
{
    uint32_t i, state = 0;
    for (i = 0; sentence[i]; ++i)
    {
        if (states[state].inputs[sentence[i]] == 0)
            return -1;
        state = states[state].inputs[sentence[i]];
    }
    return states[state].inputs[0];
}
int parse_exp(State *states, char *sentence)
{
    uint32_t i, state = 0;
    for (i = 0; sentence[i]; ++i)
    {
        if (states[state].inputs[sentence[i]] == 0)
        {
            if (states[state].inputs[0])
            {
                printf("%d\n", states[state].inputs[0]);
                state = states[0].inputs[sentence[i]];
                continue;
            }
            return -1;
        }
        if (isspace(sentence[i]))
            continue;
        state = states[state].inputs[sentence[i]];
    }
    return 0;
}

State *init_state_machine(uint32_t *numberOfStates)
{
    State *states;
    int i;
    *numberOfStates = 1;
    states = malloc(sizeof(State) * MAX_STATES);
    if (states == NULL)
        return NULL;
    memset(states, 0, sizeof(State) * MAX_STATES);

    for (i = 0; i < NUMBER_OF_OPERATORS; ++i)
    {
        add_word(states, grammarBuffer[i].name, numberOfStates, i + 1);
    }
    return states;
}

#endif