#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE 1024
#define ENTREE 100

int main(int argc, char *argv[]){
  int *buffer;
  buffer = malloc(TAILLE * sizeof(int));
  int indice = 0;
  int sortie = 0;
  char *entree;
  entree = malloc(ENTREE * sizeof(int));
  while(sortie != 1) {
    scanf("%s", entree);
    if(strcmp("quit", entree) == 0){
      sortie = 1;
    }else{
      if(indice%TAILLE == 0){
	buffer = realloc(buffer, TAILLE * sizeof(int));
      }
      buffer[indice] = strtol(entree, NULL, 10);
      indice ++;
    }
  }
}
