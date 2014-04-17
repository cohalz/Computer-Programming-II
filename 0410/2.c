#include <stdio.h>
#define MaxDigits 9
void rec(int n);
int main(){
  int n;
  scanf("%d",&n);
  while(n >= 0) {
    rec(n);
    scanf("%d", &n);
  }
  return 0;
}

void rec(int n) {
  if(n < 1000) printf("%d",n);
  else {
    rec(n/1000);
    printf(",%03d",n%1000);
  }
}
