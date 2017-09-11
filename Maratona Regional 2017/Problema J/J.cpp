//Autor = Welerson
//Complexidade = O(N)
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  char N[101];
  scanf("%s", N);

  int ans = 0;

  for(int i = 0; i < (int) strlen(N); i++){
    ans += (N[i] - '0');
  }

  printf("%d\n", ans%3);
  return 0;
}
