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
        int n, x, c;
        vector <int> a(2, 0);
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            cin >> c;
            a[c&1]++;
        }
        if(!a[1]){
            cout << "No\n";
            continue;
        }
        a[1]--;
        x--;
        // x even nums;
        if(x & 1){
            x = max(1LL, x - ((a[1]/2) * 2));
        }
        else{
            x = max(0LL, x - ((a[1]/2) * 2));   
        }
        x = max(0LL, x - a[0]);
        if(x == 0){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}