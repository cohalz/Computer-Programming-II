#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* readLine();
char* readStr(int n);

int main(void){
  int n;
  int i;
  char **str;
  scanf("%d",&n);
  while(getchar() != '\n');
  str = (char **)malloc(n * sizeof(char *));
  for (i = 0; i < n; i++) {
    str[i] = (char *)malloc(64 * sizeof(char));
  }
  for (i = 0; i < n; i++) {
    str[i] = readLine();
  }
  for (i = 0; i < n; i+=2) {
    printf("%s ",str[i]);
  }
  for (i = 1; i < n; i+=2) {
    printf("%s ",str[i]);
  }
  return 0;
}

char* readStr(int n) {
  int ch;
  char *p;

  ch = getchar();
  if (ch == EOF || ch == '\n') {
    p = (char *)malloc(sizeof(char) * (n + 1));
    if (p == NULL) 
      return NULL;
    else { 
      p[n] = '\0';
      return p;
    }
  } else {
    p = readStr(n + 1);
    p[n] = ch;
    return p;
  }
}
char* readLine() {
  char *c;
  c = readStr(0);
  return c;
}
