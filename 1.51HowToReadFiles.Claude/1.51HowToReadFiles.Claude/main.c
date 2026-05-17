#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main()
{
	//A FILE pointer is used to reference the file we want to work with.
	FILE* fPointer;
	//Open the file in read-only mode ("r") - we only want to read its contents.
	fPointer = fopen("TestReadFile.txt", "r");
	//If the file couldn't be opened (e.g. it doesn't exist). fopen returns NULL
	if (fPointer == NULL) {

		//Returning 1 signals the program ended due to an error
		return 1;
	}

	//A character buffer to hold one line at a time - 150 is the maximum line length we support
	char singleLine[150];

	//Keep reading until we reach the end of the file (eof = end of file)
	while (!feof(fPointer)) {
		//REad the next line from the file into our buffer.
		fgets(singleLine, 150, fPointer);
		//Print the line to the console
		puts(singleLine);
	}

	//Always close the file when done to free up system resources.
	fclose(fPointer);
}

/*
The output appears double-spaced because each line in the .txt file ends with a newline character '\n'.
Since puts() also appends it own newline, each line gets printed with an extra blank line between them.
*/