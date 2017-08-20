#include <stdio.h>

//Busca Binária em um array de tamanho n
//O algoritmo retorna -1 caso o elemento não seja achado e pos caso o encontre

int buscaBinaria(int arr[], int elemento, int size){
  int l = 0, r = size - 1; //tamanho do array
  
  while(l <= r){
    int mid = (l + r) / 2; //pego o meio
    
    if(arr[mid] == elemento) return mid;
    
    if(arr[mid] > elemento){
      r = mid - 1;
    }else l = mid + 1; //arr[mid] <= elemento
  }
  
  return -1; //se chegamos aqui é porque o elemento não existe em arr
}

int main(){
  int A[] = {1, 2, 3, 10, 20, 32, 50};
  int n = 7;
  printf("%d\n", buscaBinaria(A, 50, n));
  return 0;
}
