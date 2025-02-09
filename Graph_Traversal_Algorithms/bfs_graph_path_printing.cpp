#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int> edgList[100];
int visited[100];
int parent[100];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();

        for(int child : edgList[p]){
            if(!visited[child]){
                q.push(child);
                parent[child] = p;
                visited[child] = true;
            }
        }
    }
}

int main(){
  cin >> n >> e;

  while(e--){
    int a,b;
    cin >> a >> b;

    edgList[a].push_back(b);
    edgList[b].push_back(a);
  }

  memset(visited, false, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  int src,dest;
  cin >> src >> dest;
  bfs(src);



  int node = dest;

  while(node != -1){
    cout << node << " ";
    node = parent[node];
  }


  return 0;
}
