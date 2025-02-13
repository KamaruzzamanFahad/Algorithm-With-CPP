#include<bits/stdc++.h>
using namespace std;
vector<int> edgList[100];
bool visited[100];
int n,e;
int parent[100];
bool cycle = false;


void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();

        cout << p << " ";

        for(int c : edgList[p]){

            if(!visited[c] && parent[p] != c){
                cycle = true;
            }


            if(!visited[c]){
                q.push(c);
                visited[c] = true;
                parent[c] = p;
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

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(i);
        }
    }

    if(cycle){
        cout << "Cycle Detected";
    }else{
        cout << "No Cycle Detected";
    }
}