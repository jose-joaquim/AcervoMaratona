//Autor: José Joaquim de Andrade Neto
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> v;
  
  for(int i = 0; i < 10; i++)
    v.push_back(i);
  
  printf("Tamanho do vetor: %d\n", (int) v.size());
  
  printf("Primeiro elemento: %d\n", v[0]);
  printf("Quinto elemento: %d\n", v[4]);
  
  v.clear();
  printf("Vetor esta vazio: %d\n", v.empty());
  
  vector<int> outro_v(10, 4);
  printf("Tenho %d elementos\n", (int) outro_v.size());
  for(int i = 0; i < (int) outro_v.size(); i++){
    printf("%d\n", v[i]);
  }
  return 0;
}
