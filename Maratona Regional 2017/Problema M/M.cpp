//Autor: Welerson
//Complexidade: O(1)
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int a1, a2, a3;

  scanf("%d %d %d", &a1, &a2, &a3);

  int ans1 = 2*a2 + 4*a3;
  int ans2 = 2*a1 + 2*a3;
  int ans3 = 2*a2 + 4*a1;

  printf("%d\n", min(ans1, min(ans2, ans3)));
  return 0;
}
