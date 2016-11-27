#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "string_stack.hpp"


void printStrStack(const StrStack& stack){

	char** buff = stack.buffer;
	size_t sd = stack.stackDepth;
	

	int num = 0;

	while (buff-- > stack.stackHead)
		std::cout <<num++ <<": " <<*(buff) <<std::endl;
	
}



#endif
