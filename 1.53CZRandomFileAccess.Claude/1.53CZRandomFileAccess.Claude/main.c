#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE* fPointer;
	//"w+" opens the file for both writing and reading. If the file doesn't exist, it will be created.

	fPointer = fopen("TestTextFile.txt", "w+");

	//Write an initial string into the file.
	fputs("I am the 3rd Adam", fPointer);

	//fseek() lets you jump to any position within a file, giving you random access.
	//Parameter 1: the file pointer to reposition.
	//Parameter 2: the byte offset to move by.
	//Parameter 2: the reference point - SEEK_SET starts counting from the beginning of the file.
	//The cursor is now placed at byte 13 (0-indexed), right before "Adam"/
	//Any subsequent write will overwrite content from that position onward.
	fseek(fPointer, 13, SEEK_SET);

	fputs("Aten ", fPointer);
	//The file now reads: "I am the 3rd Aten "

	//SEEK_END uses the end of the file as the reference point.
	//A negative offset moves the cursor backwards from the end.
	//Here, the cursor is placed 1 byte before the last character.
	fseek(fPointer, -1, SEEK_END);

	fputs(" 3", fPointer);

	//The file now reads: "I am the 3rd Aten 3"

	fclose(fPointer);
}

//SEEK_SET - offset is relative to the beginning of the file
//SEEK_END - offset is relative to the end of the file.
//SEEK_CUR - offset is relative to the current cursor position