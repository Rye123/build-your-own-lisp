#include <stdlib.h>
#include <stdio.h>
#define START_STACK_SIZE 2

typedef struct {
	int* contents;
	int size;
	int _allocSize;
} NumStack;

typedef struct {
	char* contents;
	int size;
	int _allocSize;
} OpStack;

NumStack* numStack_new();
void numStack_push(NumStack* numStack, int value);
int numStack_pop(NumStack* numStack);
void numStack_free(NumStack* numStack);

OpStack* opStack_new();
void opStack_push(OpStack* opStack, char value);
char opStack_pop(OpStack* opStack);
void opStack_free(OpStack* opStack);