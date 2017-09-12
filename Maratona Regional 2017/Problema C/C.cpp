#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
ll lcm(int a, int b){ return a * (b / gcd(a, b)); }

ll arr[10004];
ll n, l;

ll lcm_(int qtd){
  if(qtd == 2){
    return lcm(arr[0], arr[1]);
  }else return lcm(arr[qtd - 1], lcm_(qtd - 1));
}

int main(){
  scanf("%lld %lld", &n, &l);
  for(int i = 0; i < n; i++){
    scanf("%lld", &arr[i]);
  }
  ll lcmgeral = lcm_(n);
  ll ans = 0, pos = 0;
  for(ll i = 1; i <= l; i++){
    ll xx = lcm(lcmgeral, i);
    if(xx > ans && xx <= l){
      ans = xx;
      pos = i;
    }
  }
  printf("%lld\n", pos);
  return 0;
}
