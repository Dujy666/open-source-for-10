#ifndef _rollandprint_h
#define _rollandprint_h

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

int get_data(int n);
void init_keyboard();
int kbhit();
void close_keyboard();
void rollandprint();
void start();

#endif
