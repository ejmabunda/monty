#include "monty.h"

/**
 * reset - resets pointer to the top of the stack
 * @stack: stack
 *
 * Return: this function does not return any value
 */
void reset(stack_t **stack)
{
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
}
