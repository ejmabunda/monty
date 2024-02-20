#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "monty.h"

int arg = 0;

/**
 * main - entry point, starts the monty intepreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	
	if (argc != 2) /* wrong number of arguments */
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* try to open the file */
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty(fptr);

	/* clean up */
	fclose(fptr);

	return (0);
}

/**
 * monty - monty bytcode interpreter
 * @fptr; points to the file to interpret
 *
 * Return: this function does not return any value
 */
void monty(FILE *fptr)
{
	char line[1000]; /* line read from file */
	char *token;
	int line_number;
	instruction_t ins; /* instruction */
	stack_t *top;

	/* read lines */
	line_number = 1;
	top = NULL;
	while (fgets(line, 100, fptr) != NULL)
	{
		/* get opcode */
		token = strtok(line, " ");
		trim(token);
		ins.opcode = token;

		/* link opcode's function */
		if (strcmp(ins.opcode, "push") == 0)
		{
			ins.f = push;
		}
		else if (strcmp(ins.opcode, "pall") == 0)
		{
			ins.f = pall;
		}
		else if (strcmp(ins.opcode, "pint") == 0)
		{
			ins.f = pint;
		}
		else if (strcmp(ins.opcode, "pop") == 0)
		{
			ins.f = pop;
		}
		else if (strcmp(ins.opcode, "swap") == 0)
		{
			ins.f = swap;
		}
		else if (strcmp(ins.opcode, "add") == 0)
		{
			ins.f = add;
		}
		else if (strcmp(ins.opcode, "nop") == 0)
		{
			ins.f = nop;
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, ins.opcode);
			exit(EXIT_FAILURE);
		}

		/* get opcode argument */
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			trim(token);
			arg = atoi(token);
		}

		ins.f(&top, line_number);
		line_number++;
	}
}
