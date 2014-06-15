#include <stdio.h>
#include <stdlib.h>
int *memo;
int catalan(int n) {
  int i;
  if(memo[n] != 0) return memo[n];
  if(n == 0 || n == 1) return 1;
  for (i = 0; i < n; i++) {
    memo[n] += catalan(i)*catalan(n-i-1);
  }
  return memo[n];
}
int main(void){
  int n;
  int i;
  scanf("%d",&n);
  memo = (int *)malloc(n * sizeof(n));
  for (i = 0; i < n; i++) {
    memo[i] = 0;
  }
  printf("%d",catalan(n));
  return 0;
}

