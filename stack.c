#include <stdio.h>

#define MAXSTACK 100

static int sp = 0;
static double valstack[MAXSTACK];

void push(double f)
{
    if (sp < MAXSTACK)
        valstack[sp++] = f;
    else
        printf("error: stack-overflow, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return valstack[--sp];
    else
        printf("error: stack empty\n");
        return 0.0;
}

void clear(void)
{
    sp = 0;
}
