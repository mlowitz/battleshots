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
                         fork();
            // start server function
            while (isdigit(IP))
            {
                prinf("Please enter the IP Address");
                
                scanf("%d", IP);
            }
            
            memset(recvBuff, '0',sizeof(recvBuff));
            if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                printf("\n Error : Could not create socket \n");
                return 1;
            }
            
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(5000);
            
            if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            {
                printf("\n Error : Connect Failed \n");
                return 1;
            }
            
            while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
            {
                recvBuff[n] = 0;
                if(fputs(recvBuff, stdout) == EOF)
                {
                    printf("\n Error : Fputs error\n");
                }
            }
        }
    
        if (num==2)
        {
            
            IP=atoi("127.0.0.1");
            
            memset(recvBuff, '0',sizeof(recvBuff));
            if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                printf("\n Error : Could not create socket \n");
                return 1;
            }
            
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(5000);

            if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            {
                printf("\n Error : Connect Failed \n");
                return 1;
            }
            
            while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
            {
                recvBuff[n] = 0;
                if(fputs(recvBuff, stdout) == EOF)
                {
                    printf("\n Error : Fputs error\n");
                }
            }
        }
    
        if (num==3)
        {
            introduction();
        }
    
    } while(num<4);
    
    
    return 0;
}

