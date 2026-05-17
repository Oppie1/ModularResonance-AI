#include<stdio.h>
#include<stdlib.h>

//Functions let you split your program into smaller, manageable pieces.
//You write a block of code once as a function, then reuse it anywhere in your program.

//The"void" return type means this function doesn't send any value back to main.
//Declaring it here, before main, tells the compiler it exists before it's actually defined.
//This early declaration is know as function prototype.
void printSomething();


//main is itself a function - every C program is a collection of functions, and main is the entry point.
//It's the one function every C program must have; execution always starts here.
//When the program runs, C jumps straight into main and works through everything inside its curly braces.

int main() {

	//To use a function, write its name followed by parentheses - this is called "calling" a function.
	//When main calls a function, it hands over control, lets the function run completely, then resumes
	//right where it left off in main. You can call the same function as many times as you neec. Below,
	//we call it 3 times.
	//Note: you don't include the return type (e.g. "void")  when calling a function.
	printSomething();
	printSomething();
	printSomething();

	printf("\nCongratulations, you ran a function 3 times!\n");

	//Returning 0 signals to the OS that the program finished successfully.
	//Technically the compiler adds this automatically, but it's good practice to be explicit.
	return 0;
};

//Function definitions live outside of main. This is where you give a prototype its actual behavior.
//main delegates work to these , and once they finish, control flows back to main.

//The block below is the function definition - it provides the full implementation of the prototype above.

void printSomething() {
	printf("This is the output of the definition of the protptype of the function.\n");

	//Reaching "return" means this function is finished - conrol goes back to wherever it was called from.
	return;
}

//Everything a function does is contained within its curly braces {  }.
//"return" signals the end of the function and hands execution back to the calling code.
