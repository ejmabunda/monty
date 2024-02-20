#include <stdio.h>

#ifndef MONTY_H
#define MONTY_H

extern int arg;

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

void monty(FILE *fptr); /* monty interpreter */
void trim(char *str); /* remove leading and trailing whitespace */
void push(stack_t **stack, unsigned int line_number); /* add to top of stack */
void pall(stack_t **stack, unsigned int line_number); /* prints the stack */
void pint(stack_t **stack, unsigned int line_number); /* prints the top */
void pop(stack_t **stack, unsigned int line_number); /* removes the top */
void reset(stack_t **stack); /* move pointer to the top */
void swap(stack_t **stack, unsigned int line_number); /* swap the top two elements */
unsigned int stacklen(stack_t *stack); /* returns the lenght of the stack */
void add(stack_t **stack, unsigned int line_number); /* add the top two */
void nop(stack_t **stack, unsigned int line_number); /* does nothing */

#endif
