#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printrank(int prev1, int prev2);

int main(void){
  printrank(INT_MAX,INT_MAX);
  return 0;
}

void printrank(int prev1, int prev2) {
  int rank;
  static int flag = 0;
  scanf("%d",&rank);

  if(rank < 0) return;
  printrank(rank,prev1);
  if(flag != 0) {
    flag--;
    return;
  }

  if(rank <= prev1 && rank <= prev2)       printf("%d ", rank);
  else if(prev1 <= rank && prev1 <= prev2) printf("%d ", prev1);
  else                                     printf("%d ", prev2);
  flag = 2;
}

