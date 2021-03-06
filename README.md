# stack-demo
A small program to be used as an educational tool to teach about the stack and how it works.

## To build [![Build Status](https://travis-ci.org/dvtate/stack-demo.svg?branch=master)](https://travis-ci.org/dvtate/stack-demo)
```
 stack-demo $ g++ *.cpp -o stack # compile
 stack-demo $ ./stack # run
```

## Commands:
- `push [text]`: pushes `[text]` onto the top of the stack
- `pop`: deletes the top element of the stack
- `size`: tells the current size of the stack
- `reset`: deletes all elements of the stack
- `chtop [text]`: changes the top element's value to `[text]`
- `exit`: quits the program
### Non-traditional Stack Commands
These commands aren't usually associated with stacks and are only added as I use this program to experiment with changes to [my scripting language](https://github.com/dvtate/yoda)
- `list`: prints all the elements in the stack
- `at [index]`: get value at given element
- `edit [index] [value]`: change value at given index
