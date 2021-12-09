# Simple Shell
<div style="text-align: justify">

Thank you for visiting this repository which contain our Simple Shell project written in C programming language. for the
**Low Level Programming** curriculum at Holberton School.

![Logo](https://www.howtogeek.com/wp-content/uploads/2021/05/laptop-with-terminal-big.png?height=200p&trim=2,2,2,50)

# Getting Started :running:
<div style="text-align: justify">

## Table of Contents
* [About](#about)
* [Man Page](#manpage)
* [Flowchart](#flowchart)
* [Requirements](#requirements)
* [Depedences](#dependences)
* [Credits](#credits)



## About
This directory contains a collection of files, functions, structs and scripts used to build and manage this repository. If there are any issues regarding the intention of a particular script (or even part of a certain script), please reach out to us.

## Man page
*In progress

## Flowchart
![simple_shell1 drawio](https://user-images.githubusercontent.com/86312558/145317248-11c642c3-335b-47a6-aa7b-1b53ad1de844.png)
	
## Requirements 

### Resources

**Read or watch** :

[![M](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2f/Google_2015_logo.svg/80px-Google_2015_logo.svg.png)](https://www.google.com/search?q=Writing+a+shell+in+C&sa=X&ved=2ahUKEwi6vIn-nrr0AhWbTDABHUjrAxwQ1QJ6BAgLEAE&biw=1378&bih=708&dpr=1.25)

[![M](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e1/Logo_of_YouTube_%282015-2017%29.svg/70px-Logo_of_YouTube_%282015-2017%29.svg.png)](https://www.youtube.com/watch?v=z4LEuxMGGs8)

* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)

* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)

* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)


## General :page_with_curl:
<div style="text-align: justify">
* Allowed editors: vi, vim, emacs. </div>
<div style="text-align: justify">
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options:

`-Wall -Werror -Wextra -pedantic -std=gnu89`. </div>
<div style="text-align: justify">

* All your files should end with a new line.

*A `README.md` file, at the root of the folder of the project is mandatory. </div>

<div style="text-align: justify">
* Your code should use the Betty. It will be checked using</div>

`betty-style.pl` and `betty-doc.pl`.</div>

Please visit the [Betty style](https://github.com/holbertonschool/Betty/wiki) for the full specifications of Betty coding and documentation styles.

*Your shell should not have any memory leaks.

*No more than 5 functions per file.

*All your header files should be include guarded.

*Use system calls only when you need to.


## **More Info**

## Installation

Clone this repository: git clone `"https://github.com/Imanolasolo/simple_shell.git"`
	
Change directories into the repository: cd `simple_shell`
	
Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
	
Run the shell in interactive mode: `./hsh`
	
Or run the shell in non-interactive mode: example `echo "ls -lh" | ./hsh`
	
## Dependences 


| Files | Description |
| :---  | :--- |
| [main.c](./main.c) | Starts the shell `CLI`.  |
| [shell.h](./shell.h)| `Header File` containing the differente `libraries`, `macros`, `structures`, `variables` and `principal functions` used in the project.|
| [command_sequence.c](./command_sequence.c)| File to creates and `handle the command` sequence or `AST`.|
| [dynamic_structures.c](./dynamic_structures.c)| File to created to `handle functions` to use in structures.|
| [environment.c](./environment.c)| File to check and use the environmental variables list and compare with the sequence or `AST`.|
| [exit.c](./exit.c)| File created to `free sequence` and return exit code.|
| [execute_commands.c](./execute_commands.c)| File used to `execute` different commands from the sequence.|
| [history.c](./history.c)| File created to `create` and `handle` the `history node`.|
| [history_file.c](./history_file.c)| File used to `manage` the history files.|
| [history_queue.c](./history_queue.c)| File created to build and `create the history` of used commands and `sequences`.|
| [int_to_string.c](./int_to_string.c)| File used to change `type` of variables from `int to string` (use for arithmetic tasks).|
| [man_1_simple_shell](./man_1_simple_shell)| File to `show` the `manual page` of simple shell project.|
| [path_finder.c](./path_finder.c)| File used to `work` with `paths` (environment paths, list of tokenized directories).|
| [print_errors.c](./print_errors.c)| File created to `print` different `errors`.|
| [realloc.c](./realloc.c)| File to reallocate `memory blocks` and copy `old` to `new`.|
| [signal_handler.c](./signal_handler.c)| File to register `signal handlers` for `kernel`.|
| [start_shell.c](./start_shell.c)| File to `start the process` of simple shell project.|
| [std_funcs.c](./std_funcs.c)| File to `create standard functions`.|
| [string_parser.c](./string_parser.c)| File used to create the functions to cut the `AST` or sequence into `pieces`.|
| [tokenize_string.c](./tokenize_string.c)| File use to read the tokens from the `AST` or sequence.|

## Usage

To use the `.hsh` shell, *assuming the above `.c` dependencies have been installed,* compile all `.c` files in the repository and include the header `shell.h`in the entry point function.

## Credits

## Author(s):blue_book:

Work is owned and maintained by
* Imanol Asolo <[3848](mailto:3848@holbertonschool.com)> [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/Imanolasolo) [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/jjusturi) [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/25px-LinkedIn_logo_initials.png)](https://www.linkedin.com/in/imanol-asolo-5ba9b42a/)
* Andrés Medina <[3371](mailto:<3371@holbertonschool.com>)> [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/TheRealMedi) [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/_SoyMedi)
* Alex Arévalo <[3915](mailto:3915@holbertonschool.com)> [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/Alexoat76) [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/aoarevalot) [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/25px-LinkedIn_logo_initials.png)](https://www.linkedin.com/in/Alexoat76/)


## Acknowledgments :mega: 

### **`Holberton School`** (*providing guidance*)
This program was written as part of the curriculum for Holberton School.
Holberton School is a campus-based full-stack software engineering program
that prepares students for careers in the tech industry using project-based
peer learning. For more information, visit [this link](https://www.holbertonschool.com/).
<p align="center">
  <img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" alt="This is a secret;)">
</p>
