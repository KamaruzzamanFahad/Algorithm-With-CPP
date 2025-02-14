#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int visited[1000][1000];
int n,m;
vector<pair<int,int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>= m){
        return false;
    }
    return true;
}

int counts =0;
int elementCount[1000];

void dfs(int si, int sj){
    visited[si][sj] = true;
    elementCount[counts] ++;

    for(int i=0; i<4; i++){
        int ci = si + moves[i].first;
        int cj = sj + moves[i].second;

        if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] != '-' ){
            
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

    for(int i=0; i<1000; i++){
        elementCount[i] == 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(!visited[i][j] && grid[i][j] != '-'){
                
                dfs(i,j);
                counts ++;
            }
        }
    }


    int minimum = INT_MAX;

    for(int i=0; i<counts; i++){
        minimum = min(minimum, elementCount[i]);
    }

    if(counts == 0){
        cout << -1;
    }else{
        cout << minimum;
    }




  
  return 0;
}
