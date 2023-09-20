#include "main.h"

/**
 * parseCommand - takes a cmd str and parse it into
 * a array of args
 * @command: a ptr
 * @arguments: a ptr to a ptr
 *
 * Return: num of args
 */

int parseCommand(char* command, char** arguments)
{
	int argc = 0;
	char *token = strtok(command, " \t\n");

	while (token != NULL)
	{
		arguments[argc++] = token;
		token = strtok(NULL, " \t\n");
		if (argc >= MAX_ARGUMENTS)
		{
			fprintf(stderr, "Too many arguments\n");
			break;
		}
	}
	arguments[argc] = NULL;

	return (argc);
}
