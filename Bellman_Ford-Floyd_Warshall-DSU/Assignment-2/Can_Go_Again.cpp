#include <bits/stdc++.h>
using namespace std;

int n, e;

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

vector<Edge> edg_list;

bool cycle(int src)
{
    long long dis[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dis[i] = LONG_MAX;
    }
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edg_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dis[a] != LONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    for (auto ed : edg_list)
    {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != LONG_MAX && dis[a] + c < dis[b])
        {
            return true;
        }
    }

    return false;
}

void bellmanford(int src, int dest)
{
    long long dis[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dis[i] = LONG_MAX;
    }
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edg_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if (dis[a] != LONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    if (dis[dest] == LONG_MAX)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << dis[dest] << endl;
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

    int src, t;
    cin >> src >> t;

    if (cycle(src))
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    for (int i = 0; i < t; i++)
    {
        int dest;
        cin >> dest;
        bellmanford(src, dest);
    }

    return 0;
}