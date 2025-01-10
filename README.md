# Pipex Project

Pipex is a project that emulates the behavior of the shell's pipeline (`|`) by redirecting input and output streams between commands. This project is implemented in C and consists of several files that work together to handle piping and process management.

## Project Structure

Here is an overview of the files included in this project:

### 1. **`get_path.c`**
This file contains functions to handle and retrieve the paths of executable commands from the system's `PATH` environment variable. It ensures that commands can be located and executed correctly.

### 2. **`libft/`**
This directory contains a custom library of helper functions commonly used in C programming. The library provides utilities for string manipulation, memory management, and more.

### 3. **`Makefile`**
The `Makefile` automates the compilation process for the project. It includes rules to build, clean, and manage dependencies for the project files.

- **Common targets:**
  - `make`: Compiles the program.
  - `make clean`: Removes object files.
  - `make fclean`: Removes object files and the executable.
  - `make re`: Cleans and recompiles the project.

### 4. **`pipex.c`**
This is the main file of the project. It handles the core functionality, including argument parsing, process creation, and piping between commands. It acts as the entry point for the program.

### 5. **`pipex.h`**
The header file for the project, `pipex.h`, contains function prototypes, macros, and any necessary data structures shared across multiple files.

### 6. **`pipex_util.c`**
This file contains utility functions used throughout the project. These helper functions simplify repetitive or complex tasks, making the main logic easier to follow.

## How to Compile

To compile the project, simply run:

```bash
make
```

This will generate an executable, typically named `pipex`.

## Usage

The program takes the following command-line arguments:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

- **`infile`**: The input file containing the initial data.
- **`cmd1`**: The first command to execute.
- **`cmd2`**: The second command to execute, receiving the output of `cmd1`.
- **`outfile`**: The file where the final output will be written.

### Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

This command reads from `input.txt`, passes it through `grep hello`, then pipes the output through `wc -l`, and finally writes the result to `output.txt`.

## Cleaning Up

To clean up object files and the executable:

```bash
make fclean
```

This will remove all compiled files, leaving the source code untouched.

## Notes

- Ensure all required libraries and dependencies are installed on your system.
- Error handling is implemented for edge cases, such as missing files or invalid commands.
- The project was designed to mimic the behavior of shell pipelines as closely as possible.
