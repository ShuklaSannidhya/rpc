#include "calc.h"

#define MAXOP 100

void mathfunc(char []);
void help(void);
void hr(void);

bool h = false;

main()
{
    int i, var;
    char s[MAXOP], type;
    double v2, v1, variables[26], ans;
    
    printf("Reverse Polish Calculator (v0.1)\n");
    printf("Type help for help\n");
    ans = 0.0;
    var = 0;
    for (i = 0; i < 26; i++)
        variables[i] = 0.0;
    printf(">>> ");
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                mathfunc(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                v2 = pop();
                push(pop() - v2);
                break;
            case '/':
                v2 = pop();
                push(pop() / v2);
                break;
            case '%':
                v2 = pop();
                push(fmod(pop(), v2));
                break;
            case '?':
                v2 = pop();
                printf("%.8g\n", v2);
                push(v2);
                break;
            case '=':
                pop();
                if (islower(var))
                    push(variables[var - 'a'] = pop());
                else
                    printf("error: invalid variable name\n");
                break;
            case 'A':
                push(ans);
                break;
            case 'C':
                clear();
                break;
            case 'D':
                v2 = pop();
                push(v2);
                push(v2);
                break;
            case 'S':
                v2 = pop();
                v1 = pop();
                push(v2);
                push(v1);
                break;
            case '\n':
                if (h) {
                    h = false;
                    printf(">>> ");
                    break;
                }
                ans = pop();
                printf("\t%.8g\n", ans);
                printf(">>> ");
                break;
            default:
                if (islower(type))
                    push(variables[type - 'a']);
                else
                    printf("error: unknown command %c\n", type);
                break;
        }
        var = type;
    }
    printf("Exiting...");
    hr();
    return 0;
}

void mathfunc(char s[])
{
    double v2;
    
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "tan") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        v2 = pop();
        push(pow(pop(), v2));
    } else if (strcmp(s, "help") == 0)
        help();
    else
        printf("error: %s not supported\n", s);
}

void help(void)
{
    h = true;
    printf("In reverse Polish notation, each operator follows its operands.\n");
    printf("Examples:\n");
    printf("An infix expression like\n");
    printf("\t(1 - 2) * (4 + 5)\n");
    printf("is entered as\n");
    printf("\t1 2 - 4 5 + *");
    hr();
    printf("Supported operations and functions are:\n");
    printf("\t+ - / * %%(mod)");
    printf(" sin cos tan");
    printf(" pow exp");
    hr();
    printf("Variables\n");
    printf("To assign a value to a variable use this syntax:\n");
    printf("\t<value> <variable> =\n");
    printf("Example:\n");
    printf("\tx 5 =\n");
    printf("this assigns 5 to x\n");
    printf("NOTE: Variables can only be single lower-case letters.");
    hr();
    printf("Shortcuts:\n");
    printf("\tA\tLast Result\n");
    printf("\tC\tClear the stack\n");
    printf("\tD\tDuplicate the last operator\n");
    printf("\tS\tSwap the last two operators\n");
    printf("\t?\tPop the current operator");
    hr();
}
void hr(void)
{
    printf("\n-------------------------------------------------------------\n");
}
