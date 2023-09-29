
#ifndef OPERATORS_DEF
#define OPERATORS_DEF

#include "defs.h"

#define NUMBER_OF_OPERATORS 48
#define OPEN_PARENTHESIS_INDEX 46
#define CLOSE_PARENTHESIS_INDEX 47

typedef enum
{
    SEMICOLON_PRIORITY = 0,
    VARIABLE_PRIORITY,
    TYPE_PRIORITY,
    ACCESS_PRIORITY,
    UNARY_PRIORITY,
    ASSIGNMENT_PRIORITY,
    MULTIPLICATION_PRIORITY,
    BITWISE_PRIORITY,
    ADDITION_PRIORITY,
    LOGICAL_PRIORITY,
    COMPARISON_PRIORITY,
    RETURN_PRIORITY
} OPERATORS_PRIORITY;

typedef struct OperatorType
{
    char *name;
    int32_t priority;
    int32_t left, right; // options for children
} OperatorType;

OperatorType grammarBuffer[NUMBER_OF_OPERATORS] = {
    {
        "+",
        ADDITION_PRIORITY,
    },
    {"-", ADDITION_PRIORITY},
    {"++", UNARY_PRIORITY},
    {"--", UNARY_PRIORITY},
    {"+=", ASSIGNMENT_PRIORITY},
    {"-=", ASSIGNMENT_PRIORITY},
    {"*", MULTIPLICATION_PRIORITY},
    {"/", MULTIPLICATION_PRIORITY},
    {"&", BITWISE_PRIORITY},
    {"&&", LOGICAL_PRIORITY},
    {"|", BITWISE_PRIORITY},
    {"||", LOGICAL_PRIORITY},
    {"*=", ASSIGNMENT_PRIORITY},
    {"/=", ASSIGNMENT_PRIORITY},
    {"&=", ASSIGNMENT_PRIORITY},
    {"|=", ASSIGNMENT_PRIORITY},
    {"<", COMPARISON_PRIORITY},
    {">", COMPARISON_PRIORITY},
    {">=", COMPARISON_PRIORITY},
    {"<=", COMPARISON_PRIORITY},
    {"<<", BITWISE_PRIORITY},
    {">>", BITWISE_PRIORITY},
    {"<<=", ASSIGNMENT_PRIORITY},
    {">>=", ASSIGNMENT_PRIORITY},
    {"=", ASSIGNMENT_PRIORITY},
    {"==", COMPARISON_PRIORITY},
    {"!=", COMPARISON_PRIORITY},
    {".", ACCESS_PRIORITY},
    {"->", ACCESS_PRIORITY},
    {",", 0},
    {":", 0},
    {";", SEMICOLON_PRIORITY},
    {"ptr", TYPE_PRIORITY},
    {"int8", TYPE_PRIORITY},
    {"int16", TYPE_PRIORITY},
    {"int32", TYPE_PRIORITY},
    {"int64", TYPE_PRIORITY},
    {"float", TYPE_PRIORITY},
    {"double", TYPE_PRIORITY},
    {"array", TYPE_PRIORITY},
    {"return", RETURN_PRIORITY},
    {"func", 0},
    {"{", 0},
    {"}", 0},
    {"[", 0},
    {"]", 0},
    {"(", 0},
    {")", 0}};

#endif // OPERATORS_DEF