#include <stdio.h>
int main(void){ 
  FILE *fp;
  char c;
  int count = 0;
  if((fp = fopen("file.txt", "r")) == NULL) { 
    puts("failed to open member.txt."); 
    return 1;
  }
  c = fgetc(fp);
  while(!feof(fp)) {
    if(c == '\n') count++;
    c = fgetc(fp);
  }
  printf("%d\n",count);
  fclose(fp);
  return 0;
}

