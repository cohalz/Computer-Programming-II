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

nodeType* copyList(nodeType *p);
nodeType* copyList2(nodeType *p);
nodeType* copyList3(nodeType *p);

nodeType* inputpoly(char *name);
void printpoly(char *name,nodeType *r);
void listmemfree(nodeType *r);

int main(void) {
  nodeType *p,*q,*ad,*su,*mu, *headp ,*headq; 
  nodeType *s;
  headp = NULL;
  headq = NULL;

  //pとqの二つの多項式を負の次数が入力されるまで入力

  p = inputpoly("p");
  q = inputpoly("q");

  ad = add(p, q);
  su = sub(p, q);
  mu = mul(p, q);
  s = copyList3(p);

  printpoly("s = ", s);
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

  while (p != NULL) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (q == NULL) return 0; 
    r -> coef = p -> coef;
    r -> degree = p -> degree;
    r -> next = headr; 
    headr = r;
    p = p -> next;
  }

  while (q != NULL) {
    flag = 0;
    while(r != NULL) {
      if(r -> degree == q -> degree) {
        flag = 1;
        r -> coef += q -> coef;
        r = headr;
        q = q -> next;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (q == NULL) return 0; 
    r -> coef = q -> coef;
    r -> degree = q -> degree;
    r -> next = headr; 
    headr = r;
    q = q -> next; 
    }
  }

  return r;
}

nodeType* sub(nodeType *p, nodeType *q){
  nodeType *r,*headr;
  int flag = 0;
  headr = NULL;

  while (p != NULL) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (r == NULL) return 0; 
    r -> coef = p -> coef;
    r -> degree = p -> degree;
    r -> next = headr; 
    headr = r;
    p = p -> next;
  }

  while (q != NULL) {
    flag = 0;
    while(r != NULL) {
      if(r -> degree == q -> degree) {
        flag = 1;
        r -> coef -= q -> coef;
        r = headr;
        q = q -> next;
        break;
      }
      r = r -> next; 
    }
    if(flag == 0) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (q == NULL) return 0; 
    r -> coef = q -> coef;
    r -> degree = q -> degree;
    r -> next = headr; 
    headr = r;
    q = q -> next; 
    }
  }

  return r;
}

nodeType* mul(nodeType *p, nodeType *q){
  nodeType *r,*headr,*headq;
  /* int flag = 0; */
  headr = NULL;
  headq = q;

  while (p != NULL) {
      while (p != NULL) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (r == NULL) return 0; 
    r -> coef = p -> coef;
    r -> degree = p -> degree;
    r -> next = headr; 
    headr = r;
    p = p -> next;
  }

  }
  return r;
}

void printpoly(char *name,nodeType *r) {
  printf("%s = ",name);

  while(r != NULL) {
    printf("%f",r -> coef);
    if(r -> degree != 0) printf("x^%d",r -> degree);
    if(r -> next != NULL) printf(" + ");
    else puts("");
    r = r -> next;
  }
}

void listmemfree(nodeType *r) {
  nodeType *tmp = NULL;
  while (r != NULL) { 
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
    if (r == NULL) return 0; 
    printf("%s's coef -> ",name);
    scanf("%lf", &(r -> coef)); 
    printf("%s's degree -> ",name);
    scanf("%d", &(r -> degree)); 
    r -> next = headr; 
    headr = r; 
  } while (r -> degree >= 0);

  r = r -> next; 
  free(headr);
  return r;
}


nodeType* copyList2(nodeType *p) {
  nodeType *r,*headr;
  headr = NULL;

  while (p != NULL) {
    r = (nodeType *)malloc(sizeof(nodeType)); 
    if (r == NULL) return 0; 
    r -> coef = p -> coef;
    r -> degree = p -> degree;
    r -> next = headr; 
    headr = r;
    p = p -> next;
  }
  return r;
}

nodeType* copyList(nodeType *p) {
  nodeType *r,*q;

  if(p == NULL) return NULL;

  r = copyList(p -> next);
  q = (nodeType *)malloc(sizeof(nodeType)); 
  if (q == NULL) return 0; 
  *q = *p;
  q -> next = r;
  return q;
}

nodeType* copyList3(nodeType *p) {
  nodeType *r = NULL;
  nodeType *tmp,*tail;

  while (p != NULL) {
    tmp = (nodeType *)malloc(sizeof(nodeType)); 
    if (r == NULL) return 0; 
    tmp = p;
    if(r == NULL) {
      r = tmp;
    } else {
      tail -> next = tmp;
      tmp -> next = NULL;
    }
      tail = tmp;
    p = p -> next;
  }
  return r;
}
