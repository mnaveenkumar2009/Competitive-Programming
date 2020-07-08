#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(c <= a){
            cout << "-1 ";
        }
        else
            cout << "1 ";
        if(a*b <= c)
            cout << "-1\n";
        else
            cout << b << '\n';
    }
}