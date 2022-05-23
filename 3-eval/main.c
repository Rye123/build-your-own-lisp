#include "main.h"

NumStack* numStack;
OpStack* opStack;

long eval_op(char* operator, long result, long nextResult)
{
	if (!strcmp(operator, "+"))
		return result + nextResult;
	else if(!strcmp(operator, "-"))
		return result - nextResult;
	else if(!strcmp(operator, "*"))
		return result * nextResult;
	else if(!strcmp(operator, "/"))
		return result / nextResult;
	else if(!strcmp(operator, "%"))
		return result % nextResult;
	return 0;
}

long calc_mpc_result(mpc_ast_t* tree)
{
	// if number, add it to the number stack
	if (strstr(tree->tag, "number"))
		return atoi(tree->contents);
	// otherwise, if it is an expression, it is also not a number
	// first child is the opening bracket
	char* operator = tree->children[1]->contents;
	
	long result = calc_mpc_result(tree->children[2]);
	// keep looping until the next child is not an expression (i.e. closed bracket)
	int i = 3;
	while(strstr(tree->children[i]->tag, "expression")) {
		long nextResult = calc_mpc_result(tree->children[i]);
		result = eval_op(operator, result, nextResult);
		i++;
	}

	return result;
}

/*void testStack()
{
	NumStack* stack = numStack_new();
	numStack_push(stack, 5);
	numStack_push(stack, 6);
	printf("%d\n", numStack_pop(stack));
	numStack_free(stack);
}*/

int main(int argc, char** argv) 
{
	// Initialise stacks
	

	// Define Parsers
	mpc_parser_t* Number     = mpc_new("number");
	mpc_parser_t* Operator   = mpc_new("operator");
	mpc_parser_t* Expression = mpc_new("expression");
	mpc_parser_t* Lispy      = mpc_new("lispy");
	
	// Define them with a language
	mpca_lang(MPCA_LANG_DEFAULT,
		"									\
			number     : /-?[0-9]+(\\.[0-9]+)?/ ;				\
			operator   : '+' | '-' | '*' | '/' | '%' | \"add\" | \"sub\" | \"mul\" | \"div\";\
			expression : <number> | '(' <operator> <expression>+ ')' ;	\
			lispy      : /^/ <operator> <expression>+ /$/ ;			\
		",
		Number, Operator, Expression, Lispy);
	
	puts("Version 0.0.0.0.1");
	puts("Press CTRL-C to exit\n");

	while(1) {
		// Output prompt
		char* input = readline("lispy> ");

		// Get user input of max size SIZE
		if (input && *input)
			add_history(input);

		// Parse user input
		mpc_result_t r;
		
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			//mpc_ast_print(r.output);
			printf("%li\n", calc_mpc_result(r.output));
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}
			
		// Free used memory
		free(input);
	}
	
	// Free Parsers
	mpc_cleanup(4, Number, Operator, Expression, Lispy);
	
	return 0;
}
