#include <bits/stdc++.h>
using namespace std;
vector<int> edgList[100];
bool visited[100];
int n, e;
int parent[100];
bool cycle = false;

void dfs(int src)
{
    visited[src] = true;

    for (int c : edgList[src])
    {

        if (visited[c] && parent[src] != c)
        {
            cycle = true;
            return;
        }

        if (!visited[c])
        {
            parent[c] = src;
            dfs(c);
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
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    if (cycle)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "No Cycle Detected";
    }
}