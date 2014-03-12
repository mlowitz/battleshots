

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server_functions.h"
#include "board.h"
#define BUFSIZE 1024

#ifndef boardserver.c
#define boardserver.c 


#if 0
/*
* Structs exported from netinet/in.h (for easy reference)
*/

/* Internet address */
struct in_addr {
	unsigned int s_addr;
};

/* Internet style socket address */
struct sockaddr_in  {
	unsigned short int sin_family; /* Address family */
	unsigned short int sin_port;   /* Port number */
	struct in_addr sin_addr;	 /* IP address */
	unsigned char sin_zero[...];   /* Pad to size of 'struct sockaddr' */
};

/*
* Struct exported from netdb.h
*/

/* Domain name service (DNS) host entry */
struct hostent {
	char    *h_name;        /* official name of host */
	char    **h_aliases;    /* alias list */
	int     h_addrtype;     /* host address type */
	int     h_length;       /* length of address */
	char    **h_addr_list;  /* list of addresses */
}
#endif

/*
* error - wrapper for perror
*/
void error(char *msg) {
	perror(msg);
	exit(1);
}

int server(int argc, char **argv) {
	int listenfd; /* listening socket */
	int connfd; /* connection socket */
	int portno; /* port to listen on */
	int clientlen; /* byte size of client's address */
	struct sockaddr_in serveraddr; /* server's addr */
	struct sockaddr_in clientaddr; /* client addr */
	struct hostent *hostp; /* client host info */
	char buf[BUFSIZE]; /* message buffer */
	char *hostaddrp; /* dotted decimal host addr string */
	int optval; /* flag value for setsockopt */
	int n; /* message byte size */

	if (fork() ==0)
	  {	  
	/* check command line args */
       
	portno = atoi(80);

	/* socket: create a socket */
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0)
		error("ERROR opening socket");

	/* setsockopt: Handy debugging trick that lets
	* us rerun the server immediately after we kill it;
	* otherwise we have to wait about 20 secs.
	* Eliminates "ERROR on binding: Address already in use" error.
	*/
	optval = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
		(const void *)&optval, sizeof(int));

	/* build the server's internet address */
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET; /* we are using the Internet */
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); /* accept reqs to any IP addr */
	serveraddr.sin_port = htons((unsigned short)portno); /* port to listen on */
	
	/* bind: associate the listening socket with a port */
	if (bind(listenfd, (struct sockaddr *) &serveraddr,
		sizeof(serveraddr)) < 0)
		error("ERROR on binding");

	/* listen: make it a listening socket ready to accept connection requests */
	if (listen(listenfd, 5) < 0) /* allow 5 requests to queue up */
		error("ERROR on listen");

	/* main loop: wait for a connection request, echo input line,
	then close connection. */
	clientlen = sizeof(clientaddr);
	board *board = board_create(16777216);
	char* status=malloc(2*sizeof(char*));                                                                                                                         
	char* player=malloc(2*sizeof(char*));                                                                                                                         
	char* positon=malloc(2*sizeof(char*));                                                                                                                        
	char*ship = malloc(1*sizeof(char*));              
	while (1) {
	  
    
		
	        
		/* accept: wait for a connection request */
		connfd = accept(listenfd, (struct sockaddr *) &clientaddr, &clientlen);
		if (connfd < 0)
			error("ERROR on accept");

		/* gethostbyaddr: determine who sent the message */
		hostp = gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
			sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		if (hostp == NULL)
			error("ERROR on gethostbyaddr");
		hostaddrp = inet_ntoa(clientaddr.sin_addr);
		if (hostaddrp == NULL)
			error("ERROR on inet_ntoa\n");
		printf("server established connection with %s (%s)\n",
			hostp->h_name, hostaddrp);


		/* read: read input string from the client */
		bzero(buf, BUFSIZE);
		n = read(connfd, buf, BUFSIZE);
		if (n < 0)
			error("ERROR reading from socket");
		printf("server received %d bytes: %s", n, buf);
		//data to be sent to server in format 
		//[R/W]XYP[1/2]
		/*if sent data is enter*/
		if (buf[0] == 'W')
		{	
			/*
			*function to place peice in server
			*/
		  char* player=malloc(2*sizeof(char*));
		  char* positon=malloc(2*sizeof(char*));
		  char* ship = malloc(1*sizeof(char*));
		  
			player = playerNum(buf);//get player number
			position = parsePosition(buf);//get position 
			ship = shipnum(buf); 
			status =  board_put(board, position, player, ship);
			

			
		}
	
		elseif(buf[0] == 'R')
		{
			/*
			*function to read from server 
			*/
			player = playerNum(buf);//get player number
			position = parsePosition(buf);//get position
			status = board_get(board, position, player);
			
		}
		else
		{
			//retrun error in reading from server 
		}
		strcpy(buf,status);
		n = write(connfd, buf, strlen(buf));
		if (n < 0)
			error("ERROR writing to socket");

		close(connfd);
	}
	  }
	else{
	exit(0);
	}
}

#endif
