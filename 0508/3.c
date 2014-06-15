#include <stdio.h>
#include <stdlib.h>

char* readLine(int n);
int main(void)
{
  char *str;
  str = readLine(0);
  puts(str);
  return 0;
}

char* readLine(int n) {
  char c;
  char *str;
  c = getchar();
  if(c != '\n') {
    readLine(n+1);
  }else {
    str = (char *)malloc((n+1) * sizeof(char));
  }
  str[n] = c;
  return str;
}
