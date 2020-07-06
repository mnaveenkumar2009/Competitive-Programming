#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        bool we = 1;
        for(int i = 0; i <n ;i++){
            if(a[i] == c[i] || b[i] == c[i]){
                continue;
            }
            else{
                we = 0;
            }
        }
        if(we){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}