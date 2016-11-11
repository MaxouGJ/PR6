#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "tutor.h"

int main(int argc, char *argv[]){
  int sock = socket(PF_INET, SOCK_STREAM, 0);
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(_SRV_PORT);
  address_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  int r = bind(sock, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));
  if(r==0){
    r=listen(sock,0);
    printf("Je commence ma life les gars...\n");
    struct tutor **tutors = malloc(sizeof(struct tutor**));
    int taille = init_tutors("testlist.txt", tutors);

    while(1){
      struct sockaddr_in caller;
      socklen_t size = sizeof(caller);
      int *sock2 = (int *)malloc(sizeof(int));
      *sock2 = accept(sock, (struct sockaddr *)&caller, &size);
      printf("J'accepte quelqu'un les gars !\n");
      if(sock2>=0){
        char buffer[_MSG_MAXLENGTH];
        int recu = read(*sock2, buffer, (_MSG_MAXLENGTH-1)*sizeof(char));
        buffer[recu] = '\0';
        printf("Message reçu : %s\nTaille : %d\n", buffer, recu);
        char *copie = malloc(sizeof(*buffer));
        strcpy(buffer, copie);
        char *p1 = strchr(buffer, ' ');
        char *p2 = strchr(buffer, ' ');
        if(p1){*p1 = '\0';}
        if(p2){*p2 = '\0';}

        if(strcmp(buffer, _CMD_QUIT) == 0){
          close(*sock2);
        }else if(strcmp(buffer, _CMD_LIST)){
          write(*sock2, &taille, sizeof(taille));
          printf("Envoie de : %d\n", taille);
          struct tutor *cur_tutor = *tutors;
          char *w = malloc(200*sizeof(char));
          while(cur_tutor != NULL){
            sprintf(w, "<%s> <%s>\n", cur_tutor->id, cur_tutor->subj);
            write(*sock2, w, strlen(w));
            printf("Envoie de : %s\n", w);
            cur_tutor = cur_tutor->next;
          }
        }else if(strcmp(buffer, _CMD_ACQ_I) == 0){
          if(p1){
            printf("%s\n", copie);
          }
        }else if(strcmp(buffer, _CMD_ACQ_S) == 0){
          if(p1){
            printf("%s\n", copie);
          }
        }else if(strcmp(buffer, _CMD_REL) == 0){
          if(p1 && p2){
            printf("%s\n", copie);
          }
        }
      }
    }
  }
  return 0;
}

/*void *dict(void *arg){
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
*/
