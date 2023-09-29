#ifndef FILE_READ
#define FILE_READ

#include "defs.h"
#include "ParseList.h"
#include "state.h"
#include "operators.h"

#define VARIABLE_NAME_MAX_SIZE 1024

int char_to_digit(int c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }

    // Invalid character
    return -1;
}
int32_t new_type(int32_t type, int32_t input)
{
    if (type == 0)
    {
        switch (input)
        {
        case '$':
            return 1; // variable
        case 'B':
            return 2; // binary
        case '#':
            return 10; // decimal number
        case 'X':
            return 16; // hex number
        case '"':
            return 17; // string
        default:
            return -1; // operator
        }
    }
    return type;
}

int is_legal_input(int32_t type, int32_t input)
{
    switch (type)
    {
    case 1:
        return (input == '$') || ((input >= 'a') && (input <= 'z')) || ((input >= 'A') && (input <= 'Z')) ||
               ((input >= '0') && (input <= '9'));
    case 2:
        return (input == '0') || (input == '1') || (input == 'B');
    case 10:
        return isdigit(input) || (input == '#');
    case 16:
        return isxdigit(input) || (input == 'X');
    default:
        return 0;
    }
}
uint64_t update_value(uint64_t value, int input, int type, uint32_t length)
{
    switch (type)
    {
    case 1:
        if (input != '$')
        {
            value *= 10;
            value += input - '0';
        }
        break;
    case 2:
        if (input != 'B')
        {
            value <<= 1;
            value += input - '0';
        }
        break;
    case 10:
        if (input != '#')
        {
            value *= 10;
            value += input - '0';
        }
        break;
    case 16:
        if (input != 'X')
        {
            value <<= 4;
            value += char_to_digit(input);
        }
        break;
    default:
        return 0;
    }
    return value;
}

int get_priority(uint64_t value, int32_t type)
{
    if (type == -1) // operator
        return grammarBuffer[value].priority;
    return NAMED_PRIORITY; // numbers and variables have same priority
}

int file_read(FILE *file, ParseList *list, State *states)
{
    int32_t input, state = 0, type = 0;
    uint32_t length = 1;
    uint64_t value = 0;
    int priority;
    for (input = fgetc(file); input != EOF; input = fgetc(file))
    {
        if (isspace(input))
            continue;
        type = new_type(type, input);

        if (is_legal_input(type, input))
        {
            value = update_value(value, input, type, length);
            continue;
        }
        else
        {
            if (value)
            {
                ParseList_push(list, value, get_priority(value, type));
                type = new_type(0, input);
                if (type == -1)
                    state = states[0].inputs[input];
                value = 0;
                length = 1;
                continue;
            }
            value = 0;
            length = 1;
        }

        if (states[state].inputs[input] == 0)
        {
            if (states[state].inputs[0])
            {
                value = states[state].inputs[0] - 1;
                ParseList_push(list, value, get_priority(value, type));
                type = new_type(0, input);
                if (type == -1)
                    state = states[0].inputs[input];
                value = 0;
                length = 1;
                continue;
            }
            return -1;
        }
        state = states[state].inputs[input];
        ++length;
    }
    if (states[state].inputs[input] == 0)
    {
        if (states[state].inputs[0])
        {
            value = states[state].inputs[0] - 1;
            ParseList_push(list, value, get_priority(value, type));
            state = states[0].inputs[input];
        }
    }

    return 0;
}

#endif // FILE_READ