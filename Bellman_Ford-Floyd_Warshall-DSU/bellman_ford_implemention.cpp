#include <bits/stdc++.h>
using namespace std;

class Edg
{
public:
  int a, b, c;
  Edg(int a, int b, int c)
  {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};
int dis[1005];

int main()
{
  int n, e;
  cin >> n >> e;
  vector<Edg> edge_list;

  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edge_list.push_back(Edg(a, b, c));
  }

  for (int i = 0; i < n; i++)
  {
    dis[i] = INT_MAX;
  }
  dis[0] = 0;

  for (int i = 0; i < n; i++)
  {
    for (auto ed : edge_list)
    {
      if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
      {
        dis[ed.b] = dis[ed.a] + ed.c;
      }
    }
  }

  for(int i=0; i<n; i++){
    cout << i << " -> " << dis[i] << endl;
  }

  return 0;
}
