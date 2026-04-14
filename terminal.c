#include "melstr.h"

#define COMMAND_NAME 32
#define COMMANDS 32
#define MENU_NAME 32
#define MENUS 32
#define SUBMENUS 8

struct Menu
{
	char name[MENU_NAME];
	struct Menu *parent;
	struct Menu *submenus[SUBMENUS];
}

int MenusInit (struct Menu menus[])
{
	
	
}

int TerminalInit ()
{
	
	return 0;
}