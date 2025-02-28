#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
  int a, b, c;
  Edge(int a, int b, int c)
  {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};

int n, e;
int dis[105];
vector<Edge> edg_list;

void bellman_ford()
{
  for (int i = 0; i < n; i++)
  {
    for (auto ed : edg_list)
    {
      if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
      {
        dis[ed.b] = dis[ed.a] + ed.c;
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

    edg_list.push_back(Edge(a, b, c));
  }

  for (int i = 0; i < n; i++)
  {
    dis[i] = INT_MAX;
  }
  dis[0] = 0;
  bellman_ford();

  for (int i = 0; i < n; i++)
  {
    cout << i << " -> " << dis[i] << endl;
  }

  return 0;
}
