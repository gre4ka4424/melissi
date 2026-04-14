#include <stdio.h>
#include "melstr.h"

int STR_FindLength (char *text)
{
	int index = 0;
	while (*text != '\0')
	{
		index++;
		text++;
	}
	return index;		
}

char *STR_FindCharacter (char *text, char character)
{
	while (*text != '\0')
	{
		if (*text == character)
		{
			return text;
		}
		text++;
	}
	return NULL;
}

char *STR_SkipCharacters (char *text, char character)
{
	while (*text != '\0')
	{
		if (*text != character)
			return text;
		}
		text++;
	}
	return NULL;
}

int STR_HasCharacter (char *text, char character)
{
	while (*text != '\0')
	{
		if (*text == character)
		{
			return 1;
		}
		text++;
	}
	return 0;
}

int STR_CountCharacters (char *text, char character)
{
	int counter = 0;
	while (*text != '\0')
	{
		if (*text == character)
		{
			counter++;
		}
		text++;
	}
	return counter;
}

char *STR_GoToNextWord (char *text)
{
	text = STR_FindCharacter(text, ' ');
	text = STR_SkipCharacters(text, ' ');
	return text;
}

int STR_CountWords (char *text)
{
	int counter = 0;
	while (STR_GoToNextWord != NULL)
	{
		counter++;
	}
	return counter;
}

int STR_CopyAB (char *textA, char *textB)
{
	int textLengthA = STR_FindLength(textA);
	int textLengthB = STR_FindLength(textB);
	if (textLengthB < textLengthA)
	{
		return -1;
	}
	while (*textA != '\0')
	{
		*textB = *textA;
		textA++;
		textB++;
	}
	return 0;
}

int STR_AreEqual (char *textA, char *textB)
{
	while (1)
	{
		if (*textA == *textB)
		{
			if (*textA == '\0')
			{
				return 1;
			}
			textA++;
			textB++;
		}
		else
		{
			return 0;
		}
	}
}

int STR_AreEqualFor (char *textA, char *textB, int range)
{
	if (range <= 0)
	{
		return -1;
	}
	int equal = 0;
	while (1)
	{
		if ((*textA != '\0') && (textB != '\0'))
		{
			return 0;
		}
		if (*textA != *textB)
		{
			return 0;
		}
		if (equal == range)
		{
			
		}
		textA++;
		textB++;
		equal++;
	}
}

int MegaPrint(char *)