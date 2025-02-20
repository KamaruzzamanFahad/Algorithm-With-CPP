#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<pair<int,int>> adj_list[100];
int dis[100];


void disktara(int src){
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    cin >> n,e;
}

int main() {
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
        }

    fill(dis, dis+100, 500);

    disktara(0);


  
  return 0;
}
