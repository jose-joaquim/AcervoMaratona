//Bubble Sort crescente em um array de inteiros de tamanho n.

int n;

void bubbleSort(int arr[]){
  int i, j;
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      if(arr[i] > arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
