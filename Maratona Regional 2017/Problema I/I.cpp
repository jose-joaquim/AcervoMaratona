//Autor: Welerson
//Complexidade: O(V + E)
#include<bits/stdc++.h>
using namespace std;

int dev[11234], visited[11234];
int n, c, a, b, w;

vector<pair<int, int> > adjList[11234];

int ans = 0;

void dfs(int u, int pai, int posJ){
  visited[u] = 1;
  for(int j = 0; j < (int)adjList[u].size(); j++){
    int v = adjList[u][j].first;
    if(!visited[v]){
      dfs(v, u, j);
      dev[u]+=dev[v];
    }
  }
  if(pai != -1){
    int aux = (dev[u] % c) ? dev[u]/c + 1 : dev[u]/c;
    ans += aux * adjList[pai][posJ].second;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin>>n>>c;
  
  for(int i = 0; i < n; i++)
		cin>>dev[i];
  
  for(int i = 0; i < n-1; i++){
    cin>>a>>b>>w;
    a--;b--;
    adjList[a].push_back({b, w});
    adjList[b].push_back({a, w});
  }
  
  dfs(0, -1, -1);
  
  cout<<2*ans<<endl;
  
  return 0;
}
