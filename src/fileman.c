#include <stdio.h>
#include "../hdrs/fileman.h"

int PrintFile (FILE *file)
{
	int character;
	while ((character = fgetc(file)) != EOF)
	{
		putc(character, stdout);
	}
	return 0;
}
