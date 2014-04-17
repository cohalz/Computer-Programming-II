#include<stdio.h>
#define ITEM 128

int Item[ITEM + 1][4];

void ZAQ(int item, int grade, int prise, int MAX){
  int i;
  for (i = 0; i < item; i++){
    if (Item[i][3] == 0 && grade + Item[i][1] <= MAX){
      Item[i][3] = 1;
      grade += Item[i][1];
      prise += Item[i][2];

      ZAQ(item, grade, prise, MAX);

      grade -= Item[i][1];
      prise -= Item[i][2];

      Item[i][3] = 0;
    }
  }
  if (Item[item][2] < prise){
    Item[item][2] = prise;
  }
}

int main(){
  int item, i, zaq;

  do{
    printf("How many item? -> ");
    scanf("%d", &item);
    if (item <= 0 || item > ITEM){
      printf("Error.\n");
    }
  } while (item <= 0 || item > ITEM);

  for (i = 0; i < item; i++){
    Item[i][0] = i + 1;
    Item[i][3] = 0;
    do{
      printf("Item No.%d's grade? -> ", i + 1);
      scanf("%d", &Item[i][1]);
      if (Item[i][1] <= 0){
        printf("Error.\n");
      }
    } while (Item[i][1] <= 0);

    do{
      printf("Item No.%d's prise? -> ", i + 1);
      scanf("%d", &Item[i][2]);
      if (Item[i][2] <= 0){
        printf("Error.\n");
      }
    } while (Item[i][2] <= 0);
  }

  Item[item][2] = 0;

  do{
    printf("napzakk's grade? -> ");
    scanf("%d", &zaq);
    if (zaq <= 0){
      printf("Error.\n");
    }
  } while (zaq <= 0);

  ZAQ(item, 0, 0, zaq);

  printf("Most item's prise : %d\n", Item[item][2]);

  return 0;
}
