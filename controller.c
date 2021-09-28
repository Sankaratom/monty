#include "monty.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
* fswitch - switches between functions and pass in the parameters
* @cmd: command
* Return: 
*/
int fswitch(char *cmd, ...)
{
int a, b, c;
va_list args;
va_start(args, cmd);
char *cmds[] = {"push","pa", "pop", "add", "swap", "sub", "nop", "div", "mul", "mod"};
printf("reached\n");
if (cmd == cmds[0])
{
stack_t *new = va_arg(args, stack_t *);
a = va_arg(args, int);
push(&new, a);
va_end(args);
}
return EXIT_SUCCESS;
}
