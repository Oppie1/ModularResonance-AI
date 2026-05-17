#include<stdio.h>
#include<stdlib.h>



int main() {
//FILE is a special struct type defined in <stdio.h> used to represent an open file.
//fPointer is a pointer to that struct, which we use to interact with the file.
	FILE* fPointer;

	//Attempt to open "TestTextFile.txt" in write mode ("w").
	//Write mode will create the file if it doesn't exist, or wipe it clean if it does.
	//fopen_s returns 0 on success; any other value indicates something went wrong during the operation.
	//This is an error check, not a "does the file exist?" check.
	//A common cause of failure is an invalid or inaccessible path - 
	//for example, trying to write to "C:\\Users\\Public\\restricted\\test.txt" where permissions are denied.
	if (fopen_s(&fPointer, "TestTextFile.txt", "w") != 0) {
		//Display a system-generated message describing why the file failed to open.
		perror("Enter opening file");
		//Exit the program with a non-zero code to signal that an error occurred
		return 1;
	}
//Write a line of text into the file using the file pointer.
	fprintf(fPointer, "I am the test text file.\n");

	//Always close the file when done - this flushes any buffered data and releases the file handle.

	printf("If you're seeing this message you correctly wrote to a file. Go check it out in folder.\n");
}

//Sequential access reads or writes file data in order from start to finish, like reading a book page by page.
//Random access allows jumping directly to any poinsition in the file, regardless of order.


