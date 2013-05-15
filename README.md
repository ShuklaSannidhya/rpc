rpc
===
Reverse Polish Calculator (written in C)

How to compile
---

Compiling it using GCC:

    cc main.c getop.c stack.c -lm
    
**NOTE-** Don't forget the `-lm` flag, it is important.

How to use
---

In reverse Polish notation, each operator follows its operands.
_Examples:_
An infix expression like
	(1 - 2) * (4 + 5)
is entered as
	1 2 - 4 5 + *

-------------------------------------------------------------

Supported operations and functions are:
	+ - / * %(mod) sin cos tan pow exp

-------------------------------------------------------------

**Variables**
To assign a value to a variable use this syntax:
	<value> <variable> =
_Example:_
	x 5 =
this assigns 5 to x
NOTE: Variables can only be single lower-case letters.

-------------------------------------------------------------

**Shortcuts:**

	A	Last Result
	C	Clear the stack
	D	Duplicate the last operator
	S	Swap the last two operators
	?	Pop the current operator

-------------------------------------------------------------

