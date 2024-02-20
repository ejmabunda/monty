#include <string.h>

#include "monty.h"

/**
 * rm_newline - removes the newline character from
 * a string.
 * @str: string
 *
 * Return: this function does not return any value
 */
void rm_newline(char *str)
{
	char new_str[100];
	char *temp;

	temp = str;
	while(*temp != '\n' || *temp != '\0')
	{
		if (*temp == '\n')
		{
			/* remove the newline */
			strncpy(new_str, str, strlen(str));
			new_str[strlen(new_str) - 1] = '\0';
			strcpy(str, new_str);
			break;
		}
		temp++;
	}
}
