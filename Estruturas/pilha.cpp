//Autor: José Joaquim de Andrade Neto
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(){
  stack<int> s;
  
  printf("Pilha vazia: %d\n", s.empty());
  
  s.push(1);
  s.push(2);
  
  printf("Tamanho da pilha: %d\n", (int) s.size());
  printf("Primeiro elemento: %d\n", s.top());
  
  s.pop();
  printf("Primeiro elemento apos remocao: %d\n", s.top());
  
  while(!s.empty()) s.pop(); //limpando...
  printf("Pilha esta vazia: %d\n", s.empty());
  return 0;
}
