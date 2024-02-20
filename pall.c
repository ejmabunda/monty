#include <stdlib.h>

#include "monty.h"

/**
 * pall - prints all the values on the stack
 * starting from the top
 * @stack: stack to print from
 *
 * Return: this function does not return any value
 */
void pall(stack_t **stack, unsigned int line_number)
{
	line_number = line_number; /* I have to use the variable */
	
	/* handle empty stack */
	if ((*stack) == NULL)
		exit(EXIT_SUCCESS);

	while ((*stack)->prev != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->prev;
	}

	/* print remaining value */
	printf("%d\n", (*stack)->n);

	/* move pointer back to the top of the stack */
	reset(stack);
}
