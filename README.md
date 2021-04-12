<h1 align="center"> Simple Shell Project! </h1>

This simple shell was entirely crafted by our programming hands with the purposes of expanding our knowledge on C and linux OP, and of course to pass the curse. We explore most of the functionalities of the a shell of a linux OP including the most commonly used "ls", "pwd", "cd" and more. In this readme we will explain how, install it, how to run it and all the posibilites available within the boundaries  of our simple shell.


# Files included
- **shell.c**  ---!> This file contains the basic functions needed to make the shell loop to stay continuously open and to do the basic proceses of a shell: get the input, read it and execute it.
- **helper_functions.c** ---!> In this file are some functions needed to make the previous file work as its intended.
- **aux_functions.c** ---!> In this file are some extra functions that emulate some of the functions of the standard library but coded by ourselves.
- **man_1_simple_shell** ---!> A man page you can run to see the features and functionalities descriptions of this simple shell 
- **AUTHORS** ---!> This file lists all individuals having contributed content to the repository.
- **README.md** ---!> What you are reading.

## Installation of this awesome shell 
- First you need to open the terminal and select the folder you want to save the files needed to run the shell.
- Then run this command in the terminal to clone the repository to the local directory selected:
```ssh
$ git clone "el link"
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


## Contributors
 - [Jorge Tuset](https://github.com/jtusetgraniello)
 - [Raimundo Gallino](https://github.com/RaimundoGallino)
