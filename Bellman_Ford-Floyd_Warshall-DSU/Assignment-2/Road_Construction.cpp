#include <bits/stdc++.h>
using namespace std;
int n, e;
int par[100005];
int grupSize[100005];
int num_of_cmp = 0;
int mx_cmp =0;


int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }

    int lider = find(par[node]);
    par[node] = lider;
    return lider;
}

void dsu_union(int node1, int node2)
{

    int leader1 = find(node1);
    int leader2 = find(node2);

    if(leader1 == leader2) return;

    if (grupSize[leader1] > grupSize[leader2])
    {
        par[leader2] = leader1;
        grupSize[leader1] += grupSize[leader2];
        mx_cmp = max(mx_cmp, grupSize[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        grupSize[leader2] += grupSize[leader1];
        mx_cmp = max(mx_cmp, grupSize[leader2]);
    }

    num_of_cmp -=1;
    
}

int main()
{
    cin >> n >> e;
    num_of_cmp = n;
    

    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        grupSize[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leader1 = find(a);
        int leader2 = find(b);
        
        if(leader1!= leader2){
            dsu_union(a,b);
        }

        cout << num_of_cmp << " " << mx_cmp << endl;

    }
    return 0;
}
