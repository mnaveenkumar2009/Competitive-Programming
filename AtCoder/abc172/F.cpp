#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    int y = x ^ a[0] ^ a[1], y2 = 0;
    int X = (a[0] + a[1] - y);
    bool we = 1;
    if(X & 1)
        we = 0;

    for(int i = 1; i < 61; i++){
        if(X & (1LL << i)){
            if(y & (1LL << (i-1)))
                we = 0;
            else
                y2 |= (1LL << (i-1));
        }
    }
    int ans = y2;
    for(int i = 60; i >= 0; i--){
        if(ans + (1LL << i) <= a[0]){
            if(y & (1LL << i))
                ans |= (1LL << i);
        }
    }
    if((!we) || (ans > a[0]) || (ans == 0)){
        cout << "-1\n";
        return 0;
    }
    cout << a[0] - ans << '\n';
}