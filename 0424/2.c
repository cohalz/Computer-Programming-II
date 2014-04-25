#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int n; // 整数の個数を覚えるための変数

int *p; // n個の整数を覚えるためのメモリを指すポインタ

int *route; // 最短ルートを覚える配列

int **distance; // 2点間の距離を覚える2次元配列

int mind = INT_MAX; // 最小距離を覚える変数

void enumerate(int k); // 順列を列挙する関数

void getMemory(int n); // 必要な配列のメモリを確保する関数

void inputDistance(int n); // 2点間距離を入力する関数

int salesman(); // 現在の順列での総距離を求める関数

int main() {
  int i;

  printf("n = ");
  while(scanf("%d", &n) != 1 || n < 1) {
    puts("Wrong input.");
    printf("n = ");
    while(getchar() != '\n');
  }
  
  getMemory(n);
  
  // 順列に初期値を入れる
  for (i = 0;i<n;i++) {
    p[i] = i + 1;
  }

  inputDistance(n);
  
  // 順列を全列挙して最小値を求める
  enumerate(0);

  // ルートと最小値を表示
  for (i = 0; i < n-1; i++) {
    printf("%d->",route[i]);
  }
  printf("%d\n",route[n-1]);
  printf("min = %d",mind);

  free(p);
  free(route);
  free(distance);

  return 0;
}

void getMemory(int n) {
  int i;
  // prefixのメモリを確保
  p = (int *)malloc( n * sizeof(int) ); 
  if(p == NULL) { 
    puts("Out of memory.");
    exit(1);
  }
   // prefixのメモリを確保
  route = (int *)malloc( n * sizeof(int) ); 
  if(route == NULL) { 
    puts("Out of memory.");
    exit(1);
  } 

  // distanceのメモリを確保
  distance = (int **)malloc( n * sizeof(int *));
  for(i = 0;i < n;i++) {
    distance[i] = (int *)malloc( n * sizeof(int));
  }
  if(distance == NULL) { 
    puts("Out of memory.");
    exit(1);
  }
}

void inputDistance(int n) {
  int i,j;
  // 2点間距離の入力
  // distance[i][j]でiからjへの距離
  // 1から2の距離と2から1の距離は同じなので最後に代入
  for(i = 0;i < n-1;i++) {
    for(j = i+1;j < n;j++) {
      printf("from %d to %d distance = ",i+1,j+1);
      while(scanf("%d",&distance[i][j]) != 1) {
        puts("Wrong input.");
        printf("from %d to %d distance = ",i+1,j+1);
        while(getchar() != '\n');
      }
      distance[j][i] = distance[i][j];
    }
  }  
}

int salesman() {
  int sumd = 0; // その順列での距離を覚える
  int i;

  for(i = 0; i < n-1; i++) {
    sumd += distance[p[i]-1][p[i+1]-1];
  }
  sumd += distance[p[0]-1][p[n-1]-1]; // 最後の地点から最初に戻る距離を足す。
  return sumd;
}

void enumerate(int k) {
  int i,j,temp;
  int d;

  /* 易しい場合 */
  /* 順列が完成した時にsalesmanを呼ぶ */
  if(k == n) { 
    d = salesman();
    if(d < mind) {
      mind = d;
      for (j = 0; j < n; j++) {
        route[j] = p[j];
      }
    }
  }

  /* 難しい場合 */
  /*  配列の未固定部分の先頭をしらみつぶしに固定して
    問題の規模を1つ小さくしてから，再帰的に列挙する */
  for(i = k ;  i < n ; i++) { 
    /* 配列の未固定部分の先頭から数えて(k-i+1)番目の要素を
      配列の未固定部分の先頭と入れ替える */
    temp = p[k];
    p[k] = p[i];
    p[i] = temp;

    /* 配列の未固定部分の先頭を固定して再帰的に列挙する */
    enumerate(k + 1); 

    /* 次の選択肢を試すために，直前の選択肢で移動した要素を
      配列の元の位置に戻す */
    temp = p[k];
    p[k] = p[i];
    p[i] = temp;
  }
}
