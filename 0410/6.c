#include <stdio.h>
#define maxLength 99
/* 
 * どちらにしろ計算量が多いので上限を設けた。
 * lとrはそれぞれ残りの表示するLとRの数。
 * 全列挙で深さ優先探索する際に配列の中身を書き換えて表示している。
 */
void dfs(int l, int r) {
  static char str[maxLength];
  if(l + r == 0) {
    puts(str);
  }
  else if(l == 0) {
    str[l+r-1] = 'R';
    dfs(l,r-1);
  }
  else if(r == 0) {
    str[l+r-1] = 'L';
    dfs(l-1, r);
  }
  else {
    str[l+r-1] = 'R';
    dfs(l,r-1);
    str[l+r-1] = 'L';
    dfs(l-1,r);
  }
}

int main(){
  int l,r;
  scanf("%d",&l);
  scanf("%d",&r);
  if(l+r <= maxLength) dfs(l,r);
  return 0;
}
