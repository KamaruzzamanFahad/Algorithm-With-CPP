#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> edgList[100];
int n,e;

int main(){
  cin >> n >> e;

  while(e--){
    int a, b, c;
    cin >> a >> b >> c;

    edgList[a].push_back({b,c});
    edgList[b].push_back({a,c});
  }

  for(int i=0; i<n; i++){
    cout << i << " -> ";

    for(auto x : edgList[i]){
        cout << x.first << " " << x.second << ", ";
    }
    cout << endl;
  }
  return 0;
}
