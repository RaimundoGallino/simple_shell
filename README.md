<h1 align="center"> Simple Shell Project! </h1>

![markdown poster by Raimundo Gallino](/Extras/seashellRender7.png)

This simple shell was entirely crafted by our programming hands with the purpose of expanding our knowledge on C and Linux, and obviously to pass Holberton's course. We explore most of the functionalities of the a shell of a linux-based OS including the most commonly used "ls", "pwd", "cd" and more. In this readme we will explain how, install it, how to run it and all the posibilites available within the boundaries  of our simple shell.


# Files included
- **shell.c**  ---!> This file contains the basic functions needed to make the shell loop to stay continuously open and to do the basic proceses of a shell: get the input, read it and execute it.
- **helper_functions.c** ---!> In this file are some functions needed to make the previous file work as its intended.
- **aux_functions.c** ---!> In this file are some extra functions that emulate some of the functions of the standard library but coded by ourselves.
- **aux_functions2.c** ---!> More functions that emulate part of the standard library, only made by ourselves.
- **man_1_simple_shell** ---!> A man page you can run to see the features and functionalities descriptions of this simple shell
- **shellcito.h** ---!> C header file. Includes function prototypes, libraries and external variables.
- **AUTHORS** ---!> This file lists all individuals having contributed content to the repository.
- **README.md** ---!> What you are reading.

## Installation of this awesome shell 
- First you need to open the terminal and select the folder you want to save the files needed to run the shell.
- Then run this command in the terminal to clone the repository to the local directory selected:
```ssh
$ git clone https://github.com/RaimundoGallino/simple_shell.git
```
 - Compile the files with gcc using this flags (after the "-o" flag you will be naming the executable file, so name it as you wish):
```ssh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
- Finally run the executable file like so:
```ssh
$ ./hsh
```

## Using the shell 

A simple example of the usage of the shell would be displaying the files in the current directory, and we can do that by using the ls command:
```ssh
$/root/your_local_dir/simple_shell> ./hsh
$hsh> ls
shell.c helper_functions aux_functions.c man_1_simple_shell AUTHORS README.md
```
Or displaying the path of the current directory using the pwd command:
```ssh
$hsh> pwd 
/root/your_local_dir/simple_shell
```
## How it works
The basic structure of the shell is mainly devided by four steps. 

The first one consists on generating an infinite loop to keep the shell open and recibing the input lines. If nothing is recieved, it will continue looping. 

When an input line is recieved it will be sent to the second step: the reading. This step will read the string and parse it in to tokens. After that, the shell is intended to execute the input recieved.

In order to do that, the input parsed in tokens is passed to a function that searches for the correct path. Checking if the executable files of the command passed exist somewhere in the path of the OS (built in command definitions will be handled by the shell itself). Once we have the the full path of the command, the next step is to execute it. 

If everything went right in the previous steps the command will be executed as it is defined. After the execution of the program, the shell will return to its initial state awaiting any input to be recieved. Below this is a brief (really brief) flowchart of how the program is structured in order to achieve a better understanding of its inner workings.



## Contributors
 - [Jorge Tuset](https://github.com/jtusetgraniello)
 - [Raimundo Gallino](https://github.com/RaimundoGallino)
