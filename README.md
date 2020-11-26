# file-permissions-retriever
Displays file permission information.

Brady Lange

04/16/18

Op Sys Programming

Assignment 4

## `src/file_perms.c`
This program allows the user to learn information about a file such as file type, file permissions, file name,
file size, and I-Node Number. The program uses various logical statements to execute if the users input
matches their conditions. The correct information outputted is made possible because of the stat and struct 
combination. 

### Input:

`a.out`

`file_perms.c`

`File_Type`

### Output:

`Which file would you like to learn more about?`

```
What do you want to know about the file?
Enter exactly one of the options:

- File_Name
- I-Node_Number
- Size
- File_Type
- File_Permissions
- Exit
```

`Regular File`

## Issues:
- `file_perms.c`: `S_IFSOCK` and `S_IFLNK` doesn't work (Windows problem?)