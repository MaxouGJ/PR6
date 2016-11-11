#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "tutor.h"

int main(){

    struct sockaddr_in address_sock;
    address_sock.sin_family = AF_INET;
    address_sock.sin_port = htons(_SRV_PORT);
    inet_aton("0.0.0.0", &address_sock.sin_addr);

    int descr = socket(PF_INET, SOCK_STREAM, 0);
    int r = connect(descr, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));

    if(r != -1){
        printf("Connexion...\n");

        char *req = malloc(_MSG_MAXLENGTH*sizeof(char));
        char *request = malloc(_MSG_MAXLENGTH*sizeof(char));
        char *buffer = malloc(_RPLY_MAXMSGS*sizeof(char));
        int boolean = 1;
        int size_rec;

        while(boolean){
            scanf("%s", req);
            strcpy(request, req);
            char *p1 = strchr(req, ' ');
            char *p2 = strchr(req, ' ');
            char *p3 = strchr(req, ' ');

            if(p1){*p1 = '\0';}
            if(p2){*p2 = '\0';}

            printf("Request : %s\n",req);

            if(strcmp(req, _CMD_QUIT) == 0){
                boolean = 0;
                write(descr, req, strlen(request));
            }else if(strcmp(req, _CMD_LIST) == 0){
                write(descr, request, strlen(request));
                printf("Ecriture de : %s\n", request);
                size_rec = read(descr, buffer, (_RPLY_MAXMSGS-1)*sizeof(char));
                buffer[size_rec]='\0';
                buffer[sizeof(int)] = '\0';
                int n = *((int*)buffer);
                char *mot = buffer[sizeof(n)];
                printf("Nombre de personnes : %d\nReste : %s\nTaille : %d\n", n, mot, size_rec);
                int i = 0;
                //while(compteur < n)
                for(i; i<n; i++){
                    size_rec = read(descr, buffer, (_RPLY_MAXMSGS-1)*sizeof(char));
                    buffer[size_rec]='\0';
                    printf("%s", buffer);
                }
            }else if(strcmp(req, _CMD_ACQ_I) == 0){
                if(p1+1){
                    write(descr, request, strlen(request));
                    size_rec = read(descr, buffer, (_RPLY_MAXMSGS-1)*sizeof(char));
                    buffer[size_rec]='\0';
                    printf("%s", buffer);
                }
            }else if(strcmp(req, _CMD_ACQ_S) == 0){
                if(p1+1){
                    write(descr, request, strlen(request));
                    size_rec = read(descr, buffer, (_RPLY_MAXMSGS-1)*sizeof(char));
                    buffer[size_rec]='\0';
                    printf("%s", buffer);
                }
            }else if(strcmp(req, _CMD_REL) == 0){
                if(p1+1 && p2+1){
                    write(descr, request, strlen(request));
                    printf("Merci !");
                }
            }
        }
    }else{
        printf("Problème de connexion.\n");
    }

    close(descr);
}
