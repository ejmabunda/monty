#include <stdlib.h>

#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: line number where opcode was used
 *
 * Return: this function does not return any value
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int len;
	int res;
	stack_t *top, *second;

	len = stacklen(*stack);

	/* handle short stacks */
	if (len < 2)
	{
		printf("L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	/* add top two elements */
	top = *stack;
	second = top->prev;

	res = top->n + second->n;

	/* remove top, and store result in new top */
	second->n = res;
	second->next = NULL;

	/* point to new top */
	*stack = second;
}
