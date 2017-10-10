//Autores: todos os participantes da aula.
#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

typedef struct c {
  int a, b;
}carro;

int main() {
  stack<carro> pilha;
  int n, k, a, b, tempoS;
  bool resp = false;
  scanf("%d %d", &n, &k);
  while(n != 0 && k != 0){
    carro car;
    resp = true;        
    for(int i=0; i<n; i++){
      scanf("%d %d", &a, &b);            
      tempoS = 0;
      while(pilha.size() > 0 && a>=pilha.top().b){
        resp &= pilha.top().b >= tempoS;
        tempoS = pilha.top().b;
        pilha.pop();
      }            
      resp &= pilha.size() < (unsigned)k;
      car.a = a; car.b = b;
      pilha.push(car);
    }        
    tempoS = 0;
    while(pilha.size() > 0){
      resp &= pilha.top().b >= tempoS;
      tempoS = pilha.top().b;
      pilha.pop();
    }        
    if(resp) puts("Sim");
    else puts("Nao");      
    scanf("%d %d", &n, &k);
  }
  return 0;
}
