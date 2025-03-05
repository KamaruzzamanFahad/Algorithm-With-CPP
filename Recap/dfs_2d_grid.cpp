#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[10005][10005];
bool visited[10005][10005];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{

    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj; // child index
        ci = si + moves[i].first;
        cj = sj + moves[i].second;

        if (valid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int si, sj; // source
    cin >> si >> sj;

    dfs(si, sj);

    // or
    // for (int i = 0; i < n; i++) // Ensure all components are visited
    // {
    //     if (!visited[i])
    //     {
    //         dfs(i);
    //     }
    // }

    // for grid print
    //  for(int i=0; i<n; i++){
    //      for(int j=0; j<m; j++){
    //         cout << grid[i][j];
    //      }
    //      cout << endl;
    //  }

    return 0;
}

// input:
// 3 4
// ....
// ....
// ....
// 1 2

// output:
// 1 2
// 0 2
// 0 1
// 1 1
// 2 1
// 2 0
// 1 0
// 0 0
// 2 2
// 2 3
// 1 3
// 0 3

// use for :
// 1.Number of Islands , components
// 2. path finding src to distant possible path