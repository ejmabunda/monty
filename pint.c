#include <stdlib.h>

#include "monty.h"

/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: stack
 * @line_number: line number where opcode is used
 *
 * Return: this function does not return any value
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* handle empty stack */
	if ((*stack) == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
