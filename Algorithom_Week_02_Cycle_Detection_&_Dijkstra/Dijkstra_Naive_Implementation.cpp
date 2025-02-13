#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adjList[100];
int n,e;
int dis[100];

void dijkstra(int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while(!q.empty()){
        pair<int,int> prant = q.front();
        q.pop();

        int par_node = prant.first;
        int par_dis = prant.second;

        for(auto child : adjList[par_node]){
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]){
                dis[child_node] = par_dis + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }

    }
}

int main(){
  cin >> n >> e;

  while(e--){
    int a, b, c;
    cin >> a >> b >> c;

    adjList[a].push_back({b,c});
    adjList[b].push_back({a,c});
  }

  memset(dis, 252645135, sizeof(dis));

  dijkstra(0);

  


  for(int i=0; i<n; i++){
    cout << i << " -> " << dis[i] << endl;
  }

  return 0;
}
