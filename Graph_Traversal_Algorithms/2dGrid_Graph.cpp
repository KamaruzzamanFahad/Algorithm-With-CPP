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

void dfs(int si, int sj){
  cout << si << " " << sj << endl;
  visited[si][sj] = true;

  for(int i=0; i<4; i++){
    int  ci = si+ moves[i].first;
    int cj = sj + moves[i].second;

    if(valid(ci,cj) && !visited[ci][cj]){
      dfs(ci,cj);
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

  dfs(si,sj);
  
  return 0;
}
