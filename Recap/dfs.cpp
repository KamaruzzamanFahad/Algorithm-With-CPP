#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> edg_list[10005];
bool visited[10005];

void dfs(int src)
{
    cout << src << " ";
    visited[src] = true;

    for (int child : edg_list[src])
    {
        if (!visited[child])
        {
            dfs(child);
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

        edg_list[a].push_back(b);
        edg_list[b].push_back(a); // for unweighted
    }

    // fill(begin(visited), end(visited), false);
    memset(visited, sizeof(visited), false);

    dfs(0);

    // or
    // for (int i = 0; i < n; i++) // Ensure all components are visited
    // {
    //     if (!visited[i])
    //     {
    //         dfs(i);
    //     }
    // }

    return 0;
}


// input: 
// 7 7
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5

// output: 0 1 3 2 5 4 6 

// use for: 
// 1. full graph travarsal 
// 2. Connected Component
// 3.maze solve