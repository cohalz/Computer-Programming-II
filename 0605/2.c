#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  int data;
  struct node *next;
} nodeType;

void listmemfree(nodeType *r);
int main(void) {
  char command[7];
  int n,flag = 0;
  nodeType *list,*tmp;
  nodeType *head = NULL;
  printf("input command: ");
  scanf("%s",command);
  if(strcmp(command,"push") == 0 || strcmp(command,"search") == 0) {
    puts("a");
    scanf("%d",&n);
  }
  while(getchar() != '\n');
  while(strcmp(command,"q") != 0) {
    if(strcmp(command,"push") == 0) {
      list = (nodeType *)malloc(sizeof(nodeType)); 
      if (list == NULL) return 0;
      list -> data = n;
      list -> next = head; 
      head = list; 
    } else if(strcmp(command,"pop") == 0) {
      printf("%d\n",list->data);
      tmp = list -> next;
      free(list);
      list = tmp;
    } else if(strcmp(command,"print") == 0) {
      while(list != NULL) {
        printf("%d",n);
        if((list -> next) != NULL) printf(" -> ");
        list = list -> next;
      }
      puts("");
      list = head;

    } else if(strcmp(command,"search") == 0) {
      flag = 0;
      while(list != NULL) {
        if(list -> data == n) {
          puts("true");
          flag = 1;
          break;
        }
      }
      if(flag == 0) puts("false");

    } else {
      puts("error");
    }
  printf("input command: ");
  scanf("%6s",command);
  if(strcmp(command,"push") == 0 || strcmp(command,"search") == 0) {
    puts("a");
    scanf("%d",&n);
  }
  while(getchar() != '\n');
  }

  listmemfree(list);
  return 0;
}
void listmemfree(nodeType *r) {
  nodeType *tmp = NULL;
  while (r != NULL) { 
    tmp = r -> next;
    free(r);
    r = tmp;
  }
}

void freeList(nodeType *p) {
  if(p == NULL) return;
  freeList(p -> next);
  free(p);
}

