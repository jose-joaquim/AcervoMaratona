//Autor: Joaquim
//Complexidade: O(MAXN * MAXM)
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 1000000007;
const int MAXN = 52;
const int MAXM = 100005;

int t, m, n;
int dp[MAXM][MAXN];

bool insideBound(int pos){
  return pos <= n && pos >= m;
}

int solve(int pos, int temp){
  if(temp == 1){
    if(insideBound(pos)){
      return 1;
    }else{
      return 0;
    }
  }

  if(pos > n || pos < m){
    return 0;
  }

  int &ret = dp[pos][temp];

  if(ret == -1){
    ret = (solve(pos - 1, temp - 1) + solve(pos + 1, temp - 1))%INF;
  }

  return ret;  
}

int main(){
  scanf("%d %d %d", &t, &m, &n);
  memset(dp, -1, sizeof dp);
  int retFinal = 0;
  for(int i = m; i <= n; i++){
    int voltou = solve(i, t);
    retFinal += voltou%INF;
    retFinal %= INF;
  }
  printf("%d\n", retFinal%INF);
  return 0;
}
