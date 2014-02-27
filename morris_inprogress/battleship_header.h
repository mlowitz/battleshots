//
//  battleship_header.h
//  battleship_over_tux
//
//  Created by Ian Shinbrot on 2/24/14.
//  Copyright (c) 2014 rumford. All rights reserved.
//


#ifndef battleship_over_tux_battleship_header_h
#define battleship_over_tux_battleship_header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define Ship_Size 10

enum ship_piece {patrol_boat=5, destroyer=4, submarine=3,battleship=2,aircraft_carrier=1};
enum row {a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7, i=8, j=9};

char ** newBoard() ;
char ** attackBoard(int x, int y, char ** board);
bool OutofBounds(int x, int y);
bool WordExists(char word[32], char *letter);
void displayBoard(char ** board);



void introduction()
{
    printf("Welcome to the game battleship. This will be played over tux.\n");
    printf("First, you will be prompted where to select your ships.\n");
    printf("Then you will begin the game. Just select where to hit the pieces");
}

#endif
