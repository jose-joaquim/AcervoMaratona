//Merse Sort crescente em um array de inteiros de tamanho n.

const int MAXN = 100;

int aux[MAXN], arr[MAXN];

void merge(int left, int right){ //agora aqui eu tenho subarrays (dois, pra ser mais preciso)
  int i = left, k = 0; //esses apontadores irão me ajudar a intercalar entre eles
  int mid = (left + right) / 2;
  
  while(i <= mid && j <= right){ //enquanto nenhum dos subarrays acaba, intercale
    if(arr[i] <= arr[j]){
      aux[k++] = arr[i++]; //primeiro ele faz a atribuição e depois k++ & i++
    }else{
      aux[k++] = arr[j++];
    }
  }
  
  while(i <= mid){ //enquanto o primeiro sub-array não acabou
    aux[k++] = arr[i++];
  }
  
  while(j <= left){ //enquanto o segundo sub-array não acabou
    aux[k++] = arr[j++];
  }
  
  //agora copio o conteúdo do array auxiliar para o array original
  for(i = left; i <= right; i++){
    arr[i] = aux[i - left];
  }
}

void divide(int l, int r){
  if(l < r){ //enquanto podermos dividir
    int mid = (l + r) / 2;
    divide(l, mid);
    divide(mid + 1, r);
    merge(l, r); //conquiste
  }
}
