#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 1024
#define COUNT 1024

int parse(int fd){
  int lus;
  char *sortie;
  sortie =  malloc(SIZE * sizeof(char));
  lus = read(fd, sortie, COUNT);
  int i;
  for(i=0; i<lus; i++){
    if(sortie[i] < '0'|| sortie[i] > '9'){
      return 0;
    }
  }
  return 1;
}

char* lit(int fd){
  
}

int main(int argc, char *argv[]){
  int fd = open(argv[1], O_RDONLY);
  
}
