#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n&1){
        cout << "NO\n";
    }
    else{
        int x[n], y[n];
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        bool we = 1;
        for(int i = 0; i < n/2; i++){
            if((x[i + 1] - x[i]) * (y[(i+n/2 + 1) % n] - y[i+n/2]) != (y[i + 1] - y[i]) * (x[(i+n/2 + 1) % n] - x[i+n/2]))
                we = 0;
        }
        if(we){
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}