#include <stdio.h>
#include "fileman.h"

int PrintFile (FILE *file)
{
	char character = fgetc(file);
	while (character != EOF)
	{
		character = fgetc(file);
		putc(character, stdout);
	}
	return 0;
}