//
//  main.c
//  Battleship Main Menu
//
//  Created by Ian Shinbrot on 2/26/14.
//  Copyright (c) 2014 rumford. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



int MainMenu()
{
    
    int response=0;
    
    
    
    do
    {
        printf("Please select an option.\n");
        printf("1: Start a new Server\n");
        printf("2: Join Server\n");
        printf("3: Display the introduction again\n");
        printf("4: Quit\n\n\n");
        
    }
        while (response>5 || response<0);
    
    scanf("%d", &response);
    
     return response;
}

void introduction()
{
    printf("Welcome to the game battleship. This will be played over tux.\n");
    printf("First, you will be prompted where to select your ships.\n");
    printf("Then you will begin the game. Just select where to hit the pieces");
    printf("The menu will display now\n\n\n");
}


int main(int argc, const char * argv[])
{

    int num;
    introduction();
    
    
    
    
    do
    {
        num = MainMenu();
        if (num==1)
        {
            // start server function
            fork();
            // make IP Address 127.0.0.1
        }
    
        if (num==2)
        {
            // join server function
            // join host
        }
    
        if (num==3)
        {
            introduction();
        }
    
    } while(num<4);
    
    
    return 0;
}

