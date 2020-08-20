#include "holberton.h"
/**
 * main - Entry point for shell
 * Return: 0 (Return value)
 */
int main(void)
{
	int status_output = 0;
	int read = 1;

	while (read)
	{
		char *command_line = NULL, **argm = NULL;
		size_t line_size = 0;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		signal(SIGINT, signal_c);
		read = getline(&command_line, &line_size, stdin);
		if (read < 0)
		{
			free(command_line);
			exit(status_output);
		}
		if (read == 1)
		{
			free(command_line);
			continue;
		}
		if (read != EOF)
		{
			command_line = _strtok(command_line, "\n");
			if (_myexit(command_line) == 0)
			{
				free(command_line);
				return (status_output);
			}
			_myenv(command_line);
			argm = splitline(command_line);
			status_output = execute_process(argm);
			free(command_line);
			free(argm);
		}
	}
	return (status_output);
}
