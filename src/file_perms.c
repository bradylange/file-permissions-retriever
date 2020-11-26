#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define CAP 256

/*
 * Brady Lange
 * 4/16/18
 * File name: file-info.c
 * This program gives file information about a file like the name, file type, and permissions.
 */

//Main function
int main()
{
	//Variables
	struct stat info;
	char file[CAP];
	char input[CAP];

	//Getting the file
	printf("Which file would you like to learn more about?\n");
	//Grabbing the file input
	scanf("%s", file);
	stat(file, &info);

	//Loop so the user can access more than one piece of information about the file
	while(strcmp(input, "Exit") != 0)
	{
	   //Getting the file information that the user wants to know
	   printf("\nWhat do you want to know about the file?\n");
	   printf("Enter exactly one of the options:\n");
	   printf("\n- File_Name\n- I-Node_Number\n- Size\n- File_Type\n- File_Permissions\n- Exit\n\n");
	   
	   scanf("%s", input);

	   //Executing the stat function based upon the users input
	   if(strcmp("File_Name", input) == 0)
			printf("\nFile Name: %s\n", file);
	   else 
		   if(strcmp("I-Node_Number", input) == 0)
				printf("\nI-Node Number: %lu\n", info.st_ino);
	   else 
		   if(strcmp("Size", input) == 0)
				printf("\nFile Size: %lu\n", info.st_size);
	   
	   //File permissions
	   else 
		   if(strcmp("File_Permissions", input) == 0)
		   {
				if((info.st_mode &  S_IRWXU) == S_IRWXU)
						printf("\nOwner has read, write, and execute permissions\n");
				else 
					if(((info.st_mode &  S_IRUSR) == S_IRUSR) && ((info.st_mode & S_IWUSR) == S_IWUSR))
						printf("\nOwner has read and write permissions\n");
				else 
					if(((info.st_mode &  S_IRUSR) == S_IRUSR) && ((info.st_mode & S_IXUSR) == S_IXUSR))
						printf("\nOwner has read and execute permissions\n");
				else 
					if(((info.st_mode &  S_IWUSR) == S_IWUSR) && ((info.st_mode & S_IXUSR) == S_IXUSR))
						printf("\nOwner has write and execute permissions\n");
				else 
					if((info.st_mode &  S_IRUSR) == S_IRUSR)
						printf("\nOwner has read permissions\n");
				else 
					if((info.st_mode &  S_IWUSR) == S_IWUSR)
						printf("\nOwner has write permissions\n");
				else 
					if((info.st_mode &  S_IXUSR) == S_IXUSR)
						printf("\nOwner has execute permissions\n");
				if((info.st_mode &  S_IRWXG) == S_IRWXG)
						printf("\nGroup has read, write, and execute permissions\n");
				else 
					if(((info.st_mode &  S_IRGRP) == S_IRGRP) && ((info.st_mode & S_IWGRP) == S_IWGRP))
						printf("\nGroup has read and write permissions\n");
				else 
					if(((info.st_mode &  S_IRGRP) == S_IRGRP) && ((info.st_mode & S_IXGRP) == S_IXGRP))
						printf("\nGroup has read and execute permissions\n");
				else 
					if(((info.st_mode &  S_IWGRP) == S_IWGRP) && ((info.st_mode & S_IXGRP) == S_IXGRP))
						printf("\nGroup has write and execute permissions\n");
				else 
					if((info.st_mode &  S_IWGRP) == S_IWGRP)
						printf("\nGroup has write permissions\n");
				else 
					if((info.st_mode &  S_IRGRP) == S_IRGRP)
						printf("\nGroup has read permissions\n");
				else 
					if((info.st_mode &  S_IXGRP) == S_IXGRP)
						printf("\nGroup has execute permissions\n");
				if((info.st_mode &  S_IRWXO) == S_IRWXO)
						printf("\nOther's have read, write, and execute permissions\n");
				else 
					if(((info.st_mode &  S_IROTH) == S_IROTH) && ((info.st_mode & S_IWOTH) == S_IWOTH))
						printf("\nOther's have read and write permissions\n");
				else 
					if(((info.st_mode &  S_IROTH) == S_IROTH) && ((info.st_mode & S_IXOTH) == S_IXOTH))
						printf("\nOther's have read and execute permissions\n");
				else 
					if(((info.st_mode &  S_IWOTH) == S_IWOTH) && ((info.st_mode & S_IXOTH) == S_IXOTH))
						printf("\nOther's have write and execute permissions\n");
				else 
					if((info.st_mode &  S_IROTH) == S_IROTH)
						printf("\nOther's have read permissions\n");
				else 
					if((info.st_mode &  S_IWOTH) == S_IWOTH)
						printf("\nOther's have write permissions\n"); 
				else 
					if((info.st_mode &  S_IXOTH) == S_IXOTH)
						printf("\nOther's have execute permissions\n");
	   }
	   
	   //File types
	   else 
		   if(strcmp("File_Type", input) == 0)
		   {
				if((info.st_mode & S_IFMT) == S_IFREG)
						printf("\nRegular File\n");
				// else 
				// 	if((info.st_mode & S_IFMT) == S_IFSOCK)
				// 		printf("\nSocket\n");
				else 
					if((info.st_mode & S_IFMT) == S_IFDIR)
						printf("\nDirectory\n");
				else 
					if((info.st_mode & S_IFMT) == S_IFCHR)
						printf("\nCharacter Device\n");
				// else 
				// 	if((info.st_mode & S_IFMT) == S_IFLNK)
				// 		printf("\nSymbolic Link\n");
				else 
					if((info.st_mode & S_IFMT) == S_IFIFO)
						printf("\nFIFO\n");\
				else 
					if((info.st_mode & S_IFMT) == S_IFBLK)
						printf("\nBlock Device\n");
		   }
	   
	   //Exit the program
	   else 
		   if(strcmp("Exit", input) == 0)
		   {
				break;
		   }

	}

	return 0;

}
