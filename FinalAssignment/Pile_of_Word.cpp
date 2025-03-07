#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string first, second;
        cin >> first >> second;

        if (first.length() != second.length())
        {
            cout << "NO" << endl;
        }
        else
        {
            sort(first.begin(), first.end());
            sort(second.begin(), second.end());
            
            if(first == second){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
