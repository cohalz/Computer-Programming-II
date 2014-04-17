#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  ポインタprefixの指す2進列の後ろに 
  n桁の2進数を任意の順番に付けること
  によって得られる2進列をすべて表示する関数。
*/
void enumerate(char *prefix, int n) ;


int main(void) {
  int n ;
  char *prefix ;

  printf("n = ") ;
  while (scanf("%d", &n) != 1 || n < 0) {
    puts("Wrong input.") ;
    while (getchar() != '\n') ;
  }

  /* prefixのメモリを確保 */
  prefix = (char *)malloc( (n + 1) * sizeof(char) ) ; 
  if (prefix == NULL) { 
    puts("Out of memory.") ;
    return 1 ;
  }
  prefix[0] = '\0' ; /* 最初はprefixが空 */

  enumerate(prefix, n) ;

  free(prefix) ;

  return 0 ;
}


void enumerate(char *prefix, int n) {
  int i,j,k ;

  /* 易しい場合 */
  if (n == 0) { 
    puts(prefix) ; 
    return ;
  } 

  /* 難しい場合 */
  /* 選択肢を順番に試す */ 
  for (j = 1 ; j <= n ; j++) {
    /* prefixの最後に 文字 ('0'+ j) を1個追加 */
    i = strlen(prefix) ; 
    for(k = 0;k<n;k++){
      if(prefix[k] == '0'+j) break;
        prefix[i] = '0' + j ; 
        prefix[ i + 1 ] = '\0' ;
        enumerate(prefix, n - 1) ;

        /* prefixを現在の選択肢の前の状態に戻す */
        prefix[i] = '\0' ;
    }
  }
}
