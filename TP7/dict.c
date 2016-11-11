#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

char * dict(char *mot){
  char *definition;

  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(2628);
  inet_aton("194.254.199.30", &address_sock.sin_addr);

  int descr = socket(PF_INET, SOCK_STREAM, 0);
  int r = connect(descr, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));

  if(r != -1){
    printf("Connexion.\n");

    char buff[1024];
    int size_rec = read(descr, buff, 1023*sizeof(char));


    char *req = malloc(100*sizeof(char));
    sprintf(req, "DEFINE wn %s\n", mot);
    printf("Ecriture de %s\n", req);
    write(descr, req, strlen(req));
    //send(descr, req, strlen(req), 0);
    printf("Ecriture de %s réussie\n", req);

    char buffer[2048];
    while(1){
      size_rec = read(descr, buffer, 2047*sizeof(char));
      buffer[size_rec]='\0';
      printf("%s", buffer);
    }
    definition = buffer;
  }else{
    printf("Problème de connexion.\n");
  }

  close(descr);
  return definition;
}

int main(int argc, char *argv[]){
  printf("%s : %s", argv[1], dict(argv[1]));
  return 0;
}
