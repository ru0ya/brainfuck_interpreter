#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_parse.h"
#include "brainfuck_lexer.h"


void parseBrainfuck(const char* code, BrainfuckComm tokens[], int numTokens)
{
	unsigned char memory[MEMSIZE] = {0}; //initialize memory with zero
	unsigned char *ptr = memory; //pointer to current memory cell
	int loop_stack[MEMSIZE] = {0};  // 
	int stack_pointer = -1; // helps to keep track of current pointer


	 for (int i = 0; i < numTokens; ++i) {
		switch (tokens[i]) {
			case INC_PTR:
				ptr++;
				break;
			case DEC_PTR:
				ptr--;
				break;
			case INC_VAL:
				*ptr = *ptr + 1;
				break;
			case DEC_VAL:
				*ptr = *ptr - 1;
				break;
			case OUTPUT:
				putchar(*ptr);
				break;
			case INPUT:
				*ptr = getchar();
				break;
			case LOOP_START:
				loop_stack[++stack_pointer] = i;
				break;
			case LOOP_END:
				if (*ptr != 0) {
					i = loop_stack[stack_pointer--];
				} else {
					stack_pointer--;
				}
				break;
			case INVALID_COMMAND:
				fprintf(stderr, "Error: Unknown command encountered.\n");
				exit(EXIT_FAILURE);
				break;

			default:
				break;
		}
	}
}
