#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
int main() {
  char *str;
  char *input;
  char *tmp;
  int input_length = 0;
  int str_length = 0;
  int i;
  input = (char *)malloc(MAX * sizeof(char));
  if(input == NULL) return 1;

  fgets(input,MAX,stdin);

  str = (char *)malloc((strlen(input)+1) * sizeof(char));
  str[strlen(str)-1] = '\0'; //改行文字を消す
  if(str == NULL) return 1;

  strcpy(str,input);
  tmp = str;

  while(strcmp(input,"quit\n") != 0) {
    str = tmp; //もしquitが入力されていなければstrに入力した文字を追記する
    for (i = 0; input[i] != '\0'; i++) {
      str[str_length+i] = input[i];
    }

    str[strlen(str)-1] = '\0'; //最後の改行文字を消す
    fgets(input,MAX,stdin);

    str_length = strlen(str);

    tmp = (char *)realloc(str, (str_length + strlen(input)+1) * sizeof(char));
    if(tmp == NULL) return 1;
  }

  if(strcmp(str,"quit\n") == 0) str[0] = '\0';
  puts(str);

  free(str);
  free(input);
  return 0;
}

