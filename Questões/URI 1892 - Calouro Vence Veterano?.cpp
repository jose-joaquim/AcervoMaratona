#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100010;

char arr[MAXN][11];
char aux[MAXN][11];
long long answer;

void merge(int left, int right){
  int meio = (left + right) / 2;
  int i = left, j = meio + 1;
  int k = 0;q
  while(i <= meio && j <= right){
    if(strcmp(arr[i], arr[j]) <= 0){
      strcpy(aux[k], arr[i]);
      k++; i++;
    }else{
      strcpy(aux[k], arr[j]);
      k++; j++;
      answer = answer + ((meio - i) + 1) * 1LL;
    }
  }
  while(i <= meio){
    strcpy(aux[k], arr[i]);
    k++; i++;
  }
  while(j <= right){
    strcpy(aux[k], arr[j]);
    k++, j++;
  }
  for(i = left; i <= right; i++){
    strcpy(arr[i], aux[i - left]);
  }
}

void divide(int left, int right){
  if(left < right){
    int meio = (left + right) / 2;
    divide(left, meio);
    divide(meio + 1, right);
    merge(left, right);
  }
}

int main(){
  int n;
  while(scanf("%d", &n) != EOF){
    int i;
    for(i = 0; i < n; i++){
      scanf("%s", arr[i]);
    }
    answer = 0;
    divide(0, n - 1);
    printf("%lld\n", answer);
  }  
}
