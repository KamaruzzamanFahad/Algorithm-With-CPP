#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[10005];

int find(int node)
{

  if (par[node] == -1)
  {
    return node;
  }
  int leader = find(par[node]);
  par[node] = leader;
  return leader;
}

void dsu_unioun(int node1, int node2)
{
  int leader1 = find(node1);
  int leader2 = find(node2);

  if (group_size[leader1] > group_size[leader2])
  {
    par[leader2] = leader1;
    group_size[leader1] += group_size[leader2];
  }
  else
  {
    par[leader1] = leader2;
    group_size[leader2] += group_size[leader1];
  }
}
int main()
{
  memset(par, -1, sizeof(par));
  memset(group_size, 1, sizeof(group_size));

  dsu_unioun(1, 2);


  for(int i=0; i<6; i++){
    cout << i << " -> " << par[i] << endl;
  }

  return 0;
}
