#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 Always success
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char* arguments[MAX_ARGUMENTS];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		int argc = parseCommand(command, arguments);
		if (argc > 0 && strcmp(arguments[0], "exit") == 0)
		{
			break;
		}

		if (argc > 0)
		{
			executeCommand(arguments);
		}
	}

	return (0);
}
