//Autor: Welerson
//Complexidade: O(NlogN)
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  int a[1123];
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  sort(a, a + n);
  reverse(a, a + n);

  int cont = k - 1;
  while(a[cont] == a[k - 1]){
    cont++;
  }

  printf("%d\n", cont);
  return 0;
}
