//Autores: todos participantes da aula.
#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;

int main(){
  int n;
  while(scanf("%d", &n) && n){
    deque<int> q;
    for(int i = 1; i <= n; i++){
      q.push_back(i);
    }
    printf("Discarded cards: ");
    while(q.size() >= 2){
      printf("%d", q.front());
      q.pop_front();
      if(q.size() == 1) break;
      else printf(", ");
      int topo = q.front();
      q.push_back(topo);
      q.pop_front();
    }
    puts("");
    printf("Remaining card: %d\n", q.front());
  }
  return 0;
}
