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
        pair<int,int> par = q.front();
        int par_node = par.first;
        int par_dis = par.second;

        for(auto child : adj_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node] ){
                dis[child_node] = par_dis + child_dis;

                q.push({child_node, dis[child_node]});
            }
        }

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

  for(int i=0; i<n; i++){
    cout << i << " -> " << dis[i] << endl;
  }
  return 0;
}
