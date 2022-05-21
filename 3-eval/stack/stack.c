#include "stack.h"

NumStack* numStack_new()
{
	NumStack* numStack = malloc(sizeof(NumStack));
	numStack->contents = (int*) malloc(sizeof(int) * START_STACK_SIZE);
	numStack->size = 0;
	numStack->_allocSize = START_STACK_SIZE;
    return numStack;
}

void numStack_push(NumStack* numStack, int value)
{
	int newSize = numStack->size + 1;
	if (newSize >= numStack->_allocSize) { //then double the allocSize
		int* newContents = (int*) realloc(numStack->contents, (2*numStack->_allocSize) * sizeof(int));
		numStack->contents = newContents;
	}
	*(numStack->contents + numStack->size) = value;
	numStack->size = newSize;
}

int numStack_pop(NumStack* numStack)
{
	if (numStack->size == 0) {
		fprintf(stderr, "ERROR: Stack empty.");
		return 0;
	}
	numStack->size--;
	return *(numStack->contents + numStack->size);
}

void numStack_free(NumStack* numStack)
{
    free(numStack->contents);
    free(numStack);
}


OpStack* opStack_new()
{
	OpStack* opStack = malloc(sizeof(OpStack));
	opStack->contents = (char*) malloc(sizeof(char) * START_STACK_SIZE);
	opStack->size = 0;
	opStack->_allocSize = START_STACK_SIZE;
    return opStack;
}

void opStack_push(OpStack* opStack, char value)
{
	int newSize = opStack->size + 1;
	if (newSize >= opStack->_allocSize) { //then double the allocSize
		char* newContents = (char*) realloc(opStack->contents, (2*opStack->_allocSize) * sizeof(char));
		opStack->contents = newContents;
	}
	*(opStack->contents + opStack->size) = value;
	opStack->size = newSize;
}

char opStack_pop(OpStack* opStack)
{
	if (opStack->size == 0) {
		fprintf(stderr, "ERROR: Stack empty.");
		return 0;
	}
	opStack->size--;
	return *(opStack->contents + opStack->size);
}

void opStack_free(OpStack* opStack)
{
    free(opStack->contents);
    free(opStack);
}