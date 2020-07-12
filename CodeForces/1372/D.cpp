#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;
    int ans = 0;
    vector <int> a(2*n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }
    if(n == 1){
        cout << a[0];
        return 0;
    }
    for(int i = 2; i < 2*n; i++){
        a[i] += a[i-2];
    }
    for(int i = 0; i < 2 * n; i++){
        if(i >= n + 1)
            ans = max(ans, a[i] - a[i - n - 1]);
        else
            ans = max(ans, a[i]);
    }
    cout << ans << '\n';
}