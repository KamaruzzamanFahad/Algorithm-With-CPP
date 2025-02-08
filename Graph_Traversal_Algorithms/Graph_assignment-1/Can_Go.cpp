#include <bits/stdc++.h>
using namespace std;
int n, m;
int di = -1, dj = -1;
char grid[1000][1000];
bool visited[1000][1000];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

bool CanGo = false;
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> prant = q.front();
        q.pop();

        int prant_i = prant.first;
        int prant_j = prant.second;

        if (prant_i == di && prant_j == dj)
        {
            CanGo = true;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = prant_i + moves[i].first;
            int cj = prant_j + moves[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && (grid[ci][cj] != '#'))
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    int si = -1, sj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    if (si == -1 || sj == -1 || di == -1 || dj == -1)
    {
        cout << "NO";
        return 0;
    }

    if (si == di && sj == dj)
    {
        cout << "YES";
        return 0;
    }

    memset(visited, false, sizeof(visited));

    bfs(si, sj);

    if (CanGo)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
