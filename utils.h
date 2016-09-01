#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "string_stack.hpp"


void printStrStack(const StrStack& stack){

	char** buff = stack.buffer;
	for (size_t i = 0; i < stack.stackDepth; i++)
		std::cout <<i <<": " <<*(--buff) <<std::endl;


}



#endif
