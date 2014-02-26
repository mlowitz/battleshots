//
//  battleship.c
//  battleship_over_tux
//
//  Created by Ian Shinbrot on 1/28/14.
//  Copyright (c) 2014 rumford. All rights reserved.
//

#include <stdio.h>
#include "battleship_header.h"


int getrow()
{
    return 0;
}

int getcolumn()
{
    return 0;
}

bool shipexists()
{
    return true;
}

bool hitpiece()
{
    return true;
}
bool placevalid(int x, int y, bool is_vertical, int length, char ** board)
{
   
    if (is_vertical)
    {
        for (int ii=x; ii<x+length; ii++)
        { if (OutofBounds(ii, y))
            {
                return false;
            }
            if (board[y][ii]!='-')
            return false;
        }
    }
    if (!is_vertical)
    {
        for (int ii=y; ii<y+length; ii++)
        {
            if (OutofBounds(x,ii))
            {
                return false;
            }
            if (board[ii][x]!='-')
            return false;
        }
    }
    return true;
}
void placePiece_Begin(bool is_vertical, char ** board, int length)
{
    int x ;
    enum row y;
    char *c = malloc(sizeof(char)*1);
    bool placed=false;
    
    printf("Please pick the coordinates that you would like to place your piece at (in the format of A #: ");
    scanf("%s", c);
    
    if (WordExists("A", c))
    {
        y=a;
    }
    if (WordExists("B", c))
    {
        y=b;
    }
    
    
    scanf("%d", &x);
    
    
    
    
    while (!placed)
    {
        if (placevalid(x,y,is_vertical, length, board))
        {
            if (!is_vertical)               // determines if artifact will be vertical
                    {
                
                    for (int jj = x; jj<x+length; jj++)
                    {
                        placed=true;
                        board[y][jj] = 's';
                    }
                }
            
                else if (is_vertical)
                    {
                    for (int jj = y; jj<y+length; jj++)
                    {
                        placed=true;
                        board[x][jj] = 's';
                        }
                    
                }
                else
                {
                    printf("Those coordinates didn't work. Please try picking the coordinates again (in the format of A#");
                    scanf("%d %d", &y, &x);
                }
            }
    }
    

}
/*
 allows you to pick pieces from a board
 board is the matrix created
 */
void PickPiece(char ** board)
{
    int piece =0;           // number as defined in menu
    bool is_vertical;
    int num_picked=0;
    bool orientation=false;
    bool piece1=false,piece2=false,piece3=false,piece4=false,piece5=false;
    char *response = malloc(Ship_Size);
    
    printf("Please type the number of the piece that you would like to place?\n");
  
    while (num_picked<5)
    {
   displayBoard(board);
        printf("1: AIRCRAFT\n");
        if (piece1)                     // if piece was used yet
        {
            piece1=true;
            num_picked++;
        }
        printf("2: BATTLESHIP \n");
        if (piece2)                     // if piece was used yet
        {
      
            piece2=true;
            num_picked++;
        }
         printf("3: SUBMARINE \n");
        if (piece3)                     // if piece was used yet
        {
           
            piece3=true;
            num_picked++;
        }
              printf("4: DESTROYER \n");
        if (piece4)                     // if piece was used yet
        {
      
            piece4=true;
            num_picked++;
        }
        printf("5: PATROL BOAT \n");
        if (piece5)                     // if piece was used yet
        {
            
            piece5=true;
            num_picked++;
        }
        if (!piece1 || !piece2 || !piece3 || !piece4 || !piece5)
        {
            scanf("%d", &piece);
        }
        int size=0;
    
    
    
        do
           {
               printf("What orientation would you like to have the piece (veritcal/horizontal)\n");
               scanf("%s", response);
           
               if (WordExists(response, "horizontal"))
               {
                   orientation=true;
                   is_vertical=false;
               }
               else if (WordExists(response, "vertical"))
               {
                   orientation=true;
                   is_vertical=true;
               }
    }while (!orientation);
    
        switch (piece)
        {
            case 1:     // aircraft picked
            size=5;
            break;
        
            case 2:     // battleship picked
            size=4;
            break;
        
            case 3:     // submarine picked
            size=3;
            break;
        
            case 4:     // destroyer picked
            size=3;
            break;
        
            case 5:     // patrol boat picked
                size=2;
            break;
        }
        placePiece_Begin(is_vertical, board, size);
    }
}

char ** newBoard()      // creates a matrix initializing everything to a
{
    char ** matrix;
    
    matrix = (char**)malloc(sizeof(char*)*10);
    
    for (int i=0; i<10;i++)
    {
        
        matrix[i] = (char*)malloc(sizeof(char));
        for (int j=0;j<10;j++)
        {
            matrix[i][j]=(char)malloc(sizeof(char)*1);
            matrix[i][j]='-';
        }
    }
    return matrix;
    
}
bool WordExists(char word[32], char *letter)
{
    if (strcmp(letter, word) == 0)
    return true;
    else return false;
}

bool OutofBounds(int x, int y)
{
    if (x>10 || y>10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
char ** attackBoard(int x, int y, char ** board)        // x and y are coordinates
{
    if (OutofBounds(x,y))
    {
        if (hitpiece())
        {
        board[x][y]='+';
        }
        else if (!hitpiece())
        {
            board[x][y]='-';
        }
    }
    return board;
}
void displayBoard(char ** board)
{
    printf("\n   ");
    for (int i = 0; i < 10; i++)
    printf("%d  ", i);
    printf("\n");
    
    // print rows of holes, with letters in leftmost column
    for (int i = 0; i < 10; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < 10; j++)
        printf("%c  ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main(void)
{
    
    char ** board = newBoard();
    
    // print top row of numbers
    PickPiece(board);
   // return contents;
    
    displayBoard(board);

}