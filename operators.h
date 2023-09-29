
#ifndef OPERATORS_DEF
#define OPERATORS_DEF

#include "defs.h"

#define NUMBER_OF_OPERATORS 57
#define OPEN_PARENTHESIS_INDEX 45
#define CLOSE_PARENTHESIS_INDEX 46

typedef enum
{
    FUNCTION_DECLARE_PRIORITY = 0,
    LBRACKET_PRIORITY,
    RBRACKET_PRIORITY,
    END_LINE_PRIORITY,
    RETURN_PRIORITY,
    EQUALITY_PRIORITY,
    LOGIC_PRIORITY,
    COMPARE_PRIORITY,
    BITWISE_PRIORITY,
    ADD_PRIORITY,
    MULL_PRIORITY,
    UNIRARY_PRIORITY,
    RPARENTH_PRIORITY,
    LPARENTH_PRIORITY,
    TYPENAME_PRIORITY,
    NAMED_PRIORITY
} OPERATORS_PRIORITY;

enum op_sons_properties
{
    BY_AMB = 0,
    BY_VALUE_EXC_VALUE,
    BY_VALUE_EXC_REFERENCE,
    BY_REFERENCE_EXC_VALUE,
    BY_REFERENCE_EXC_REFERENCE,
    BY_VALUE_EXC_ERROR,
    BY_REFERENCE_EXC_ERROR,
    BY_EXC_VALUE_ELSE_ERROR,
    BY_EXC_REFERENCE_ELSE_ERROR,
    BY_ERROR
};

enum op_codes
{
    OPT_DO_NOT_SWAP_SONS = 0b1
};

typedef struct OperatorType
{
    char *name;
    int32_t priority;
    // int32_t left, right;
} OperatorType;

OperatorType grammarBuffer[NUMBER_OF_OPERATORS] = {
    {"+", ADD_PRIORITY},
    {"-", ADD_PRIORITY},
    {"*", MULL_PRIORITY},
    {"/", MULL_PRIORITY},
    {"%", MULL_PRIORITY},
    {"+=", EQUALITY_PRIORITY},
    {"-=", EQUALITY_PRIORITY},
    {"*=", EQUALITY_PRIORITY},
    {"/=", EQUALITY_PRIORITY},
    {"%=", EQUALITY_PRIORITY},
    {"++", UNIRARY_PRIORITY},
    {"--", UNIRARY_PRIORITY},
    {"&", BITWISE_PRIORITY},
    {"|", BITWISE_PRIORITY},
    {"^", BITWISE_PRIORITY},
    {"~", BITWISE_PRIORITY},
    {"<<", MULL_PRIORITY},
    {">>", MULL_PRIORITY},
    {"&&", LOGIC_PRIORITY},
    {"||", LOGIC_PRIORITY},
    {"!", LOGIC_PRIORITY},
    {"&=", EQUALITY_PRIORITY},
    {"|=", EQUALITY_PRIORITY},
    {"^=", EQUALITY_PRIORITY},
    {"~=", EQUALITY_PRIORITY},
    {"<<=", EQUALITY_PRIORITY},
    {">>=", EQUALITY_PRIORITY},
    {"&&=", EQUALITY_PRIORITY},
    {"||=", EQUALITY_PRIORITY},
    {".", 0},
    {"->", 0},
    {"==", COMPARE_PRIORITY},
    {"!=", COMPARE_PRIORITY},
    {">", COMPARE_PRIORITY},
    {"<", COMPARE_PRIORITY},
    {">=", COMPARE_PRIORITY},
    {"<=", COMPARE_PRIORITY},
    {"return", RETURN_PRIORITY},
    {"if", 0},
    {"while", 0},
    {"if-not", 0},
    {";", END_LINE_PRIORITY},
    {":", 0},
    {"{", LBRACKET_PRIORITY},
    {"}", RBRACKET_PRIORITY},
    {"(", RPARENTH_PRIORITY},
    {")", LPARENTH_PRIORITY},
    {"func", 0},
    {",", 0},
    {"include", 0},
    {"define", 0},
    {"=", EQUALITY_PRIORITY},
    {"ptr", TYPENAME_PRIORITY},
    {"int8", TYPENAME_PRIORITY},
    {"int16", TYPENAME_PRIORITY},
    {"int32", TYPENAME_PRIORITY},
    {"int64", TYPENAME_PRIORITY}};

#endif // OPERATORS_DEF