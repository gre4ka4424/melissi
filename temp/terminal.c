#include "../hdrs/melstr.h"

#define COMMAND_NAME 32
#define COMMANDS 32
#define MENU_NAME 32
#define MENUS 32
#define SUBMENUS 8
#define ARGUMENTS 8
#define ARGUMENT_NAME 32
#define ARGUMENT_BUFFER 64
#define ARGUMENT_STRING 0
#define ARGUMENT_INT 1
#define ARGUMENT_FLOAT 2
#define BUTTON_NAME 32
#define BUTTONS 8
#define MENU_DESCRIPTION 128

struct Argument
{
	char name[ARGUMENT_NAME];
	char buffer[ARGUMENT_BUFFER];
	int length;
	int type;
};

int Button
{
	char name[BUTTON_NAME];
};

struct Menu
{
	char name[MENU_NAME];
	struct Menu *parent;
	struct Argument arguments[ARGUMENTS];
	int argumentsAmount;
	struct Button buttons[BUTTONS];
	int buttonsAmount;
	char description[MENU_DESCRIPTION];
};

int ButtonsInit (struct Button buttons[])
{
	for (int index = 0; index < BUTTONS; index++)
	{
		STR_Init(buttons[index].name, BUTTON_NAME);
	}
	return 0;
}

int ArgumentsInit (struct Argument arguments[])
{
	for (int index = 0; index < 3; index++)
	{
		arguments[index].length = ARGUMENT_BUFFER;
		STR_Init(arguments[index].name, ARGUMENT_NAME);
		STR_Init(arguments[index].buffer, ARGUMENT_BUFFER);
	}
	arguments[0].type = ARGUMENT_STRING;
	arguments[1].type = ARGUMENT_INT;
	arguments[2].type = ARGUMENT_FLOAT;
	return 0;
}

struct Menu MenuInit ()
{
	struct Menu menu;
	STR_Init(menu.name, MENU_NAME);
	menu = {.argumentsAmount = ARGUMENTS, .buttonsAmount = BUTTONS};
	STR_Init(menu.description, MENU_DESCRIPTION);
	return menu;
}

int MenusInit (struct Menu menus[])
{
	struct Arguments basicArguments[3];
	ArgumentsInit(basicArguments);
	struct Argument stringArgument = basicArgunents[0];
	struct Argument intArgument = basicArguments[1];
	struct Argument floatArgument = basicArguments[2];
	int index;
	for (index = 0; index < MENUS; index++)
	{
		menus[index] = MenuInit();
		ButtonsInit(menus[index].buttons);
	}
	STR_CopyAB("Create new scenario", menus[0].name);
	STR_CopyAB("Name: @ScenarioName\nMode: @Mode (0 - empty, 1 - example)\n@Confirm\n@Return to the main menu", menu[0].description);
	menu[0].arguments[0] = stringArgument;
	STR_CopyAB("ScenarioName", menu[0].arguments[0].name);
	menu[0].arguments[1] = intArgument;
	STR_CopyAB("Gamemode", menu[0].arguments[1].name);
	STR_CopyAB("Return to the main menu.", menu[0].buttons[0].name);
	STR_CopyAB("Confirm", menu[0].buttons[1].name);
	return 0;
}

int DisplayMenu(struct Menu menu)
{
	printf("%s", menu.name);
	char *cursor = menu.description;
	while ( (*cursor != '@') || (*cursor != '\0') )
	{
		cursor++;
	}
	return 0;
}

int TerminalOutput()
{
	return 0;
}

int TerminalInput()
{
	return 0;
}

int TerminalLoop ()
{
	int condition = 1;
	while (condition)
	{
		TerminalOutput();
		TerminalInput();
	}
	return 0;
}

int TerminalInit ()
{
	TerminalLoop();
	return 0;
}
