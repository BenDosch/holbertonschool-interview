# Menger sponge

1. [Requirements](#requirements)
2. [Tasks](#tasks)
	1. [2D Menger sponge](#0-2d-menger-sponge)
3. [Author](#author)


## Requirements

* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* The prototypes of all your functions should be included in your header file called menger.h
* All your header files should be include guarded

## Tasks
List of tasks with brief descriptions of each task.

### [0. 2D Menger sponge](https://github.com/BenDoschGit/holbertonschool-machine_learning/blob/main/supervised_learning/r/0-menger.c "0. 2D Menger sponge")

Write a function that draws a 2D Menger Sponge

* Prototype: void menger(int level);
* Where level is the level of the Menger Sponge to draw
* If level is lower than 0, your function must do nothing
* You’re allowed to use the math library. Your program will be compiled using the ld flag -lm

Format:

* Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
* A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty
* A level 0 sponge is represented by the # character
* Examples:
	* A level 0 sponge is a simple 1x1 square
	* A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
	* A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
	*  …
* TIP: The size of a level N Menger sponge is calculated as follows: 3^N

---

## Author

[Benjamin Dosch](https://github.com/BenDoschGit)