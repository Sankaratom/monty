#include "monty.h"
#include <stdio.h>

/**
* isnum - checks if there is a number in a string
* @str: the string to be checked
* Return: 1 if there is | 0 if there is not
*/
int isnum(char *str)
{
int i;
for (i = 0; str[i]; i++)
{
if (isdigit(str[i]))
{
return (1);
}
}
return (0);
}
