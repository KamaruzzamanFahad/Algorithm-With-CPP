#include<bits/stdc++.h>
using namespace std;

int main(){
  int q;
  cin >> q;

  while(q--){
    int t;
    cin >> t;

    priority_queue<pair<int,int>> pq;

    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        pq.push({a,i});
    }

    pair<int,int> top1 = pq.top();
    pq.pop();
    pair<int,int> top2 = pq.top();

    if(top1.second < top2.second){
        cout << top1.second << " " << top2.second << endl;
    }else{
        cout << top2.second  << " " << top1.second<< endl;
    }

    
  }
  return 0;
}

