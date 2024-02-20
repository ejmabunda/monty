#include <stdlib.h>

#include "monty.h"

/**
 * push - adds an integer to the top of the stack
 * @stack: a stack
 * @line_number: integer
 *
 * Return: this function does not return any value
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *item; /* new entry */

	line_number = line_number; /* compiler is complaining */

	item = (stack_t *)malloc(sizeof(stack_t));
	if (item == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	item->n = arg;
	
	/* handle empty list */
	if ((*stack) == NULL)
	{
		item->next = NULL;
		item->prev = NULL;
		(*stack) = item;
		return;
	}

	(*stack)->next = item;
	item->prev = (*stack);
	item->next = NULL;
	(*stack) = item;
}
