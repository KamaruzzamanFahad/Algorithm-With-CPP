#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> edgList[100];
bool visited[100];
int lavle[100];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  visited[src] = true;
  lavle[src] = 0;

  while (!q.empty())
  {
    int parent = q.front();
    q.pop();

    cout << parent << " ";

    for (int child : edgList[parent])
    {
      if (!visited[child])
      {
        q.push(child);
        visited[child] = true;
        lavle[child] = lavle[parent] + 1;
      }
    }
  }
}

int main()
{
  cin >> n >> e;

  while (e--)
  {
    int a, b;
    cin >> a >> b;

    edgList[a].push_back(b);
    edgList[b].push_back(a);
  }

  memset(visited, false, sizeof(visited));
  memset(lavle, -1, sizeof(lavle));
  bfs(0);


  for(int i=0; i<n; i++){
    cout << i << " -> " << lavle[i] << endl;
  }

  
  return 0;
}
