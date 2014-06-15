#include <stdio.h>
#include <stdlib.h>
void ma_strcat(char *str1, char *str2);
int main(void)
{
  char str1[50] = "abc";
  char str2[5] = "def";
  ma_strcat(str1,str2);
  printf("%s",str1);
  return 0;
}
void ma_strcat(char *str1, char *str2) {
  int i,j;
  for (i = 0; str1[i] != '\0'; i++) {}
  for(j = i; str2[j] != '\0'; j++) {
    str1[j] = str2[j-i];
  }
}
