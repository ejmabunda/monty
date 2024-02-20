#include <stdlib.h>

#include "monty.h"

/**
 * stacklen - counts the number of elements in a stack
 * @stack: the stack
 *
 * Return: lenght of the stack
 */
unsigned int stacklen(stack_t *stack)
{
	unsigned int len;

	len = 0;
	
	/* handle empty stack */
	if (stack == NULL)
		return (len);

	while (stack->prev != NULL)
	{
		stack = stack->prev;
		len++;
	}
	
	return (len + 1);
}
