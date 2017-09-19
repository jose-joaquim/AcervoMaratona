//Autores: Welerson & Adam
//Complexidade: O(NlogN)
#include<bits/stdc++.h>

#define ft first
#define sc second

using namespace std;

int arr[] = {1, 3, 5, 6, 8, 10, 12};
pair<set<int>, bool> tom[15];

int main(){
  int n;
  
  cin>>n;
  
  for(int i = 0; i < 12; i++){
    set<int> aux;
    for(int j = 0; j < 7; j++){
      int a = (i + arr[j]) % 12;
      if(a == 0) a = 12;
      
      aux.insert(a);
    }
    tom[i] = {aux, true};
  }
  
  int a;
  for(int i = 0; i < n; i++){
    cin>>a;
    a = a % 12;
    if(a == 0) a = 12;
    for(int j = 0; j < 12; j++){
      if(tom[j].sc == true && tom[j].ft.find(a) == tom[j].ft.end()){
        tom[j].sc = false;
      }
    }
  }
  
  string ans[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
  
  for(int i = 0; i < 12; i++){
    if(tom[i].sc == true){
      cout<<ans[i]<<endl;
      return 0;
    }
  }
  
  cout<<"desafinado\n";
  
  return 0;
}
