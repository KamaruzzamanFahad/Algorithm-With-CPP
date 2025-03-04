#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int> edg_list[1005];
bool visited[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << " ";

        for(int child : edg_list[par]){
            if(!visited[child]){
                q.push(child);
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
        edg_list[a].push_back(b);
        edg_list[b].push_back(a); // for unweighted
    }

    // fill(visited, visited+sizeof(visited), false);
    fill(begin(visited), end(visited), false);

    bfs(0);
  
  return 0;
}



// input: 
// 7 7 
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5

// output: 0 1 3 4 2 5 6 

// use for:
// 1. Shortest Path and distant of Unweighted Graph
// 2. Level Order Traversal