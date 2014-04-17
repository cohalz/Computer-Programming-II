#include <stdio.h>
#include <stdlib.h>
int main(void){
  int n,i,j;
  scanf("%d",&n);
  int *num;
  num = (int *)malloc(sizeof(int) * n);
  for(i=0;i<n;i++){
    num[i] = 0;
  }
  for(i=0;i<n;i++){
    if(num[i] == 0){
      num[i] = 1;
      for(j = i-1;j>=0;j--){
        num[j] = 0;
      }
    }
    for(j=0;j<n;j++){
      printf("%d",num[i]);
    }
    puts("");
  }
  
  return 0;
}
