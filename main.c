#include "monty.h"
#include "controller.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ops.c"
/**
* main - our monty interpreter
* @argc : number of arguments
* @argv: list of parameters
* Return: failure or success
*/
int main(int argc, char *argv[])
{
if (argv[1] == NULL)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}
FILE *file = fopen(argv[1], "r");

if (file == NULL)
{
printf("Error: Can't open file <file>\n");
exit(EXIT_FAILURE);
}
char line[256];
char *delim = " ";
const char *cmd[10] = {"push", "pall", "pop", "add", "swap",
"sub", "nop", "div", "mul", "mod"};
char *fname, *cpush = "push\0";
int param;
stack_t *head = NULL;
while (fgets(line, 256, file))
{
fname = strtok(line, delim);
if (!strcmp(cmd[0], fname))
{
param = atoi(strtok(NULL, line));
push(&head, param);
}
if (!strcmp(cmd[1], fname))
{
pall(&head);
}
if (fname == cmd[2])
{
pop(&head);
}
}
fclose(file);
}
