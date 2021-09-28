#include "monty.h"
#include "controller.c"
#include <stdio.h>
#include "stack_ops.c"
int main(){
stack_t *head;
head = NULL;
push(&head, 5);
push(&head, 6);
push(&head, 7);
push(&head, 8);
pall(&head);
}