#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int a[2] = {0,0};
        for(auto i:s){
            a[i - '0']++;
        }
        if(min(a[0], a[1])&1)
            cout << "DA\n";
        else
            cout << "NET\n";
    }
}