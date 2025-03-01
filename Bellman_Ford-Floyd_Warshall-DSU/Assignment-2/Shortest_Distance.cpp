#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    long adj_matric[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_matric[i][j] = 0;
            }
            else
            {
                adj_matric[i][j] = LONG_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b;
        long c;
        cin >> a >> b >> c;

        if (adj_matric[a][b] == LONG_MAX)
            adj_matric[a][b] = c;
        else
            adj_matric[a][b] = min(adj_matric[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_matric[i][k] != LONG_MAX && adj_matric[k][j] != LONG_MAX && adj_matric[i][j] > adj_matric[i][k] + adj_matric[k][j])
                {
                    adj_matric[i][j] = adj_matric[i][k] + adj_matric[k][j];
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (adj_matric[a][b] == LONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_matric[a][b] << endl;
        }
    }
    return 0;
}
