#include<bits/stdc++.h>
using namespace std;
# define INF INT_MAX
int n,e;
int adj_mat[1005][1005];

void floyedWarshall(){
   
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( adj_mat[i][k] != INF && adj_mat[k][j] != INF && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]){
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }
}

int main(){
    cin >> n >> e;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) adj_mat[i][j] = 0;
            else adj_mat[i][j] = INF;
        }
    }

    while(e--){
        int a, b,c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c // undirected
    }

    floyedWarshall();

    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj_mat[i][j] == INF) cout << "INF ";
            else cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }


    
  
  return 0;
}


// input : 
// 4 5
// 0 1 3
// 0 2 6
// 1 2 2
// 1 3 5
// 2 3 4


// output : 
// 0 3 5 8 
// INF 0 2 5 
// INF INF 0 4 
// INF INF INF 0 

// complexcity : O(v^3)
// v = node number || vertex

// use for:
// 1.  all-pairs shortest path/distance
