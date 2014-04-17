#include <stdio.h>
int main(void){
  int n; 
  int i,j;
  printf("n = ");
  scanf("%d",&n);  
  for(i=0;i<(1<<n);i++){
    for(j=n-1;j>=0;j--){
      printf("%d",(i>>j)%2);
    }
    puts("");
  }
  return 0;
}

