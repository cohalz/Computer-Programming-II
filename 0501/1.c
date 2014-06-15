#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
int main(void)
{
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  swap(&a,&b);
  printf("%d %d",a,b);
  return 0;
}
void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

