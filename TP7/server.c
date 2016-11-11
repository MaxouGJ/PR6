#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void *dict(void *arg){
  int sockcomm = *((int *)arg);

  char *mot;
  scanf("%s", mot)
  char tab[50];
  char *res="";
  int i=1;
  int taille_entree = strlen(argv[1]);
  char *appel = malloc((6+taile_entree)*sizeof(char));
  strcpy(appel, "dict");
  strcat(appel, argv[1]);
  FILE *f = popen(appel, "r");
  while(fgets(tab, 50, f)!=NULL){
    char *temp = res;
    res = malloc(i*50*sizeof(char));
    strcpy(res, temp);
    strcat(res, tab);
    i++;
  }
  printf("Résultat %s\n", res);
  free(appel);
  free(res);

}

int main(int argc, char *argv[]){
  int sock = socket(PF_INET, SOCK_STREAM, 0);
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(4242);
  address_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  int r = bind(sock, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));
  if(r==0){
    r=listen(sock,0);
    while(1){
      struct sockaddr_in caller;
      socklen_t size = sizeof(caller);
      int *sock2 = (int *)malloc(sizeof(int));
      *sock2 = accept(sock, (struct sockaddr *)&caller, &size);
      if(sock2>=0){
        pthread_t th;
        pthread_create(&th, NULL, dict, sock2)
      }
      close(sock2);
    }
  }
  return 0;
}
