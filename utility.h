/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Harshan Mohanaraj, Rohil Arya
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);

extern void cd(char *name);
extern void clr();
extern void environ(char* env[]);
extern void help();
extern void pause1();
extern void dir(char *name);
extern void echo(char *text);


#endif /* UTILITY_H_ */
