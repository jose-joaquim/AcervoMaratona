#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi howMuch, visited, grau, levels;
int n, c;


int dfs(int u, int length){
  visited[u] = true;
  int ret = 0;
  for(int j = 0; j < (int) adj[u].size(); j++){
    ii v = adj[u][j];
    if(!visited[v.first]){
      int gogo = dfs(v.first, length + v.second);
      //printf("v %d me retornou %d\n", v.first, gogo);
      ret += gogo;
    }
  }
  //printf("length ate %d eh %d\n", u, length);
  if(howMuch[u]){
    //printf("%d deve %d\n", u, howMuch[u]);
    if(c > howMuch[u]){
      //printf("so preciso de uma passada, vou add apenas %d\n", length * 2);
      ret = ret + (length * 2);
    }else{
      //printf("preciso de %d passadas, vou add ", (howMuch[u] / c) + (howMuch[u] % c != 0));
      int div = howMuch[u] / c;
      int add = (2 * length * (div + (howMuch[u] % c != 0)));
      //printf("%d\n", add);
      ret = ret + add;
    }
  }
  return ret;
}


void bfs(){
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(grau[i] == 1){
      //printf("coloquei %d\n", i);
      q.push(i);
    }
  }
  
  while(!q.empty()){
    int u = q.front(); q.pop();
    if(u == 1) continue;
    //printf("to em %d, ele deve %d\n", u, howMuch[u]);
    for(int j = 0; j < (int) adj[u].size(); j++){
      int v = adj[u][j].first;
      int maxload = (int) abs(c - howMuch[v]);
      if(v == 1) continue;
      if((levels[v] == levels[u] - 1) && maxload){//se eh o meu pai e ele pode receber
        //printf("tirei %d de %d, que tinha %d e agora tem %d, para colocar em %d, que tinha %d e agora tem %d\n", min(maxload, howMuch[u]), u, howMuch[u], howMuch[u] - min(maxload, howMuch[u]), v, howMuch[v], howMuch[v] + min(maxload, howMuch[u]));
        howMuch[v] += min(maxload, howMuch[u]);
        howMuch[u] -= min(maxload, howMuch[u]);
        q.push(v);
      }      
    }
  }
}

void findLevels(int u, int pai, int level){
  levels[u] = level;
  for(int i = 0; i < (int) adj[u].size(); i++){
    int v = adj[u][i].first;
    if(v != pai){
      findLevels(v, u, level + 1);
    }
  }
}

int main(){
  while(scanf("%d %d", &n, &c) != EOF){
    howMuch.resize(n + 1);
    adj.assign(n + 1, vii());
    grau.assign(n + 1, 0);
    levels.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
      scanf("%d", &howMuch[i]);
    }
    for(int i = 0; i < n - 1; i++){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back(ii(v, w));
      adj[v].push_back(ii(u, w));
      grau[u]++, grau[v]++;
    }
    findLevels(1, -1, 0);
    bfs();
    /*puts("atual estado de divida");
      for(int i = 1; i <= n; i++){
      printf("%d ", howMuch[i]);
      }
      puts("");*/
    printf("%d\n", dfs(1, 0));
  }
  return 0;
}
