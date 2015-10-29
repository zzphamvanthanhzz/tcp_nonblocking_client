/* 
 * File:   main.cpp
 * Author: thanhpv
 *
 * Created on October 28, 2015, 10:40 PM
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h>

#define PORT 6060    /* the port client will be connecting to */

#define MAXDATASIZE 100 /* max number of bytes we can get at once */
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in their_addr; /* connector's address information */

	if (argc != 2) {
		fprintf(stderr, "usage: client hostname\n");
		exit(1);
	}

	if ((he = gethostbyname(argv[1])) == NULL) { /* get the host info */
		herror("gethostbyname");
		exit(1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET; /* host byte order */
	their_addr.sin_port = htons(PORT); /* short, network byte order */
	their_addr.sin_addr = *((struct in_addr *) he->h_addr);
	bzero(&(their_addr.sin_zero), 8); /* zero the rest of the struct */

	if (connect(sockfd, (struct sockaddr *) &their_addr, sizeof (struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}
	/* sleep(5); */
//	while (1) {
		if (send(sockfd, "Hello, World!\n", 14, 0) == -1)
			printf("Error send %s\n", strerror(errno));
		printf("In loop \n");
//	}
	close(sockfd);

	return 0;
}
