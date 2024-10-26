#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[]){
  // error handler
  void perror(const char *s);

  // declare address
  struct sockaddr_in6 address;

  // clear the memory of the values
  memset(&address, 0, sizeof(address));

  // provide the address
  address.sin6_family = AF_INET6;
  address.sin6_port = htons(80);
  inet_pton(AF_INET6, argv[1], &address.sin6_addr);

  // create a socket
  int sfd = socket(AF_INET6,SOCK_STREAM,0);
  perror("Socket Status");
  printf("%s\n", argv[1]);

  //connect to an address
  int con = connect(sfd, (struct sockaddr *)&address, sizeof(address));
  perror("Connection Status: ");

  // send request
  // char *msg = "GET / HTTP/1.1\r\n\r\n";
  char *request = "GET / HTTP/1.1\r\n\r\n";
  // char request[4096];
  // sprintf(request, "%s", msg);
  send(sfd, request, strlen(request), 0);
  perror("Request Sent");

  //print the response
  char response[4096];
  read(sfd, response,100);
  perror("Read Status");
  printf("%s", response);
}
