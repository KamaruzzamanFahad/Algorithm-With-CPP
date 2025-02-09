#include <bits/stdc++.h>
using namespace std;
vector<int> edgList[1000];
bool visited[1000];
int n, e;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

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

    bfs(0);
}