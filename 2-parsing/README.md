# 2-parsing

This source file contains content from Lessons 5 to 6 of the Build Your Own Lisp book. The lessons covered parsing using the given library, this source file includes attempts at the challenges at the end of the lesson like recognising operators in textual format, and recognising decimal numbers with regular expressions.

## Usage
This program uses the [Micro Parser Combinators](https://github.com/orangeduck/mpc) library to parse commands. The library is stored in the `mpc/` directory.

If you are on Windows, you can compile `main.c` and `mpc/mpc.c` and run it.
```bash
gcc main.c mpc/mpc.c -o main
./main
```

As with the [previous part](https://github.com/Rye123/build-your-own-lisp/tree/main/1-basics), you will need the `editline` library on your computer to allow for additional functionality.

Compile and run with:
```bash
gcc main.c mpc/mpc.c -o main -ledit -lm
./main
```
