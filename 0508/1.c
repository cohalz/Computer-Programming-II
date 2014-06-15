#include <stdio.h>
#include <stdlib.h>
char* readLine();
int main() {
  char *str;
  str = (char *)malloc(sizeof(char));
  str = readLine();
  if(str == NULL) return 1;
  puts(str);
  free(str);
  return 0;
}

char* readLine() {
  int i = 1;
  char *p;
  char *q;
  char c;
  while((c = getchar()) != EOF && c != '\n') {
    i++;
    q = (char *)realloc(p,i * sizeof(char));
    if(q == NULL){
      free(p);
      return NULL;
    }
    p = q;
    q[i-2] = c;
    q[i-1] = '\0';
  }
  return p;
}
