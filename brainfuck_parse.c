#include <stdio.h>
#include <stdlib.h>
#include "brainfuck_parse.h"
#include "brainfuck_lexer.h"


void parseBrainfuck(const char* code)
{
	unsigned char memory[MEMSIZE] = {0}; //initialize memory with zero
	unsigned char *ptr = memory; //pointer to current memory cell
	int loop_stack[MEMSIZE] = {0};  // stack to handle loop
	int stack_pointer = -1; // helps to keep track of current pointer
	char command; // holds current command


	 while (command = *code) {
		switch (command) {
			case INC_PTR:
				ptr++;
				break;
			case DEC_PTR:
				ptr--;
				break;
			case INC_VAL:
				(*ptr)++;
				break;
			case DEC_VAL:
				(*ptr)--;
				break;
			case OUTPUT:
				putchar(*ptr);
				break;
			case INPUT:
				*ptr = getchar();
				break;
			case LOOP_START:
				loop_stack[++stack_pointer] = command;
				break;
			case LOOP_END:
				if (*ptr != 0) {
					command = loop_stack[stack_pointer--];
				} else {
					stack_pointer--;
				}
				break;
			default:
				fprintf(stderr, "Error: Unknown command encountered.\n");
				exit(EXIT_FAILURE);
				break;
		}
		code++;
	}
}
