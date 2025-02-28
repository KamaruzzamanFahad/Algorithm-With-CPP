#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int edg_list[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                edg_list[i][j] = 0;
            }
            else
            {
                edg_list[i][j] = INT_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg_list[a][b] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(edg_list[i][k] != INT_MAX && edg_list[k][j] != INT_MAX && edg_list[i][j] > edg_list[i][k] + edg_list[k][j]){
                    edg_list[i][j] = edg_list[i][k] + edg_list[k][j];
                }
            }
        }
    }

      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << edg_list[i][j] << " ";
        }
        cout << endl;
      }
    return 0;
}
