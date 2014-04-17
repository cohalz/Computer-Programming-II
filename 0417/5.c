#include <stdio.h>
int f[1000] = {0};
int fib(int n){
  if(f[n] != 0) return f[n];
  else if(n <= 1) return 1;
  else {
    f[n] = fib(n-1) + fib(n-2);
    return f[n];
  }
}
int main(void){
  int n; 
  printf("n = ");
  scanf("%d",&n);
  printf("%d",fib(n));
  return 0;
}

