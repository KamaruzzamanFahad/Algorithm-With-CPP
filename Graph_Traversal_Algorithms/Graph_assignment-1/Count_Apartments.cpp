#include <bits/stdc++.h>
using namespace std;
int n, m;
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


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }


    memset(visited, false, sizeof(visited));


     int apartment = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                apartment++;
            }
        }
    }

    cout << apartment << endl;

   

   

    



    return 0;
}
