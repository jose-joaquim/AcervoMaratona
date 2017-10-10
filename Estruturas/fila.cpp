//Autor: José Joaquim de Andrade Neto
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(){
  queue<int> q;
  
  printf("Fila vazia: %d\n", q.empty());
  
  q.push(1);
  q.push(2);
  
  printf("Tamanho da fila: %d\n", (int) q.size());
  printf("Primeiro elemento: %d\n", q.front());
  
  q.pop();
  printf("Primeiro elemento apos remocao: %d\n", q.front());
  
  while(!q.empty()) q.pop(); //limpando...
  printf("Fila esta vazia: %d\n", q.empty());
  return 0;
}
