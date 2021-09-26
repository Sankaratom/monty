#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
*push - pushes an element to the stack
*@head: head of the structure that makes up the stack
*@n: integer to be stored in the stack
*Return - a new head to the stack
*/
stack_t *push(stack_t **head, int n)
{
stack_t *new = malloc(sizeof(stack_t));
if (new == NULL)
{
EXIT_FAILURE;
}
new->n = n;
new->next = NULL;
new->prev = NULL;
if (*head != NULL)
{
new->next = *head, (*head)->prev = new;
}
*head = new;
return (*head);
}
/**
* pop - removes the top element of the stack
* @head: head of the list // top of the stack
* Return: a new head to the list // a new top
*/
stack_t *pop(stack_t **head)
{
if (*head != NULL)
{
if ((*head)->next == NULL)
{
free(*head);
return (EXIT_SUCCESS);
}
*head = (*head)->next;
free((*head)->prev);
(*head)->prev = NULL;
return (*head);
EXIT_FAILURE;
return (NULL);
}
else
{
printf("Stack is empty");
return (NULL);
}
}
/**
* pall - prints all elements of the stack popping them off as it does
* @head: head of the list // top of the stack
* Return: success or failure status
*/
size_t pall(stack_t **head)
{
if (*head != NULL)
{
while ((*head)->next != NULL)
{
printf("%d\n", (*head)->n);
pop(head);
}
printf("%d\n", (*head)->n);
pop(head);
exit(EXIT_SUCCESS);
}
else
{
exit(EXIT_FAILURE);
}
}
