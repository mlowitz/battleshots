//
//  battleship.c
//  battleship_over_tux
//
//  Created by Ian Shinbrot on 1/28/14.
//  Copyright (c) 2014 rumford. All rights reserved.
//

#include <stdio.h>
#include "battleship_header.h"


bool shipexists()
{
    return true;
}

bool hitpiece()
{
    return true;
}
/*
 This function converts a character containing input to the enumerated type.
 I used an enumerated type to make the code easier to read
 */
enum row convert(char * letter)
{
    enum row y;
    if (WordExists("A",letter))
    {
        y=a;
    }
    if (WordExists("B", letter))
    {
        y=b;
    }
    if (WordExists("C", letter))
    {
        y=c;
    }
    if (WordExists("D", letter))
    {
        y=d;
    }
    if (WordExists("E", letter))
    {
        y=e;
    }
    if (WordExists("F", letter))
    {
        y=f;
    }
    if (WordExists("G", letter))
    {
        y=g;
    }
    if (WordExists("H", letter))
    {
        y=h;
    }
    if (WordExists("I", letter))
    {
        y=i;
    }
    if (WordExists("J", letter))
    {
        y=j;
    }
    return y;
}
/*
 This function is used to determine if the placement is valid
 */
bool placevalid(int x, int y, bool is_vertical, int length, char ** board)
{
   
    if (is_vertical)                        // if the orientation is vertical
    {
        if (OutofBounds(x, y+length))       // determines if the ship will be out of bounds
        {
            return  false;
        }
        for (int ii=y; ii<y+length; ii++)
        {
          
            if (board[ii][x]!='-')
            return false;
        }
    }
    else if (!is_vertical)                       // if the orientation is horizontal
    {
        if (OutofBounds(x+length,y))
        {
            return false;
        }
        for (int ii=x; ii<x+length; ii++)   // determines if the ship will be out of bounds
        {
            
            if (board[y][ii]!='-')
            return false;
        }
    }
    return true;
}
void placePiece_Begin(bool is_vertical, char ** board, int length)
{
    int x ;
    enum row y;
    char *letter = malloc(sizeof(char)*1);
    bool placed=false;
    
    printf("Please pick the coordinates that you would like to place your piece at (in the format of A #: ");
  
    
    scanf("%s", letter);
    
    
    scanf("%d", &x);
    
    y = convert(letter);
    
    
    while (!placed)
    {
        if (placevalid(x,y,is_vertical, length, board))
        {
            if (!is_vertical)               // determines if artifact will be vertical
                    {
                
                    for (int jj = x; jj<x+length; jj++)
                    {
                        placed=true;
                        board[y][jj] = length+48;
                    }
                }
            
                else if (is_vertical)
                    {
                    for (int jj = y; jj<y+length; jj++)
                    {
                        placed=true;
                        board[jj][x] = length+48;
                        }
                    
                }
                else
                {
                    printf("Those coordinates didn't work. Please try picking the coordinates again (in the format of A#");
                   scanf("%s", letter);
             scanf("%d", &x);
            
            y = convert(letter);
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
    int hitAC=0;
    int hitBAT=0;
    int hitSub=0;
    int hitDes=0;
    int hitPB=0;
    char *response = malloc(Ship_Size);
    
    printf("Please type the number of the piece that you would like to place?\n");
  
    while (num_picked<5)
    {
   displayBoard(board);
      
      if (!piece1)
        printf("1: AIRCRAFT\n");
        if (!piece2)
        printf("2: BATTLESHIP \n");
        if (!piece3)
         printf("3: SUBMARINE \n");
        if (!piece4)
              printf("4: DESTROYER \n");
        if (!piece5)
        printf("5: PATROL BOAT \n");
        if (!piece1 || !piece2 || !piece3 || !piece4 || !piece5)
        {
            scanf("%d", &piece);
        }
         if (piece==1)
        {
            piece1=true;
            num_picked++;
            hitAC++;
        }
        if (piece==2)
        {
            piece2=true;
            num_picked++;
            hitBAT++;
        }
        if (piece==3)
        {
            piece3=true;
            num_picked++;
            hitSub++;
        }
        if (piece==4)
        {
            piece4=true;
            num_picked++;
            hitDes++;
        }
        if (piece==5)
        {
            piece5=true;
            num_picked++;
            hitPB++;
        }
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
int displayMenu()
{
    
    char **board, ** searchBoard;
    
    board = newBoard();     // initialize board
    
    bool startGame=false;
    
    searchBoard = newBoard();    // that is the board the computer will see
    int num=0;
    
    printf("Please select an option.\n");
    printf("1: Start a new Game\n");
    printf("2: Display Board\n");
    printf("3: Cancel Game\n");
    printf("4: Display the introduction again\n");
    printf("5: Quit\n\n\n");
    
    scanf("%d", &num);
    
    if (num==1)
    {
        startGame=true;
        // print top row of numbers
        PickPiece(board);                   // this will allow you to select the ships
        // return contents;
        
    }
    else if (num==2 && startGame)
    {
        displayBoard(board);
    }
    else if (num==2)
    {
        printf("You have not started the game yet. Please start the game\n");
    }
    else if (num==3 && startGame)
    {
        deleteBoard(board, searchBoard);
        return 0;
    }
    else if (num==3)
    {
        return 0;       // return to server menu
    }
    else if (num==4)
    {
        introduction();
    }
    
    else if (num==5)
    {
        deleteBoard(board, searchBoard);
        exit(0);
    }
    else{
        printf("Your answer was unrecognizable. Please try again\n\n\n");
    }
    
    return num;
}

int main(void)
{
       
    int num;
    char *answer = malloc(sizeof(char)*1);
    printf("Do you want to read the introduction? (y/n)");
    scanf("%c", answer);
    
    if (WordExists(answer, "y"))
    {
        introduction();
    }
    
    do {
        num=displayMenu();
    } while (num==2);
    num = displayMenu();
}
    char ** board = newBoard();
    
    // print top row of numbers
    PickPiece(board);
   // return contents;
    
    displayBoard(board);

}
