#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printrank(int prev);

int main(void){
  printrank(INT_MAX);
  return 0;
}

void printrank(int prev) {
  int rank;
  static int flag = 0;

  scanf("%d",&rank);

  if(rank < 0) return;
  printrank(rank);

  if(flag == 1) {
    flag = 0;
    return;
  }

  if(rank < prev) printf("%d ",rank);
  else printf("%d ",prev);
  flag = 1;
}
