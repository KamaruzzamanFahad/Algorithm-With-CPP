#include<bits/stdc++.h>
using namespace std;
int n, m;
char grid[100][100];
bool visited[100][100];
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j){
  if(i<0 || i>=n || j<0 || j>=m){
    return false;
  }
  return true;
}

void bfs(int si, int sj){
  queue<pair<int,int>> q;
  q.push({si,sj});
  visited[si][sj]=true;

  while(!q.empty()){
    pair<int,int> prant = q.front();
    q.pop();

    int prant_i = prant.first;
    int prant_j = prant.second;

    cout << prant_i << " " << prant_j << endl;
    
    for(int i=0; i<4; i++){
      int ci = moves[i].first;
      int cj = moves[i].second;

      if(valid(ci,cj) && !visited[ci][cj]){
        q.push({ci,cj});
        visited[ci][cj];
      }
    }

  }
}

int main(){
  
  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> grid[i][j];
    }
  }

  int si, sj;
  cin >> si >>  sj;
  memset(visited, false, sizeof(visited));

  bfs(si,sj);
  
  return 0;
}
