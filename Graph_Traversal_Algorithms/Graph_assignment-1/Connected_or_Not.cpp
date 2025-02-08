#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,e;
  cin >> n >>e;

  int adj_matric[n][n];
  
  memset(adj_matric, 0, sizeof(adj_matric));

  for(int i=0; i<e; i++){
    int a,b;
    cin >> a >>b;

    adj_matric[a][b] = 1;
  }

  int q;
  cin >> q;

  while(q--){
    int a,b;
    cin >> a >>b;
    if(a==b){
        cout << "YES" << endl;
    }
    else if(adj_matric[a][b]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
  }
  return 0;
}
