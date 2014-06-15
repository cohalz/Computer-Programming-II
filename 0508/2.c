#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
  char studentID[8];
  int data1;
  int data2;
} student;


void printdata(student *s,int n);

int main() {
  char c;
  int i = 0;
  int j;
  int average;
  student *s;
  student *t;
  s = (student *)malloc(sizeof(student));
  printf("input command:");
  /* scanf("%c",&c); */
  c = getchar();
  while(getchar() != '\n'){}
  while(c != 'q') {
    t = (student *)realloc(s,(i+1) * sizeof(student));
    if(t == NULL) {
      free(s);
      return 1;
    }
    s = t;

    if(c == 'p') {
      for(j = 0; j < i; j++) {
        average = (s[j].data1+s[j].data2)/2;
        printf("%s %d %d %d\n",s[j].studentID,s[j].data1,s[j].data2,average);
      }
    } else if(c == 'i') {
      printf("ID = ");
      /* scanf("%s",s[i].studentID); */
      fgets(s[i].studentID, 8, stdin);
      if(strchr(s[i].studentID,'\n') != NULL) {
        while(getchar() != '\n');
      }
      printf("data1 = ");
      scanf("%d",&s[i].data1);
      printf("data2 = ");
      scanf("%d",&s[i].data2);
      i++;
    } else {
      printf("input error\n");
    }
    
    printf("input command:");
    while(getchar() != '\n');
    c = getchar();
  }
  printdata(s,i);
  free(s);
  return 0;
}

void printdata(student *s,int n) {
  int i;
  int average;
  for (i = 0; i < n; i++) {
    average = (s[i].data1+s[i].data2)/2;
    printf("%s ",s[i].studentID);
    if(average >= 90) puts("S");
    else if(average >= 80) puts("A");
    else if(average >= 70) puts("B");
    else if(average >= 60) puts("C");
    else puts("D");
  }
}

