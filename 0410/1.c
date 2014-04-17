#include <stdio.h>
#define MaxDigits 9
int main(){
  long long int n;
  int i = 0;
  int j;
  int arr[MaxDigits/3];
  scanf("%lld",&n);
  while(n >= 0) {
    while(n>0){
      arr[i] = n%1000;
      n/= 1000;
      i++;
    }
    for(j = i-1;j>=0;j--){
      if(j == i-1){
        printf("%d",arr[i]);
      }else printf(",%03d",arr[j]);
    }
    scanf("%lld", &n);
  }
  return 0;
}

