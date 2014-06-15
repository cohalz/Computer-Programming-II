#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isWord(char *str);

int lessThan(char *str1, char *str2);

int isContains(char *str, char c);

int main(void) {
  char str[22];
  char *max;

  fgets(str, 22, stdin);
  if(isContains(str,'\n')) str[strlen(str)-1] = '\0';
  
  max = str;

  while (isWord(str)) {
    if(lessThan(max,str)) max = str;

    fgets(str, 22, stdin);
    if(isContains(str,'\n')) str[strlen(str)-1] = '\0';
  }

  puts(max);
  return 0;
}

int isWord(char *str) {
  int i;

  for (i = 0; str[i] != '\0'; i++) {
   if(str[i] > 'z' || str[i] < 'A' || str[i] < 'a') return 0;
  }

  return 1;
}


int lessThan(char *w1, char *w2) {
  if(strcmp(w1,w2) < 0) return 1;
  else return 0;
}

int isContains(char *str, char c) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if(str[i] == c) return 1;
  }
  return 0;
}
