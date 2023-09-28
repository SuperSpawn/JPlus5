
#ifndef OPERATORS_DEF
#define OPERATORS_DEF

#include "defs.h"
#define NUMBER_OF_OPERATORS 48

typedef enum
{
    VARIABLE_PRIORITY = 0,
    ASSIGNMENT_PRIORITY,
    MULTIPLICATION_PRIORITY
} OPERATORS_PRIORITY;

typedef struct OperatorType
{
    char *name;
    // int32_t priority;
} OperatorType;

OperatorType grammarBuffer[NUMBER_OF_OPERATORS] = {
    {"+"}, {"-"}, {"++"}, {"--"}, {"+="}, {"-="}, {"*"}, {"/"}, {"&"}, {"&&"}, {"|"}, {"||"}, {"*="}, {"/="}, {"&="}, {"|="}, {"<"}, {">"}, {">="}, {"<="}, {"<<"}, {">>"}, {"<<="}, {">>="}, {"="}, {"=="}, {"!="}, {"."}, {"->"}, {","}, {":"}, {";"}, {"ptr"}, {"int8"}, {"int16"}, {"int32"}, {"int64"}, {"float"}, {"double"}, {"array"}, {"return"}, {"func"}, {"("}, {")"}, {"{"}, {"}"}, {"["}, {"]"}};

#endif // OPERATORS_DEF