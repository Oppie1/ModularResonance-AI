#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//Required for FILE, fopen(), fclose(), fprintf(), printf()
#include<stdlib.h>//Included for general-purpose utilities



int main() {
	
	//FILE* is a pointer to a FILE structure managed by the C standard library.
	//It acts as a handle that tracks the file's current position, error state, and buffer.
	FILE* fPointer;

	//fopen() opens a file and returns a pointer to it.
	//First argument : : the name (or path) of the file to open.
	//Second argument : the mode in which to pen the file.
	//"a" = Append mode - the file is opened for writing, but the cursor is placed at the END
	//of the existing content. If the file does not exist,  it will be created automatically.

	//NOTE: Use "w" if you want to overwrite the file instead of appending.
	fPointer = fopen("TestAppendToAFile.txt", "a");

	//Always check if fopen() succeeded before using the pointer.
	//fopen() returns NULL if the file could not be opened (e.g. permission denied, invalid path).
	//Using a NULL pointer would cause undefined behavior (crash).
	if (fPointer == NULL){
		printf("Error: Could not open file!\n");
	//Return a non-zero value to signal that the program failed.
	return 1; 
}

//fprintf() works like printf() but writes formatted output to a file instead of the console. 
//The first argument is the file pointer to write to. "\n" at the start ensures the new text
//begins on its own line in the file.
fprintf(fPointer, "-A warning from the 3rd Adam ");

//fclose() flushes any buffered data to disk and releases the file handle.
//Always close a file after you are done with it to prevent data loss or resource
//leaks. After this call, fPointer should no longer be used.
fclose(fPointer);

//Inform the user the operation completed successfully.
printf("Test successfully appended");

//Return 0 to signal that the program completed successfully.
return 0;

}