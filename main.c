#include "monty.h"
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
char line[256], *delim = " ", *fname, *par;
int ln = 1;
stack_t *head = NULL;
while (fgets(line, 256, file))
{
fname = strtok(line, delim);
if (fname[strlen(fname) - 1] == '\n')
    fname [strlen(fname) - 1] = '\0';
if (!strcmp("push", fname))
{
par = strtok(NULL, line);
if (par != NULL)
    par[strlen(par) - 1] = '\0';
else
    par = NULL;
push(&head, par, ln);
}
if (!strcmp("pall", fname))
    pall(&head, ln);
if (!strcmp("pop", fname))
    pop(&head, ln);
if (!strcmp("swap", fname))
    swap(&head, ln);
ln++;
}
fclose(file), free(fname), free(delim);
}
