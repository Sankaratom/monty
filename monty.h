#ifndef LIBC
#define LIBC
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#endif
#ifndef STACK_S
#define STACK_S
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
#endif

#ifndef INSTRUCTION_S
#define INSTRUCTION_S
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif

#ifndef PUSH
#define PUSH
stack_t *push(stack_t **head, char *n, int ln);
stack_t *pop(stack_t **head, int ln);
stack_t *swap(stack_t **head, int ln);
void pall(stack_t **head, int ln);
int isnum(char *str);
#endif
#ifndef FSWITCH
#define FSWITCH
int fswitch(char *cmd, ...);
#endif
