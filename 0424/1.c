#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 3

typedef struct {
  float dim[K];
} vector;

float size(vector v) {
  float squareSum = 0.0;
  int i;
  for(i = 0; i<K; i++) {
    squareSum += v.dim[i];
  }
  return sqrt(squareSum);
}

vector sum(vector v1, vector v2) {
  int i;
  vector v;
  for (i = 0; i < K; i++) {
    v.dim[i] = v1.dim[i] + v2.dim[i];
  }
  return v;
}

vector diff(vector v1, vector v2) {
  int i;
  vector v;
  for (i = 0; i < K; i++) {
    v.dim[i] = v1.dim[i] - v2.dim[i];
  }
  return v;
}

float product(vector v1, vector v2) {
  int i;
  float p;
  for (i = 0; i < K; i++) {
    p = v1.dim[i] * v2.dim[i];
  }
  return p;
}

int main(void) {
  int n,i,j;
  int maxi,maxj;
  float max = 0.0;
  float tmp;
  vector *arr;
  printf("n = ");
  scanf("%d",&n);
  arr = (vector *)malloc(sizeof(vector) * n);

  for(i = 0; i < n; i++) {
    for (j = 0; j < K; j++) {
      printf("No%d.dim:%d = ",i,j);
      scanf("%f",&arr[i].dim[j]);
    }
  }

  for(i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      tmp = size(diff(arr[i],arr[j]));
      if(max < tmp) {
        max = tmp;
        maxi = i;
        maxj = j;
      }
    }
  }
  puts("diffmax");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxi].dim[i]);
  }
  puts("");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxj].dim[i]);
  }
  puts("");

  for(i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      tmp = size(sum(arr[i],arr[j]));
      if(max < tmp) {
        max = tmp;
        maxi = i;
        maxj = j;
      }
    }
  }
  puts("summax");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxi].dim[i]);
  }
  puts("");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxj].dim[i]);
  }
  puts("");

  for(i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      tmp = product(arr[i],arr[j]);
      if(max < tmp) {
        max = tmp;
        maxi = i;
        maxj = j;
      }
    }
  }
  puts("productmax");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxi].dim[i]);
  }
  puts("");
  for (i = 0; i < K; i++) {
    printf("%f ",arr[maxj].dim[i]);
  }
  puts("");

  return 0;
}
