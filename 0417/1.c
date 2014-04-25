#include <stdio.h>
#define MAX 30 //long型の限界に近い2^30まで
int main(void){
  int n; 
  long i;
  int j;
  int max; //最大サイズ
  int sum = 0; //総価値を覚える
  int tmps = 0; //サイズの和
  int tmpw = 0; //価値の和
  int item[MAX][2];
  printf("n = ");
  scanf("%d",&n); 

  if(n > MAX) return 1;

  printf("max = ");
  scanf("%d",&max);

  for(i=0;i<n;i++){
    printf("No%ld:size = ",i+1);
    scanf("%d",&item[i][0]);
    printf("No%ld:worth = ",i+1);
    scanf("%d",&item[i][1]);
  }

  for(i=0;i<(1<<n);i++){
    tmpw = 0;
    tmps = 0;
    for(j=0;j<n;j++){
      //j桁目が1であれば詰めていく
      if(((i>>j)%2) == 1){
        tmps += item[j][0];
        tmpw += item[j][1];
      }
    }

    if(tmpw > sum && tmps <= max){
      sum = tmpw; //サイズが超えてなく今まで以上の総価値なら更新
    }
  }

  printf("%d",sum);
  return 0;
}
