#include <iostream> // std::cin, std::cout, std::endl
#include <string.h> // strcmp()


// my implementation of a c-string stack
#include "string_stack.hpp"


int main(){

	// string stack object
	StrStack stack;

	// this string will hold our command
	char command[256];

	// limit the size of the user input to prevent a buffer-overflow [attack].
	std::cin.width(255);

	
	for (;;) {

		// prompt the user for a command
		std::cout <<"\x1b[1mSTACK -> \x1b[5m% \x1b[0m";
		std::cin >>command;
		


		// delete the top element off of the stack
		if (strcmp(command, "pop") == 0)
			stack.pop();



		// print the top element of the stack
		else if (strcmp(command, "top") == 0) {
			char* top = stack.top();
			
			
			if (top == NULL)
				std::cout <<"The stack is Empty...\n";
			else
				std::cout <<top <<std::endl;


		} else if (strcmp(command, "size") == 0) {
			
			std::cout <<stack.stackDepth <<std::endl;
		// add a string to the stack
		} else if (strcmp(command, "push") == 0) {
			char value[256];
			std::cin.getline(value, 255);
			stack.push(value + 1); // first char is a space

		// reset everything
		} else if (strcmp(command, "reset") == 0)
			stack.clear();
		
		// change the top element
		else if (strcmp(command, "chtop") == 0)
			if (stack.top()) {
				char value[256];
				std::cin.getline(value, 255);
				stack.changeTop(value + 1); // first char is a space
			} else
				std::cout <<"The stack is Empty...\n";

		else if (strcmp(command, "at") == 0) {
			ssize_t index;
			std::cin >>index;
			try {
				std::cout <<stack[index] <<std::endl;
			} catch (const char* err) {
				std::cout <<"\a\x1b[31;1mError:\x1b[0m\x1B[1m index of [" <<index <<"] is out of bounds\x1b[0m\n";
			}
		// show the contents of the stack
		} else if (strcmp(command, "list") == 0 || strcmp(command, "ls") == 0)
			StrStack::printStrStack(stack);

		// quit the program
		else if (*command == 'q' || strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
			return 0;
			
		// user is a dumbass (should be assumed at this point...)
		else
			std::cerr <<"\aCommand `" <<command <<"` not found..." <<"accepted commands:"
						" top, size, pop, push, at, reset, chtop, ls/list, exit/q/quit" <<std::endl;
		
		std::cout <<"Size: " <<stack.stackDepth <<std::endl <<"sizeFactor: " <<(int) stack.sizeFactor
				  <<"\nspaces allocated: " <<((1U <<stack.sizeFactor) * 256) <<std::endl;


	}

}
