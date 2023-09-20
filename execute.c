#include "main.h"

/**
 * executeCommand - takes an array of args and executes the
 * command specified bu=y the first arg
 * @args: a ptr 2 a ptr
 *
 * Return: void
 */

void executeCommand(char** arguments)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execvp(arguments[0], arguments);
		fprintf(stderr, "Command not found\n");
		exit(1);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "Fork failed\n");
		exit(1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
