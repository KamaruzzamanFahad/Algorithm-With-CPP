#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<pair<int,int>> adj_list[105];
int dis[105];

void dijkstra(int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] =0;

    while(!q.empty()){
        
    }
}

int main(){
  cin >> n >> e;

  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj_list[a].push_back({b,c});
    adj_list[b].push_back({a,c});
  }

  fill(dis, dis+105, 500);

  dijkstra(0);
  return 0;
}
