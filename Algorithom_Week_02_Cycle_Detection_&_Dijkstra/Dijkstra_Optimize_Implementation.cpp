#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<pair<int, int>> adj_list[100];
int dis[100];

void bfs(int src)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, src});
  dis[src] =   0;

  while (!pq.empty())
  {
    pair<int, int> top = pq.top();
    pq.pop();

    int parNode = top.second;
    int parDis = top.first;

    for (auto child : adj_list[parNode])
    {
      int childNode = child.first;
      int childDis = child.second;

      if (parDis + childDis < dis[childNode])
      {
        dis[childNode] = parDis + childDis;
        pq.push({dis[childNode], childNode});
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

  memset(dis, 999999, sizeof(dis));

  bfs(0);

  for(int i=0; i<n; i++){
    cout << i << " -> " << dis[i] << endl;
  }

  return 0;
}
