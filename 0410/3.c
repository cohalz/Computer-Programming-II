#include <stdio.h>
#define max 999999
long long int combi[max][max] = {};
long long int rec(int n, int r);
int main(){
  int n,r;
  scanf("%d",&n);
  scanf("%d",&r);
  printf("%lld", rec(n,r));
}
long long int rec(int n, int r){
  if(combi[n][r] != 0) return combi[n][r];
  else if(r == 0 || n == r) return 1;
  else if(r == 1) return n;
  else return combi[n][r] = rec(n-1,r-1) + rec(n-1, r);
}
