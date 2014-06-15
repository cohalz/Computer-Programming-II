#include <stdio.h>
#include <stdlib.h>


char* readStr(int n,FILE *fp) {
  int ch;
  char *p;

  ch = fgetc(fp);
  if (ch == EOF || ch == '\n') {
    p = (char *)malloc(sizeof(char) * (n + 1));
    if (p == NULL) 
      return NULL;
    else { 
      p[n] = '\0';
      return p;
    }
  } else {
    p = readStr(n + 1,fp);
    p[n] = ch;
    return p;
  }
}
char* readLine(FILE *fp) {
  char *c;
  c = readStr(0,fp);
  return c;
}
