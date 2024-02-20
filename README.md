# Monty Interpreter
## Overview
This project is a part of the Software Engineering Foundations curriculum and focuses on implementing a simple interpreter for Monty ByteCodes files. The Monty language relies on a unique stack with specific instructions to manipulate it. The interpreter is designed to read Monty byte code files and execute the corresponding instructions.

## Project Details
- *Author*: Julien Barbier
- *Team*: Junior Mabunda

## Learning objectives
- The concepts of LIFO and FIFO
- Implementation of stacks and queues in C
- Proper usage of global variables
- Basics of the Monty language

## Monty ByteCode Files
Monty byte code files have a `.m` extension and contain instructions like `push`, `pall`, `pint`, `pop`, `swap`, `add`, and `nop`. The interpreter executes these instructions line by line.

## Usage
```
./monty file
```
- Replace `file` with the path to the Monty byte code file.
- If no file or more than one argument is provided, the program prints `USAGE: monty file` and exits with `EXIT_FAILURE`.
- If the file cannot be opened, it prints `Error: Can't open file <file>` and exits with `EXIT_FAILURE`.
If an invalid instruction is encountered, it prints `L<line_number>: unknown instruction <opcode>` and exits with `EXIT_FAILURE`

## Monty opcodes
- `push`, `pall` - add to top of stack, and print stack, respectively.
- `pint` - print top value.
- `pop` -  remove top element from stack.
- `swap` - swap top two elements of the stack.
- `add` - add top two elements of the stack.
- `nop` - does nothing

## Compilation
Code is compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

```