#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char c;
  int i = 0;
  fp = fopen(argv[1], "rb");

  if (fp == NULL) {
    printf("Failed to open %s.\n", argv[1]);
    return 1; 
  }
  fseek(fp,16,SEEK_END);
  while((c = fgetc(fp)) != EOF) 
  printf("%c",c);
  
  fclose(fp);
  return 0;
}

