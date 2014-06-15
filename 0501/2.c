#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int main(void){
  int n,i,j;
  int *num;
  scanf("%d",&n);
  num = (int *)malloc( n * sizeof(int) ); 
  for (i = 0; i < n; i++) {
    scanf("%d",&num[i]);
  }
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-1; j++) {
      if(num[j] > num[j+1]) swap(&num[j],&num[j+1]);
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d\n",num[i]);
  }
  free(num);
  return 0;
}

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
