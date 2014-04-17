#include <stdio.h>
void hanoi(int n, char s, char d, char a){
  if(n == 1) printf("more dist %d from pole %c to pole %c",n,s,d);
  else {
    hanoi(n-1,s,a,d);
    printf("more dist %d from pole %c to pole %c",n,s,d);
    hanoi(n-1,a,d,s);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  hanoi(n);
}

