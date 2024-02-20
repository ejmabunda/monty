#include <stdio.h>
#include <ctype.h>

void trim(char *str)
{
	char *dest;
	int in_word;

	dest = str;
	in_word = 0; /* to track if we're inside a word */

	/* iterate through string */
	while (*str)
	{
		if (!isspace(*str))
		{
			*dest++ = *str;
			in_word = 1; /* we're inside a word */
		} else if (in_word)
		{
			*dest = '\0';
			break;
		}
		str++; /* move to next character */
	}
}
