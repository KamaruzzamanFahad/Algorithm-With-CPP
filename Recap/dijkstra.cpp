#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
int n, e;
vector<pair<int, int>> adj_list[1005];
int dis[1005];
void dijkstra(int src)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
            }
        }
    }
}
int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

// input :
// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5

// output :
// 0 -> 0
// 1 -> 6
// 2 -> 5
// 3 -> 4
// 4 -> 9

// use for:
// 1.Shortest Path
// 2. Shortest distance

// complexcity: O((V + E) log V)
// V = node number || vertex,
// E = edg number