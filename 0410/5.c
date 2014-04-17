#include <stdio.h>
void rec(int n) {
  int m,i;
  if(n <= 0) return;
  else {
    scanf("%d",&m);
    rec(m);
    for(i = 0; i< n;i++){
      printf("+");
    }
    puts("");
  }
}
int main(){
  int n;
  scanf("%d", &n);
  rec(n);
}


