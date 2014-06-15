#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 7 /* コマンドの最大文字数 + 1 */
#define MAXNAME 32
/* リストのノードの型を宣言 */
typedef struct node {
  char name[MAXNAME+1] ;
  struct node *next ;
} nodeType ;

/* pの指すリストにあるデータを表示 */
static void showList(nodeType *p) ;

/* pの指すリストのノードのメモリをすべて解放 */
void freeList(nodeType *p) ;

/* 余計に入力したゴミを読み捨てる関数。
   戻り値：余計な入力がなかった場合、0。
           余計な入力があった場合、1 */
int skipExtraInput(void) ;


int main(void) {
  char command[SIZE] ;
  nodeType *head = NULL, *temp ,**pp;
  char name[MAXNAME+1] ;
  int k;
  int i;

  for(;;) {
    /* ユーザへの指示 */
    puts("Which operation? (1) push integer  (2) pop  (3) print  (4) search integer  (5) q") ;

    /* コマンドを読み込む */
    if ( scanf("%6s", command) != 1 ) {
      puts("Wrong command.") ;
      while ( getchar() != '\n' ) ;
      continue ; /* 次のコマンドの読み込みへ */
    }

    /* pushまたはsearchコマンドのとき */
    if ( strcmp(command, "push") == 0 || strcmp(command, "search") == 0 ) { 
      /* 整数を読み込んで、リストの先頭に追加 */
      if ( scanf("%32s", name) != 1 ) { 
        puts("Not an string.") ;
        while ( getchar() != '\n' ) ; 
        continue ; /* 整数ではないとき、次のコマンドの読み込みへ */
      }
      if ( skipExtraInput() ) { /* 余計な入力があったら、次のコマンドの入力へ */
        puts("Bad command.") ; 
        continue ; 
      }
      if ( command[0] == 'p' ) { /* pushコマンドのとき */
        /* 新しいノードを作る */
        temp = (nodeType *)malloc(sizeof(nodeType)) ;
        if (temp == NULL) { 
          puts("Out of memory.") ;
          exit(EXIT_FAILURE) ;
        }
        /* temp->name = name ; */
        strcpy(temp->name,name);

        /* 新しいノードをリストの先頭に挿入 */
        temp->next = head ;
        head = temp ;
      } else { /* searchコマンドのとき */
        for (temp = head ; temp != NULL ; temp = temp->next) 
          if (strcmp(temp->name , name) == 0) {
            printf("Found %s in the list.\n", name) ;
            break ;
          }
        if (temp == NULL) {
          printf("Found no integer %s in the list.\n", name) ;
        }
      }
    } else { /* pushとsearchコマンド以外の場合 */
      if ( skipExtraInput() ) { /* 余計な入力があったら、次のコマンドの入力へ */
        puts("Bad command.") ; 
        continue ; 
      }
      if ( strcmp(command, "pop") == 0 ) { /* popコマンドのとき */
        if (head == NULL) 
          puts("Empty list.") ;
        else {
          printf("%32s\n", head->name) ;
          temp = head ; 
          head = temp->next ;
          free(temp) ;
        }
      } else if ( strcmp(command, "print") == 0 ) { /* printコマンドのとき */
        showList(head) ; /* リストのデータを表示 */
      } else if ( strcmp(command, "q") == 0 ) { /* qコマンドのとき */
        break ;
      } else if ( strcmp(command, "d") == 0 ) { /* dコマンドのとき */
        scanf("%d",&k);
        pp = &head;
        for (i = 0; i < k-1; i++) {
          temp = temp -> next;

        }

      } else { 
        printf("Bad command: %s.", command) ;
      } 
    }
  }

  /* リストのメモリを解放 */
  freeList(head) ;

  return 0 ;
}


/* リストのデータを表示する関数 */
static void showList(nodeType *p) {
  puts("The integers in the list:") ;
  for ( ; p != NULL ; p = p->next) {
    printf("%s ", p->name) ;
  }
  puts("") ;
}


/* 余計に入力したゴミを読み捨てる関数。
   戻り値：余計な入力がなかった場合、0。
           余計な入力があった場合、1 */
int skipExtraInput(void) {
  int flag, c ;

  flag = 0 ; /* フラグを下げる */
  while ( (c = getchar()) != '\n' ) /* 余計な入力を読み捨てる */
    if ( !isspace(c) ) flag = 1 ; /* フラグをあげる */
  return flag ;
}


/* pの指すリストのノードのメモリをすべて解放 */
void freeList(nodeType *p) {
  nodeType *temp ;

  while (p != NULL) { 
    temp = p ;
    p = p->next ;
    free(temp) ;
  }
}

//**pを使うと挿入場所の前のポインタも後ろもわかる
//(**ppは前の場所のnextを指す)
