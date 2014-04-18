#include<stdio.h>
#define MAX 128

int Item[MAX][2];
int n;  //アイテムの数
int total = 0; //総額の最大値
int maxSize; //ナップサックのサイズ
void knapsack(int tmpSumSize, int tmpSumPrice, int count){
  int i;
  //count番目から初めて、重複したものを探さないようにする。
  //今まで入れたアイテム以降で足してもサイズを超えず、一番最初のアイテムを入れていく。
  for (i = count; i < n; i++){
    if (tmpSumSize+Item[i][0] <= maxSize){
      knapsack(tmpSumSize+Item[i][0], tmpSumPrice+Item[i][1], i+1);
    }
  }
  if (total < tmpSumPrice){
    total = tmpSumPrice;
  }
}

int main(){
  int i;

  do{
    printf("How many items? -> ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX){
      printf("Please input a positive and < %d number.\n",MAX);
    }
  } while (n <= 0 || n > MAX);

  for (i = 0; i < n; i++){
    do{
      printf("Item No.%d's size? -> ", i + 1);
      scanf("%d", &Item[i][0]);
      if (Item[i][0] <= 0){
        printf("Please input a positive number.\n");
      }
    } while (Item[i][0] <= 0);

    do{
      printf("Item No.%d's price? -> ", i + 1);
      scanf("%d", &Item[i][1]);
      if (Item[i][1] <= 0){
        printf("Please input a positive number.\n");
      }
    } while (Item[i][1] <= 0);
  }

  do{
    printf("knapsack's size? -> ");
    scanf("%d", &maxSize);
    if (maxSize <= 0){
      printf("Please input a positive number.\n");
    }
  } while (maxSize <= 0);

  knapsack(0,0,0);

  printf("total : %d\n", total);
  return 0;
}
