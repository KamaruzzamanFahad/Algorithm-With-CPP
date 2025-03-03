#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = LLONG_MAX;

ll n, e;
vector<pair<ll, ll>> adj_list[1000005];
ll dis[1000005], parent[1000005];

void dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    fill(dis, dis + n + 1, INF); 
    fill(parent, parent + n + 1, -1); 

    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<ll, ll> current = pq.top();
        pq.pop();

        ll par_node = current.second;
        ll par_dis = current.first;

        if (par_dis > dis[par_node]) continue; 

        for (auto child : adj_list[par_node]) {
            ll child_node = child.first;
            ll child_dis = child.second;

            if (par_dis + child_dis < dis[child_node]) {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;
            }
        }
    }
}

int main() {
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1);

    if (dis[n] == INF) {
        cout << -1;
    } else {
        vector<ll> path;
        for (ll node = n; node != -1; node = parent[node]) {
            path.push_back(node);
        }
        reverse(path.begin(), path.end());

        for (auto x : path) {
            cout << x << " ";
        }
    }

    return 0;
}
