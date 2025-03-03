#include <bits/stdc++.h>
using namespace std;
int per[1005];
int grup_size[1005];
int n, e;

int find(int node)
{
    if (per[node] == -1)
        return node;

    int leader = find(per[node]);
    per[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 != leader2)
    {

        if (grup_size[leader1] > grup_size[leader2])
        {
            per[leader2] = leader1;
            grup_size[leader1] += grup_size[leader2];
        }
        else
        {
            per[leader1] = leader2;
            grup_size[leader2] += grup_size[leader1];
        }
    }
}

int main()
{
    cin >> n;
    e = n - 1;
    vector<pair<int, int>> cpm_remove;
    vector<pair<int, int>> cpm_add;
    int cycleNode = -1;

    for (int i = 1; i <= n; i++)
    {
        per[i] = -1;
        grup_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leader1 = find(a);
        int leader2 = find(b);

        if (leader1 == leader2)
        {
            cpm_remove.push_back({a, b});
            cycleNode = a;
        }
        else
        {
            dsu_union(a, b);
        }
    }
    if (cycleNode == -1)
        cycleNode = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i == cycleNode)
            continue;
        int leader1 = find(cycleNode);
        int leader2 = find(i);

        if (leader1 != leader2)
        {
            cpm_add.push_back({cycleNode, i});
            dsu_union(cycleNode, i);
        }
    }

    cout << cpm_remove.size() << endl;

    for (int i = 0; i < cpm_remove.size(); i++)
    {
        cout << cpm_remove[i].first << " " << cpm_remove[i].second << " " << cpm_add[i].first << " " << cpm_add[i].second << endl;
    }

    return 0;
}
