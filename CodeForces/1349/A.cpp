#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x = 1;
    cin >> n;
    int a[n];
    int pre[n], suf[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = suf[i] = a[i];
        if(i)
            pre[i] = __gcd(pre[i], pre[i-1]);
    }
    for(int i = n - 2; i >= 0; i--){
        suf[i] = __gcd(suf[i], suf[i+1]);
    }
    for(int i = 0; i < n; i++){
        int gc = 0;
        if(i){
            gc = __gcd(gc, pre[i-1]);
        }
        if(i != n - 1){
            gc = __gcd(gc, suf[i+1]);
        }
        x = (x * gc) / __gcd(gc, x);
    }
    cout << x << '\n';
}