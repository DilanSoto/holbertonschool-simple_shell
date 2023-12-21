Simple Shell

Introduction

"Simple Shell" is a Holberton School project aimed at creating a simple command interpreter (shell) using a limited set of standard C library functions. This shell is designed to provide a basic understanding of how shells operate in Unix/Linux systems.

Features

Interprets and executes commands entered by the user.
Handles a list of allowed functions and system calls, ensuring a focus on fundamental programming concepts.
Works in a simple, straightforward manner without advanced features like piping, redirection, or handling of special characters.
List of Allowed Functions and System Calls

access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat, lstat, fstat, strtok, wait, waitpid, wait3, wait4, write.
Installation

Clone the repository: git clone [git@github.com:DilanSoto/holbertonschool-simple_shell.git]
Change to the repo directory: cd holbertonschool-simple_shell
Compile: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
Run the shell in interactive mode: ./hsh
Alternatively, run the shell in non-interactive mode: echo "ls -l" | ./hsh
Usage

Run the shell and type commands at the prompt.
The shell handles simple command executions based on the provided list of allowed functions and system calls.
To exit the shell, type exit.
Contributors

This project was created by [Dilan Soto] and [Ismael Pimente]. A complete list of contributors can be found in the AUTHORS file.