# C - Simple Shell

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Examples](#examples)

## Overview
The Simple Unix Shell is a basic command-line interface for Unix-like systems. It allows users to interact with the operating system by executing commands, managing directories, and utilizing essential shell functionalities.

## Features

- **Interactive Prompt:** Provides an interactive command prompt for user input.

- **Command Execution:** Executes system commands and external programs.

- **Command Search:** Searches for commands in predefined paths.

- **Command History:** Maintains a history of executed commands for reference.

- **Built-in Commands:** Supports built-in commands such as `cd`, `exit`, `pwd`, `echo`, and `ls`.

- **Environment Variables:** Enables manipulation of environment variables.

## Usage

1. **Compilation:** Compile the program using a C compiler.

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

2. **Execution:** Run the shell.

```bash
./hsh
```
3. **Interactive Commands:** Input commands in the interactive prompt.

```bash
$ ls -l
```
4. **Shell Termination:** To exit the shell, use the `exit` command.

## Examples

- **List Files in Long Format:**
```bash
$ ls -l
```
- **Change Directory:**

```bash
$ cd /path/to/directory
```
- **Print Current Directory:**

```bash
$ pwd
```

- **Echo Message:**

```bash
$ echo Hello, World
```

- **Exit the Shell:**

```bash
$ exit
```

## Authors

- [LOUIS TORO](https://github.com/Ltoro9)
- [EMMANUEL MALDONADO](https://github.com/emmanuelmaldonadomaldonado)
