/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Harshan Mohanraj, Rohil Arya
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"



// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };
    char delim[BUFFER_LEN];
    char* token = NULL;

    // Parse the commands provided using argc and argv
	FILE *in_stream = NULL;
	
	if(argc > 1){
		in_stream = fopen(argv[1], "r");
		if(in_stream == NULL){
			
			printf("FILE COULD NOT BE OPENED %s", argv[1]);
			return EXIT_FAILURE;
		}
		
	} else {
		in_stream = stdin;
		printf("%s> ", getcwd(NULL, BUFFER_LEN));
	}
	
	
    /* Perform an infinite loop getting command input from users*/
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL){
	/* Reset inputs*/
	strcpy(arg, "");
        strcpy(command, "");
 
    	/* Perform string tokenization to get the command and argument*/
        strcpy(delim, " ");
        token = strtok(buffer, delim); // Command is isolated

        if (token[strlen(token)-1] == '\n')
            token[strlen(token)-1] = '\0';
        strcpy(command, token); // Command is initialized

        /* Argument portion */
        while(token != NULL) {
            strcpy(delim, "\n");
            token = strtok(NULL, delim);

            if (token == NULL)
                break;
            strcpy(arg, token); // Argument is initialized
        }
        /* cd command -- change the current directory*/
        if (strcmp(command, "cd") == 0)
        {
            if (strcmp(arg, " ") == 0 || strcmp(arg, "") == 0)
                printf("No location given \n");
            cd(arg);
        }
        /* other commands here...*/
        else if (strcmp(command, "clr") == 0)
        {
		system("@cls||clear");

        }
        else if (strcmp(command, "dir") == 0)
        {
		dir(arg);

        }
        else if (strcmp(command, "environ") == 0)
        {
		//environ();

        }
        else if (strcmp(command, "echo") == 0)
        {
		echo(arg);
        }
        else if (strcmp(command, "help") == 0)
        {
         char str[999];
        FILE * file;
        file = fopen( "readme" , "r");
        if (file) {
            while (fscanf(file, "%s", str)!=EOF)
                printf("%s",str);
            fclose(file);
        }
		help();

        }
        else if (strcmp(command, "pause") == 0)
        {
		pause1();

        }
     
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
