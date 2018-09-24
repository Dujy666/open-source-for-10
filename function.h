#ifndef _function_h
#define _function_h

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<termios.h>
#include<curses.h>
#include<term.h>
#include<string.h>


static struct termios initial_settings,new_settings;
static int peek_character=-1;
static int alltimes;

void init_keyboard();
int kbhit();
void close_keyboard();
int get_data(int n);
void Check();
void rollandprint(char x[],int y,int jde,int info);
void Display_Rules();
void Sign_Up();
void start();
void Result();


#endif

