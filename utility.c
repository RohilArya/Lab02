/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Harshan Mohanaraj, Rohil Arya
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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

//Change directory
void cd(char *name) {
    if (chdir(name) == -1) {
        puts("Location not found");
    } else {
        
    }
}

//Directory
void dir(char *name){
	if(strcmp(name, "") == 0){
		name = ".";
	}

    DIR *directory;
    struct dirent *ep = NULL;

    directory = opendir(name);
    if(directory != NULL){
        while((ep = readdir(directory))){
            puts(ep->d_name);
        }
        (void) closedir(directory);
    }
    else{
        perror("Could not open ");
    }
    free(ep);
}

//Environ (lists all env settings)
void environ(char* env[]){
	int i;
	for( i = 0; env[i] != NULL; i++) {
		printf("%s\n",env[i]);
	}	
}

//Pause
void pause1(){
	char c;
	puts("Press Enter to continue...");
	do{
		c = fgetc(stdin);
	} while (c != 10);
} 

//Echo
void echo(char *text){
    puts(text);
}

//Help
void help(){
	
}



