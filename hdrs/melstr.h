#ifndef MELSTR_H
#define MELSTR_H

char *STR_FindCharacter(char *text, char character);
char *STR_SkipCharacters(char *text, char character);
int STR_AreEqualFor (char *textA, char *textB, int range);
int STR_Init (char *text, int length);

#endif
