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
        int n;
        cin >> n;
        vector <int> a(n), b(n), c(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }
        sort(c.begin(), c.end());
        sort(b.begin(), b.end());
        if((b == a) || (c[0] != c[n-1])){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}