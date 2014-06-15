#include <stdio.h>
#include <stdlib.h>
char *base2(int n);

int main() {
  int n;
  scanf("%d",&n);
  puts(base2(n));
  return 0;
}

char *base2(int n) {
  int i;
  int j = 0;
  int flag = 0;
  static char bin[12];
  for(i=10;i>=0;i--){
    if((n>>i)%2 == 0 && flag == 1) {
      bin[j-i] = '0';
    }
    else if((n>>i)%2 == 1){
      if(flag == 0) {
        flag = 1;
        j = i;
      }
      bin[j-i] = '1';
    }
  }
  return bin;
}
