#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  double coef;
  int degree;
  struct node *next;
} nodeType;

nodeType* add(nodeType *p, nodeType *q);
nodeType* sub(nodeType *p, nodeType *q);
nodeType* mul(nodeType *p, nodeType *q);

nodeType* inputpoly(char *name); // 多項式を入力する関数
void printpoly(char *name,nodeType *r); // 多項式を出力する関数
void listmemfree(nodeType *r); // リストのメモリを解放する関数

int main(void) {
  nodeType *p,*q,*ad,*su,*mu, *headp ,*headq; 
  headp = NULL;
  headq = NULL;

  //pとqの二つの多項式を負の次数が入力されるまで入力
  p = inputpoly("p");
  q = inputpoly("q");

  ad = add(p, q);
  su = sub(p, q);
  mu = mul(p, q);

  printpoly("add", ad);
  printpoly("sub", su);
  printpoly("mul", mu);

  listmemfree(p);
  listmemfree(q);
  listmemfree(ad);
  listmemfree(su);
  listmemfree(mu);

  return 0;
}
nodeType* add(nodeType *p, nodeType *q){
  nodeType *r,*headr;
  int flag = 0;
  headr = NULL;
  r = (nodeType *)malloc(sizeof(nodeType)); 
  if(r == NULL) return 0; 
  r -> coef = p -> coef;
  r -> degree = p -> degree;
  r -> next = headr; 
  headr = r;
  p = p -> next;

  while(p != NULL) {
    flag = 0;
    r = headr;
    while(r != NULL) {
      if(r -> degree == p -> degree) {
        flag = 1;
        r -> coef += p -> coef;
        r = headr;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
      r = (nodeType *)malloc(sizeof(nodeType)); 
      if(r == NULL) return 0; 
      r -> coef = p -> coef;
      r -> degree = p -> degree;
      r -> next = headr; 
      headr = r;
    }
    p = p -> next; 
  }


  while (q != NULL) {
    flag = 0;
    r = headr;
    while(r != NULL) {
      if(r -> degree == q -> degree) {
        flag = 1;
        r -> coef += q -> coef;
        r = headr;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
      r = (nodeType *)malloc(sizeof(nodeType)); 
      if(r == NULL) return 0; 
      r -> coef = q -> coef;
      r -> degree = q -> degree;
      r -> next = headr; 
      headr = r;
    }
    q = q -> next; 

  }

  return r;
}

nodeType* sub(nodeType *p, nodeType *q){
  nodeType *r,*headr;
  int flag = 0;
  headr = NULL;
  r = (nodeType *)malloc(sizeof(nodeType)); 
  if(r == NULL) return 0; 
  r -> coef = p -> coef;
  r -> degree = p -> degree;
  r -> next = headr; 
  headr = r;
  p = p -> next;

  while(p != NULL) {
    flag = 0;
    r = headr;
    while(r != NULL) {
      if(r -> degree == p -> degree) {
        flag = 1;
        r -> coef += p -> coef;
        r = headr;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
      r = (nodeType *)malloc(sizeof(nodeType)); 
      if(r == NULL) return 0; 
      r -> coef = p -> coef;
      r -> degree = p -> degree;
      r -> next = headr; 
      headr = r;
    }
    p = p -> next; 
  }

  while (q != NULL) {
    flag = 0;
    r = headr;
    while(r != NULL) {
      if(r -> degree == q -> degree) {
        flag = 1;
        r -> coef -= q -> coef;
        r = headr;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
      r = (nodeType *)malloc(sizeof(nodeType)); 
      if(r == NULL) return 0; 
      r -> coef = q -> coef;
      r -> degree = q -> degree;
      r -> next = headr; 
      headr = r;
    }
    q = q -> next; 
  }  

  return r;
}

nodeType* mul(nodeType *p, nodeType *q) {
  nodeType *r,*headr,*headq;
  int flag = 0;
  headr = NULL;
  headq = q;
  r = (nodeType *)malloc(sizeof(nodeType)); 
  if(r == NULL) return 0; 
  r -> coef = (p -> coef) * (q -> coef);
  r -> degree = (p -> degree) + (q -> degree);
  r -> next = headr; 
  headr = r;
  q = q -> next;

  while(p != NULL) {
    while(q != NULL) {
      flag = 0;
      r = headr;
      while(r != NULL) {
        if(r -> degree == (p -> degree) + (q -> degree)) {
          flag = 1;
          r -> coef += (p -> coef) * (q -> coef);
          r = headr;
          break;
        }
        r = r -> next; 
      }
      if(flag == 0) {
        r = (nodeType *)malloc(sizeof(nodeType)); 
        if(r == NULL) return 0; 
        r -> coef = (p -> coef) * (q -> coef);
        r -> degree = (p -> degree) + (q -> degree);
        r -> next = headr; 
        headr = r;
      }
      q = q -> next; 
    }
    q = headq;    
    p = p -> next;
  }
  return r;
}

void printpoly(char *name,nodeType *r) {
  printf("%s = ",name);

  while(r != NULL) {
    printf("%f",r -> coef);
    if(r -> degree != 0) printf("x^%d",r -> degree);
    if(r -> next != NULL) printf(" + ");
    r = r -> next;
  }
  puts("");
}

void listmemfree(nodeType *r) {
  nodeType *tmp = NULL;
  while(r != NULL) { 
    tmp = r -> next;
    free(r);
    r = tmp;
  }
}

nodeType* inputpoly(char *name) {
  nodeType *r;
  nodeType *headr = NULL;

  do { 
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if(r == NULL) return 0; 
    printf("%s's coef -> ",name);
    scanf("%lf", &(r -> coef)); 
    printf("%s's degree -> ",name);
    scanf("%d", &(r -> degree)); 
    r -> next = headr; 
    headr = r; 
  } while(r -> degree >= 0);

  r = r -> next; 
  free(headr);
  return r;
}
