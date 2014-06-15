#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *str_split(char *s, char *b);

int main(void)
{
  char s[] = "a+b/c++d";
  char b[] = "+/";
  puts(str_split(s,b));
  return 0;
}

char *str_split(char *s, char *b) {
  int i,j;
  static char *t;
  t = (char *)malloc((strlen(s)+1)*sizeof(char));
  for (i = 0; s[i] != '\0'; i++) {
    t[i] = s[i];
  }
  for (i = 0; b[i] != '\0'; i++) {
    for (j = 0; s[j] != '\0'; j++) {
      if(s[j] == b[i]) t[j] = ' ';
    }
  }
  return t;
}
