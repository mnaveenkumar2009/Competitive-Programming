#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool we = 1;
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                cout << n/i << ' ' << n - n/i << '\n';
                we = 0;
                break;
            }
        }
        if(we)
            cout << 1 << ' ' << n-1 << '\n';
    }
}