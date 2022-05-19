# 1-basics

This source file contains content from Lessons 1 to 4 of the Build Your Own Lisp book.

## Usage

If you are on Windows, you can immediately compile `main.c` and run it.
```bash
gcc main.c -o main
./main
```

If you are not on Windows, you will need the `editline` library on your computer to allow for additional functionality (e.g. command history).

Install the library with
```bash
sudo apt-get install libedit-dev
```

and compile and run
```bash
gcc main.c -o main -ledit
./main
```
