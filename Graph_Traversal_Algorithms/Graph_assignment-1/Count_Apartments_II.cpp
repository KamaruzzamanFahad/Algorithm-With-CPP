#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<int> component;

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
    int countComponent = 0;

    while (!q.empty())
    {
        pair<int, int> prant = q.front();
        q.pop();
        countComponent++;

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

    component.push_back(countComponent);
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

    bool foundApartment = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                 foundApartment = true;
            }
        }
    }

    
    if (!foundApartment)
    {
        cout << "\n";
        return 0;
    }

    sort(component.begin(), component.end());

    for(int x : component){
        cout << x << " ";
    }

   

   

    memset(visited, false, sizeof(visited));



    return 0;
}
