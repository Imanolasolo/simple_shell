![Brand](https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg)

# Simple Shell
<div style="text-align: justify">

Thank you for visiting this repository which contain our Simple Shell project written in C programming language. for the
**Low Level Programming** curriculum at Holberton School.

![Logo](https://www.howtogeek.com/wp-content/uploads/2021/05/laptop-with-terminal-big.png?height=200p&trim=2,2,2,50)

# Getting Started :running:
<div style="text-align: justify">

## Table of Contents
* [About](#about)
* [Requirements](#requirements)
* [Files](#files)
* [Credits](#credits)
* [Flowchart](#flowchart)


## About
This directory contains a collection of files, functions, structs and scripts used to build and manage this repository. If there are any issues regarding the intention of a particular script (or even part of a certain script), please reach out to us.

	
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

## List of allowed functions and system calls

* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Files 


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


## Flowchart
![simple_shell PNG](https://user-images.githubusercontent.com/86312558/145315217-4223dcec-460e-4538-9846-e704a953364c.png)







## Credits

## Author(s):blue_book:

Work is owned and maintained by
* Imanol Asolo 3848 <[![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/Imanolasolo)>
* Andrés Medina 3371 <[TheRealMedi](https://github.com/TheRealMedi)>
* Alex Arévalo 3915 <[Alexoat76](https://github.com/Alexoat76)>

<3848@holbertonschool.com>

@Imanolasolo [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/Imanolasolo)
@jjusturi [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/jjusturi)
@jjusturi [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/25px-LinkedIn_logo_initials.png)](https://www.linkedin.com/in/imanol-asolo-5ba9b42a/)


<3371@holbertonschool.com>

@TheRealMedi [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/TheRealMedi)
@_SoyMedi [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/_SoyMedi)


<3915@holbertonschool.com>

@Alexoat76 [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/9/91/Octicons-mark-github.svg/25px-Octicons-mark-github.svg.png)](https://github.com/Alexoat76)
@aoarevalot [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/25px-Twitter_Bird.svg.png)](https://twitter.com/aoarevalot)
Alexoat76 [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/25px-LinkedIn_logo_initials.png)](https://www.linkedin.com/in/Alexoat76/)


## Acknowledgments :mega: 

### **`Holberton School`** (*providing guidance*)
	
![Brand](https://avatars.githubusercontent.com/u/13408012?s=50&v=4)
www.holbertonschool.com [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/Crystal_Clear_app_Internet_Connection_Tools.svg/30px-Crystal_Clear_app_Internet_Connection_Tools.svg.png)](https://www.holbertonschool.com/)
	support@holbertonschool.com [![M](https://upload.wikimedia.org/wikipedia/commons/thumb/4/4e/Mail_%28iOS%29.svg/25px-Mail_%28iOS%29.svg.png)](https://github.com/holbertonschool#:~:text=support%40holbertonschool.com)
