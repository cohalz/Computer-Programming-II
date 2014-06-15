#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n = 0;
  int i;
  int *rank;
  int *p;
  rank = (int *)malloc(sizeof(int));
  if(rank == NULL) return 1;
  int tmp;
  scanf("%d",&tmp);
  while(tmp >= 0) {
    p = (int *)realloc(rank,(n+1)*sizeof(int));
    if(p == NULL) return 1;
    rank = p;
    rank[n] = tmp;
    n++;
    scanf("%d",&tmp);
  }
  /* for (i = 0; i < n; i++) { */
  /*   printf("%d\n",rank[i]); */
  /* } */
  for(i=n-1;i>0;i-=2) {
    if(rank[i] < rank[i-1]) printf("%d ",rank[i]);
    else printf("%d ",rank[i-1]);
  }
  if(n%2 == 1) printf("%d",rank[0]);
  return 0;
}
