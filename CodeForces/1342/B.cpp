#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        bool x[2] = {0, 0};
        string s;
        cin >> s;
        int n = s.size();
        for(auto i:s){
            x[i-'0'] = 1;
        }
        if(!x[0] || !x[1])cout << s;
        else
        for(int  i= 0; i < n; i++){
            cout << "01";
        }cout << '\n';
    }
}