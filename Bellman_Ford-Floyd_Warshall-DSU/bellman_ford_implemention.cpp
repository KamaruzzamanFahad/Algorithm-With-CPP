#include<bits/stdc++.h>
using namespace std;


class Edg {
    public:
    int a,b,c;
    Edg(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

};

int main(){
  int n,e;
  cin >> n >> e;
  vector<Edg> edge_list;

  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    edge_list.push_back(Edg(a,b,c));
  }

  for(auto ed : edge_list){
    cout << ed.a << " " << ed.b << " " << ed.c << endl;
  }
  return 0;
}
