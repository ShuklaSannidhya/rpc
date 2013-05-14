#include "calc.h"

int getop(char s[])
{
    int i, c;
    static int lastc = 0;
    
    c = lastc ? lastc : getchar();
    lastc = 0;
    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = getchar()))
            ;
        s[i] = '\0';
        if (c != EOF)
            lastc = c;
        if (strlen(s) > 1)
            return NAME;
        return s[0];
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.' )
            s[++i] = c;
        else {
            if (c != EOF)
                lastc = c;
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastc = c;
    return NUMBER;
}
