//Esse programa testa a diferença entre um problema:
//Dado um conjunto Q com 10^3 números, verificar se um elemento x pertence ao conjunto Q
//O número de conultas é 10^7
// 1 - Buscando de forma linear = O(n)
// 2 - Ordenando com o método Bubble Sort e em seguida efetuando as consultas com busca binária
//     Bubble Sort = O(n ^ 2) + Busca Binária = O(log n)

#include <time.h>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int SIZE = 10000000;
int A[1000];

bool bb(int u, int v, int x){
  int l = u, r = v;
  int mid;
  while(l <= r){
    mid = (l + r) / 2;
    if(A[mid] == x) return true;
    if(x < A[mid]) r= mid - 1;
    else l = mid + 1;
  }
  return false;
}

void verificaLinear(){
  for(int i = 0; i < SIZE; i++){
    int oq = rand()%5000 + 5000;
    printf("%s\n", verifica(oq) ? "Y" : "N");
  }
}

void verificaBuscaBinaria(){
  for(int i = 0; i < 10; i++){
    for(int j = i + 1; j < 10; j++){
      if(A[i] > A[j]) swap(A[i], A[j]);
    }
  }
  for(int i = 0; i < SIZE; i++){
    int oq = rand()%5000 + 5000;
    printf("%s\n", bb(0, 1000, oq) ? "Y" : "N");
  }
}

int main(){
  clock_t timex = clock();
  srand((unsigned) time(NULL));
  for(int i = 0; i < 1000; i++){
    A[i] = rand()%5000;
  }
  //verificaLinear(); Descomente essa linha e comente a abaixo para alternar e testar entre os métodos
  verificaBuscaBinaria();
  return 0;
}
