//Autor: Joaquim
//Complexidade: O(sqrt(N) + numero_divisores(N) * sqrt(max(divisor(N))))
#include <vector>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll n;
vector<ll> divisores;

bool ehDespojado(ll numero){
  //printf("verificando divisor %lld\n", numero);
  int qtdPrimos = 0;
  bool distintos = true;
  ll aux = numero;
  for(ll i = 2; i * i <= numero; i++){
    bool divide = false, foi = false;
    int cnt = 0;
    while(aux % i == 0){
      aux /= i;
      cnt++;
      foi = true;
    }
    if(cnt > 1) return false;
    if(foi){
      qtdPrimos++;
    }
  }
  if(aux != 1) qtdPrimos++;
  //printf("      %lld tem %d fatores primos\n", numero, qtdPrimos);
  return (qtdPrimos >= 2 && distintos);
}

int main(){
  scanf("%lld", &n);
  ll ans = 0;
  for(long long i = 1; i * i <= n; i++){
    if(n % i == 0){
      divisores.push_back(i);
      if(i != n / i){
        divisores.push_back(n / i);
      }
    }
  }

  //printf("%lld tem %d divisores\n", n, (int) divisores.size());
  //para cada divisor, verifico se ele eh despojado...
  for(int k = 0; k < (int) divisores.size(); k++){
    if(ehDespojado(divisores[k]))
      ans++;
  }
  
  printf("%lld\n", ans);
  return 0;
}
