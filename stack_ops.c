#include "monty.h"
#include "helpers.c"
/**
*push - pushes an element to the stack
*@head: head of the structure that makes up the stack
*@n: integer to be stored in the stack
* @ln: line number
*Return - a new head to the stack
*/
stack_t *push(stack_t **head, char *n, int ln)
{
stack_t *new = malloc(sizeof(stack_t));
if (new == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (n == NULL || !isnum(n))
{
printf("L<%d>: usage: push integer\n", ln);
exit(EXIT_FAILURE);
}

new->n = atoi(n);
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
* @ln: line number
* Return: a new head to the list // a new top
*/
stack_t *pop(stack_t **head, int ln)
{
if (*head == NULL)
{
printf("L<%d>: can't pop an empty stack\n", ln);
exit(EXIT_FAILURE);
}

else
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
}

}
/**
* pall - prints all elements of the stack popping them off as it does
* @head: head of the list // top of the stack
* @ln: line number
* Return: success or failure status
*/
void pall(stack_t **head, int ln)
{
if (*head != NULL)
{
while ((*head)->next != NULL)
{
printf("%d\n", (*head)->n);
pop(head, ln);
}
printf("%d\n", (*head)->n);
pop(head, ln);
*head = NULL;
}
}
/**
* swap - prints all elements of the stack popping them off as it does
* @head: head of the list // top of the stack
* @ln: line number
* Return: success or failure status
*/
stack_t *swap(stack_t **head, int ln)
{
if (*head == NULL)
{
exit(EXIT_FAILURE);
}
if ((*head)->next == NULL)
{
printf("L<%d>: can't swap, stack too short\n", ln);
exit(EXIT_FAILURE);
}
int temp = (*head)->n;
temp = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = temp;
return (*head);
exit(EXIT_SUCCESS);
}
