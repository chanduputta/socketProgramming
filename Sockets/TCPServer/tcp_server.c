#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {
	char server_message[256] = "You have reached the Server!";

	// create the server socket
	int server_sock;
	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_sock, (struct sockaddr*) &server_address, sizeof(server_address));

	listen(server_sock, 5);

	int client_sock;
	client_sock = accept(server_sock, NULL, NULL);

	// send the message
	send(client_sock, server_message, sizeof(server_message), 0);
	
	// close the socket
	close(server_sock);

	return 0;
}

