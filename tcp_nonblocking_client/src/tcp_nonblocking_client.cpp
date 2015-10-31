/* 
 * File:   main.cpp
 * Author: thanhpv
 *
 * Created on October 28, 2015, 10:40 PM
 */
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#define MAXHOSTNAME 256
using namespace std;

main() {
	struct sockaddr_in remoteSocketInfo;
	struct hostent *hPtr;
	int socketHandle;
	const char *remoteHost = "127.0.0.1";
	int portNumber = 8081;

	bzero(&remoteSocketInfo, sizeof (sockaddr_in)); // Clear structure memory

	// Get system information

	if ((hPtr = gethostbyname(remoteHost)) == NULL) {
		cerr << "System DNS name resolution not configured properly." << endl;
		cerr << "Error number: " << ECONNREFUSED << endl;
		exit(EXIT_FAILURE);
	}

	// create socket

	if ((socketHandle = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		close(socketHandle);
		exit(EXIT_FAILURE);
	}

	// Load system information into socket data structures

	memcpy((char *) &remoteSocketInfo.sin_addr, hPtr->h_addr, hPtr->h_length);
	remoteSocketInfo.sin_family = AF_INET;
	remoteSocketInfo.sin_port = htons((u_short) portNumber); // Set port number

	if (connect(socketHandle, (struct sockaddr *) &remoteSocketInfo, sizeof (sockaddr_in)) < 0) {
		close(socketHandle);
		exit(EXIT_FAILURE);
	}

	int rc = 0; // Actual number of bytes read by function read()
	char buf[512];
	char rev_buf[512];
	strcpy(buf, "Message to send");
	send(socketHandle, buf, strlen(buf) + 1, 0);
	rc = recv(socketHandle, rev_buf, strlen(buf) + 1, 0);
	
	printf("Receive data: %s\tSize of data: %d\n", rev_buf, rc);
}


