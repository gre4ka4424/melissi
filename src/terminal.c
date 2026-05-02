#include "../hdrs/melstr.h"

#define BUFFER 64
#define COMMAND_NAME 32
#define COMMANDS 32
#define MENU_NAME 32
#define MENUS 32
#define SUBMENUS 8
#define ARGUMENTS 8
#define ARGUMENT_NAME 32
#define ARGUMENT_BUFFER 64
#define BUTTON_NAME 32
#define BUTTONS 8
#define MENU_DESCRIPTION 128
#define USED_OPTIONS 16


#define ARGUMENT_STRING 0
#define ARGUMENT_INT 1
#define ARGUMENT_FLOAT 2
#define OPTION_ARGUMENT 0
#define OPTION_BUTTON 1

struct Buffer
{
	char text[BUFFER];
	int length;
};

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

struct UsedOptions
{
	struct Menu *arguments[ARGUMENTS];
	struct Buttons *buttons[BUTTONS];
}

struct TerminalStatus
{
	struct Menu *currentMenu;
	struct Menu menus[MENUS];
	struct Buffer inputBuffer;
	char loop;
	struct UsedOptions usedOptions;
}

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

int GetOptionPointer(struct Argument *argument, struct Buttons *button, void *option, int type)
{
	switch (type)
	{
		case OPTION_ARGUMENT:
			argument = (struct Argument *)option;
			break;
		case OPTION_BUTTON:
			button = (struct Button *)option;
			break;
	}
	return 0;
}

int CheckOption(void *option, int optionType, char *text, struct Menu menu)
{
	STR_SkipCharactets(text, '@');
	int index = 0;
	int optionLength = 0;
	for (index; index < menu.argumentsAmount; index++)
	{
		optionLength = STR_FindLength(menu.arguments[index].name);
		if (STR_AreEqualFor(text, menu.arguments[index].name, optionLength) == 1)
		{
			*option = &menu.arguments[index].name;
			*optionType = OPTION_ARGUMENT;
			return 0;
		}
	}
	index = 0;
	for (index; index < buttonsAmount; index++)
	{
		optionLength = STR_FindLength(menu.buttons[index].name);
		if (STR_AreEqualFor(text, menu.buttons[index].name, optionLength) == 1)
		{
			*option = &menu.buttons[index];
			*optionType = OPTION_BUTTON;
			return 0;
		}
	}
	return -1;
}

int DisplayArgument (struct Argument argument)
{
	
	printf("\"%s\"", argument.buffer);
	switch (argument.type)
		case ARGUMENT_STRING:
			printf("(string)");
			break;
		case ARGUMENT_INT:
			printf("(integer)");
			break;
		case ARGUMENT_FLOAT:
			printf("(float)");
			break;
	return 0;
}

int DisplayButton (struct Button button)
{
	printf("%s", button.name);
	return 0;
}

int DisplayOption (void *option, int optoonType)
{
	switch (optionType)
	{
		case OPTION_ARGUMENT:
			DisplayArgument( *(struct Argument *)option );
			break;
		case OPTION_BUTTON:
			DisplayButton( *(struct Button *)option);
			break;
	}
	return 0;
}

int DisplayMenu(struct Menu menu, struct UsedMenus usedMenus)
{
	printf("%s\n", menu.name);
	char *cursor = menu.description;
	int optionCounter = 0;
	while (*cursor != '\0')
	{
		if (*cursor == '@')
		{
			if (*(cursor + 1) == '@')
			{
				putchar('@');
				cursor = cursor + 2;
				continue;
			}
			printf("%d. ", optionCounter);
			void *option;
			int optionType;
			if (CheckOption(&option, &optionType, cursor, menu) == -1)
			{
				continue;
			}
			usedOptions.
			DisplayOption(option, optionType);
			optionCounter++;
		}
		putchar(*cursor);
		cursor++;
	}
	return 0;
}

int TerminalOutput (struct Menu menu, void *usedMenus[])
{
	DisplayMenu(menu, usedMenus[]);
	return 0;
}

int GetInput (struct Buffer buffer)
{
	fgets(buffer.text, buffer.length, stdin);
	char *newline = STR_FindCharacter(buffer.text, '\0');
	if (newline == NULL)
	{
		while ( getchar() != '\n' ) {}
	}
	else
	{
		*newline = '\0';
	}
	return 0;
}

int TerminalInput(struct Buffer buffer)
{
	printf("-> ");
	GetInput(buffer);
	return 0;
}

int TerminalProcess ()
{
	return 0;
}

int TerminalLoop (struct TerminalStatus terminalStatus)
{
	while (terminalStatus.loop)
	{
		TerminalOutput(*terminalStatus.currentMenu);
		TerminalInput(terminalStatus.inputBuffer);
		TerminalProcess();
	}
	return 0;
}

int TerminalInit ()
{
	struct TerminalStatus terminalStatus;
	MenusInit(terminalStatus.menus);
	terminalStatus.currentMenu = &terminalStatus.menus[0];
	terminalStatus.inputBuffer.length = BUFFER;
	STR_Init(terminalStatus.inputBuffer.text, terminalStatus.imputBuffer.length);
	TerminalLoop(terminalStatus);
	return 0;
}
