#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
// Define windows-specific functions
#include <string.h>
#define BUFFER_SIZE 2048

static char buffer[BUFFER_SIZE];

// prints `prompt`, then takes an input and returns it
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, BUFFER_SIZE, stdin);
	char* input = malloc(sizeof buffer);
	strcpy(input, buffer);
	return input;
}
void add_history(char* line) {
	// do nothing
}

#else
// Define non-windows-specific functions
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
	puts("Version 0.0.0.0.1");
	puts("Press CTRL-C to exit\n");

	while(1) {
		// Output prompt
		char* input = readline("lispy> ");

		// Get user input of max size SIZE
		if (input && *input)
			add_history(input);

		// Echo input
		printf("Input: %s\n", input);

		// Free used memory
		free(input);
	}
	
	return 0;
}
