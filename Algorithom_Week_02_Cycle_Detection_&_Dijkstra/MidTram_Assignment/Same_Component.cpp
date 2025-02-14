#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int visited[1000][1000];
int n,m;
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
int counts =0;
pair<int,int> src,dest;

bool isSame = false;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>= m){
        return false;
    }
    return true;
}

void dfs(int si, int sj){
    visited[si][sj] = true;
    if(si== dest.first && sj == dest.second){
        isSame = true;
        return;
     }

    for(int i=0; i<4; i++){
        int ci = si + moves[i].first;
        int cj = sj + moves[i].second;

        if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] != '-'){
            if(ci== dest.first && cj == dest.second){
               isSame = true;
               return;
            }
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

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    src = {a,b};
    dest = {c,d};


    memset(visited, false, sizeof(visited));

    if (grid[a][b] == '-' || grid[c][d] == '-') {
        cout << "NO" << endl;
        return 0;
    }
    
    dfs(a,b);

    if(isSame){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
  return 0;
}
