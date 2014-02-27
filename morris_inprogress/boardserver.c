#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "board.h"
/*ip address of the server is the bord number/ name 
or game number */
int main(int argc, char *argv[])
{
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;

	char sendBuff[1025];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	listen(listenfd, 10);
	while (1)
	{
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

		ticks = time(NULL);
		snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
		write(connfd, sendBuff, strlen(sendBuff));
		/*listen and repond 
		if mode = s setting board*/
		/*
		
		listening mode 
		function  will receice and insert value to table */

				//insert functiong using peice added 

						//write to 
					//if response = 0 successsuccessfully placed and add to array
					//if = 1 error try again 
					//
		//read function 
			//listen for move 
			//return int of ship 
		close(connfd);

		sleep(1);
	}
}