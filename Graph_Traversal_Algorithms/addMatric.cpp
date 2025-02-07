#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;

    int mat[n][n];
    memset(mat,0,sizeof(mat));

    for(int i=0; i<e; i++){
        int a,b;
        cin >>a >>b;

        mat[a][b] =1;
        mat[b][a] =1;
    }
}