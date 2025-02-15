#include<bits/stdc++.h>
using namespace std;
int n,m;
char grid[1000][1000];
pair<int,int> src,dest;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool visited[1000][1000];
int parent[1000][1000];

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>= m){
        return false;
    }
    return true;
}
bool  isGo = false;
void bfs(){
    queue<pair<int,int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while(!q.empty()){
        pair<int,int> par = q.front();
        q.pop();
        int si = par.first;
        int sj = par.second;

        for(int i=0; i<4; i++){
            int ci = si + moves[i].first;
            int cj = sj + moves[i].second;

            if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] != '#'){
                q.push({ci,cj});
                visited[ci][cj] = true;
                parent[ci][cj] = si * m + sj;

                if (grid[ci][cj] == 'D') { 
                    isGo = true;
                    return;
                }
            }

        }
    }

}


void path() {
    int i = dest.first, j = dest.second;
    while (!(i == src.first && j == src.second)) {
        int pi = parent[i][j] / m;
        int pj = parent[i][j] % m;
        if (grid[pi][pj] != 'R') {
            grid[pi][pj] = 'X';
        }
        i = pi;
        j = pj;
    }
}


int main(){
  cin >> n >>m;

  for(int i=0; i<n ; i++){
    for(int j=0; j<m; j++){
        cin >> grid[i][j];
    }
  }

  memset(visited, false, sizeof(visited));
  memset(parent, -1, sizeof(parent));

  for(int i=0; i<n ; i++){
    for(int j=0; j<m; j++){
        if(grid[i][j] == 'R'){
            src = {i,j};
        }

        if(grid[i][j] == 'D'){
            dest = {i,j};
        }
    }
  }

  bfs();

  if(isGo){
    path();
  }
  

  for(int i=0; i<n ; i++){
    for(int j=0; j<m; j++){
        cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
