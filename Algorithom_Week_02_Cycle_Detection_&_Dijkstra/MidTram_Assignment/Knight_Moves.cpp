#include<bits/stdc++.h>
using namespace std;
int n, m;
pair<int,int> king, queen;
bool visited[1000][1000];
vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1},{2, 1},{-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>= m){
        return false;
    }
    return true;
}


int bfs(){
    memset(visited, false, sizeof(visited));

    queue<pair<int,int>> q;
    q.push(king);
    visited[king.first][king.second] = true;

    int countStep = 0;

    while(!q.empty()){

        int size = q.size();
        while (size--){
            pair<int,int> par = q.front();
            q.pop();

            int si = par.first;
            int sj = par.second;
            
            if(si == queen.first && sj == queen.second){
                return countStep;
            }

            for(pair<int,int> move : moves){
                int ci = si + move.first;
                int cj = sj + move.second;

                if(valid(ci,cj) && !visited[ci][cj]){
                    visited[ci][cj] = true;
                    q.push({ci,cj});
                }
            }
        }
        countStep++;
    }
    return -1;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    cin >> n >> m;

    cin >> king.first >> king.second;
    cin >> queen.first >> queen.second;

    cout << bfs() << endl;
  }
  return 0;
}
