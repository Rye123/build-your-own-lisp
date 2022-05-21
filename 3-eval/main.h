#include "mpc/mpc.h"
#include "stack/stack.h"

#ifdef _WIN32
// Define windows-specific functions
#include <string.h>
#define BUFFER_SIZE 2048

static char buffer[BUFFER_SIZE];

// prints `prompt`, then takes an input and returns it
char* readline(char* prompt) 
{
	fputs(prompt, stdout);
	fgets(buffer, BUFFER_SIZE, stdin);
	char* input = malloc(strlen(buffer));
	strcpy(input, buffer);
	return input;
}
void add_history(char* line) 
{
	// do nothing
}

#else
// Define non-windows-specific functions
#include <editline/readline.h>
#include <editline/history.h>
#endif