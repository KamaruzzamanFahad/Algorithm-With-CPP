#include<bits/stdc++.h>
using namespace std;
# define INF INT_MAX
class Edge{
    public:
    int a,b,c;
    Edge(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n,e;
vector<Edge> edg_list;
int dis[1005];


void bellmanFord(int src){
    dis[src] = 0;

    for(int i=0; i<n-1; i++){

        for(auto x : edg_list){
            int a = x.a;
            int b = x.b;
            int c = x.c;
            if(dis[a] != INF && dis[a] + c < dis[b] ){
                dis[b] = dis[a] + c;
            }
        }
    }
}


int main(){
    cin >> n >> e;

    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        edg_list.push_back(Edge(a,b,c));
    }

    for(int i=0; i<n; i++){
        dis[i] = INF;
    }

    bellmanFord(0);

    for(int i=0; i<n; i++){
        cout << i << " -> " << dis[i] << endl;
    }
  
  return 0;
}


// input : 
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// output : 
// 0 -> 0
// 1 -> 7
// 2 -> 5
// 3 -> 10

// use for : 
// 1. single source distance/path with negative weight cycle  

// complexcity : O(V * E)
// v = node number || vertex
// e = edge number
