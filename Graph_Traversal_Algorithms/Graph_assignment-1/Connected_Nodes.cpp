#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,e;
  cin >> n >> e;

  vector<int> adj_list[n];
while(e--){
    int a,b;
    cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
}

int q;
cin >> q;


while(q--){
    int x;
    cin >> x;

    if(adj_list[x].empty()){
        cout << -1 << endl;
    }else{

        vector<int> temp;

    for(int child : adj_list[x]){
        temp.push_back(child);
    }

    sort(temp.begin(), temp.end() , greater<int>());

    for(int value : temp){
        cout << value << " ";
    }

    cout << endl;

    }

    


}

  return 0;
}
