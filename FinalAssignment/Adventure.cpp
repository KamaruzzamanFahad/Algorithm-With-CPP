#include<bits/stdc++.h>
using namespace std;
int val[10005], weight[10005];
int dp[10005][10005];


int knapsack(int n, int mxw){
    if(n<0 || mxw <=0) return 0;
    if(dp[n][mxw] != -1) return dp[n][mxw];

    if(weight[n] <= mxw){
        int op1 = knapsack(n-1, mxw - weight[n])  + val[n];
        int op2 = knapsack(n-1, mxw);
        dp[n][mxw] = max(op1,op2);
        return dp[n][mxw];
    }else{
        dp[n][mxw] = knapsack(n-1, mxw);
        return dp[n][mxw];
    }
}


int main(){
  int t;
  cin >> t;

  while(t--){
    int n, mxw;
    cin >> n >> mxw;

    for(int i=0; i<n; i++){
        cin >> weight[i];
    }

    for(int i=0; i<n; i++){
        cin >> val[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=mxw; j++){
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n-1, mxw) << endl;
  }

  return 0;
}
