#include <stdlib.h>

#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: line number where opcode was used
 *
 * Return: this function does not return any value
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second, *third;
	unsigned int len;

	top = *stack;
	second = top->prev;
	
	/* get stack length */
	len = stacklen(top);

	/* handle short stack */
	if (len < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
	}
	else if (len == 2)
	{
		/* move top to first position */
		top->next = top->prev;
		top->prev = NULL;

		/* move first to top */
		second->next = NULL;
		second->prev = top;

		/* move stack pointer to new top */
		*stack = second;
	}
	else
	{
		/* store pointer to third element */
		third = second->prev;

		/* move top to second */
		third->next = top;
		top->prev = third;

		/* move second to top */
		top->next = second;
		second->prev = top;
		second->next = NULL;

		/* move stack pointer to new top */
		*stack = second;
	}
}
