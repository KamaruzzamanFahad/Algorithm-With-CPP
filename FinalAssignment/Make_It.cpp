#include<bits/stdc++.h>
using namespace std;
long long int dp[1000005];

long long int  isPosible(long long int  n){
    dp[1] = true;

    for(long long int  i=0; i<n; i++){
        if(dp[i]){
            if(1+3 <= n) dp[i+3] = true;
            if(1*2 <= n) dp[i*2] = true;
        }
    }
    return dp[n];
}


int main(){
  int n;
  cin >> n;

  for(long long int  i=0; i<n; i++){
    dp[i] = false;
  }

  while(n--){
    int t;
    cin >> t;
    if(isPosible(t)){
        cout << "YES"<< endl;
    }else{
        cout << "NO" << endl;
    }
  }
  return 0;
}
