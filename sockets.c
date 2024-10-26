#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>

#define LISTEN_BACKLOG 50

int main() {
  socklen_t peer_addr_size;
  struct sockaddr_in my_addr;

  void perror(const char *str);
  int sfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&my_addr, 0, sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(8080);
  if (bind(sfd, (struct sockaddr* )&my_addr, sizeof(my_addr)) != 0)
    perror("Bind Error: ");

  for ( ; ; ) {
    if (listen(sfd, LISTEN_BACKLOG) != 0)
      perror("Listen Error: ");
  }

}




