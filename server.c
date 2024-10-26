#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[]){
  //error handler
  void perror(const char *s);

  //address
  socklen_t addr_len;
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(8000);
  inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);

  //socket
  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  perror("Socket Status");

  //bind
  int b = bind(sfd, (struct sockaddr *)&address, sizeof(address));
  perror("Bind Status");

  //listen
  int l = listen(sfd, 10);
  perror("Listen Status");

  //accept
  int a = accept(sfd, (struct sockaddr *)&address, &addr_len);
  perror("Accept Status");
  // printf("%d", a);
  
  //connect
  // int c = connect(sfd, (struct sockaddr *)&address, addr_len);
  // perror("Connect Status");

  //read
  char response[100];
  read(a, response, sizeof(response));
  printf("%s", response);

  //send reply
  char *reply = "Hello there\n";
  send(a, reply, strlen(reply), 0);

}
