#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int noi = 1000;
        while(noi--){
            if(x>=y){
                y = x;
                break;
            }
            x/=2;
            x*=3;
        }
        if(x!=y){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}