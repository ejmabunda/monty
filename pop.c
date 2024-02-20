#include <stdlib.h>

#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: line number where the opcode was used
 *
 * Return: this function does not return any value
 */
void pop(stack_t **stack, unsigned int line_number)
{
	/* handle empty stack */
	if (*stack == NULL)
	{
		printf("L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* handle stack with one element */
	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		(*stack) = NULL;
		exit(EXIT_SUCCESS);
	}
	
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
}
