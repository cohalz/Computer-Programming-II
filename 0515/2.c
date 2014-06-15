#include <stdio.h>
#include <stdlib.h>
void printdiv(int n) {
  int num;
  int count = 0;
  int i;
  scanf("%d",&num);
  if(n != 1) {
    printdiv(n-1);
  }
  for (i = 1; i <= num; i++) {
    if(num%i == 0) {
      count++;
    }
  }
  printf("%d ",count);
}

int main() {
  int n;
  scanf("%d",&n);
  printdiv(n);
  return 0;
}
