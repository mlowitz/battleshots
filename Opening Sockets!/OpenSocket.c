#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>


int PromptOpenSocket()
{
    struct sockaddr_in saddr; /* structure to hold an IP address */ 
    int clientSocket; /* socket descriptor */ 
    struct hostent *ptrh; /* pointer to a host table entry */  
    char *host;
	char buff[1024];
    char *port1;
	int port;
	host = (char *)malloc(1024 * sizeof(char));
	port1 = (char *)malloc(1024 * sizeof(char));

	printf ("Enter your the IP, please: ");
	fflush (stdout);
	scanf("%s", host);
	
	printf ("Enter your the port, please: ");
	fflush (stdout);
	scanf("%s",port1);
	
	port = atoi(port1);
	
	

    clientSocket = socket(AF_INET, SOCK_STREAM, 0); 
    
    memset((char *)&saddr,0,sizeof(saddr)); /* clear sockaddr structure */ 
    
    saddr.sin_family = AF_INET; /* set family to Internet */ 
    
    saddr.sin_port = htons((u_short)port); 
    
    ptrh = gethostbyname(host); /* Convert host name to IP address */
    
    memcpy(&saddr.sin_addr, ptrh->h_addr, ptrh->h_length);
    
    connect(clientSocket,(struct sockaddr *)&saddr, sizeof(saddr));
    

	
    return(clientSocket);
	return (0);
}

