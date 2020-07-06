#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int pr(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i){
            a[i] += a[i-1];
        }
        a[i] %= mod;
    }
    // summation ai - aj * 1/i  *1/j for all i > j
    int pinv[n], pinvarr[n];
    for(int i = 0; i < n; i++){
        pinvarr[i] = (a[i] * pr(i + 2, mod - 2)) % mod;
        pinv[i] = pr(i + 2, mod - 2);
        if(i){
            pinv[i] += pinv[i - 1];
            pinvarr[i] += pinvarr[i - 1];
        }
        pinv[i] %= mod;
        pinvarr[i] %= mod;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + pr(i + 1, mod - 2) * a[i]) % mod;
        if(i){
            ans = (ans + pr(i + 1, mod - 2) * ((a[i] * pinv[i - 1]) % mod - pinvarr[i - 1])) % mod;
        }
        ans += mod;
        ans %= mod;
    }
    cout << ans<<'\n';
}