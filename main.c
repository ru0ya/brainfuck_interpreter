#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_lexer.h"
#include "brainfuck_parse.h"

int main(void)
{
	const char* brainfuckCode = ">++++[<+>-]<[->+<]>>[.>]";
	BrainfuckComm tokens[MAX_CODE_LENGTH];
	int numTokens = 0;

	tokenizeBrainfuck(brainfuckCode, tokens, &numTokens);

	printf("Tokens:\n");
	for(int i = 0; i < numTokens; i++)
	{
		printf("%d  ", tokens[i]);
		
	}

	return 0;
}



/*
>: Move the memory pointer to the right.
<: Move the memory pointer to the left.
+: Increment the value at the memory cell pointed to.
-: Decrement the value at the memory cell pointed to.
[: Start of a loop (executes code inside the loop while the current cell is not zero).
]: End of a loop (jumps back to the corresponding [ if the current cell is not zero).
,: Read one character of input into the current cell.
.: Output the character at the current cell.
*/


