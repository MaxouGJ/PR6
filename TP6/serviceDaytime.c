#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

void print_nom1(){
  struct hostent *host;//Structure contenant le nom, la liste des ip...
  host = gethostbyname("lucien.informatique.univ-paris-diderot.fr");//Rempli la structure de type hostent
  if(host == NULL){
    printf("UNKNOWN HOST\n");
  }
  else{
    printf("Nom : %s\n", host->h_name);//Ecrit le nom de l'host
    struct in_addr **addresses = (struct in_addr**)host->h_addr_list;//On déclare une structure de type adresse
    while(*addresses != NULL){//Parcourt de la liste des adresses
      printf("Address :%s\n", inet_ntoa(**addresses));
      addresses++;
    }
  }
}

void print_nom2(){
  struct addrinfo *first_info;
  int r = getaddrinfo("lucien.informatique.univ-paris-diderot.fr", "daytime", NULL, &first_info);
  printf("Nom : %s\n", first_info->ai_canonname);
  if(r==0){
    struct addrinfo *info = first_info;
    while(info != NULL){
      struct sockaddr *saddr = info->ai_addr;
      if(saddr->sa_family == AF_INET){
        struct sockaddr_in *addressin = (struct sockaddr_in *)saddr;
        struct in_addr address = (struct in_addr) (addressin->sin_addr);
        printf("Address2 : %s\n", inet_ntoa(address));
      }
      info = info->ai_next;
    }
  }
  freeaddrinfo(first_info);
}

int main(int argc, char *argv[]){

  print_nom2();

  struct hostent *host;//Structure contenant le nom, la liste des ip...
  host = gethostbyname("lucien.informatique.univ-paris-diderot.fr");//Rempli la structure de type hostent
  struct in_addr **addresses;//On déclare une structure de type adresse
  if(host == NULL){
    printf("UNKNOWN HOST\n");
  }
  else{
    printf("Nom : %s\n", host->h_name);//Ecrit le nom de l'host
    addresses = (struct in_addr**)host->h_addr_list;//On déclare une structure de type adresse
    printf("Address :%s\n", inet_ntoa(**addresses));
  }
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(13);
  address_sock.sin_addr = **addresses;

  int descr = socket(PF_INET, SOCK_STREAM, 0);
  int r = connect(descr, (struct sockaddr*)&address_sock, sizeof(struct sockaddr_in));

  if(r == -1){
    printf("ERREUR DE CONNEXION AVEC LA SOCKET\n");
  }else{
    char buff[100];
    int size_rec = recv(descr, buff, 99*sizeof(char), 0);
    buff[size_rec] = '\0';
    printf("Date : %s\n", buff);
  }

  return 0;
}
