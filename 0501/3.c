#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_rev(char *str);
void null(char *str);
void mystrcpy(char *str1, char *str2);
int main(void){
  char *str = "abc";
  char *str2 = "def";
  /* print_rev(str); */
  /* null(str); */
  /* puts(str); */
  mystrcpy(str,str2);
  puts(str2);
  return 0;
}
void null(char *str) {
  str[0] = '\0';
  puts(str);
}

void print_rev(char *str) {
  int i;
  int n = strlen(str);
  for (i = n-1; i >= 0; i--) {
    printf("%c",str[i]);
  }
}

void mystrcpy(char *str1, char *str2) {
  int i;
  for (i = 0; str1[i] != '\0'; i++) {
    if(str2[i] == '\0') break;
    str2[i] = str1[i];
  }
}
