#include<bits/stdc++.h>
using namespace std;
int par[1005];
int grup_size[1005];

int find(int node){
    if(par[node] == -1) return;

    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(grup_size[leader1] > grup_size[leader2]){
        par[leader2] = leader1;
        grup_size[leader1] += grup_size[leader2];
    }else{
        par[leader1] = leader2;
        grup_size[leader2] += grup_size[leader1];
    }
}

int main(){
    memset(par, -1, sizeof(par));
    memset(grup_size, 1, sizeof(grup_size));

    dsu_union(1,2);
  
  return 0;
}

// use for :
// 1. Connected Components
// 2. cycle dit
