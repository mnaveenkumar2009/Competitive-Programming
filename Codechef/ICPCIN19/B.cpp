#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pr(ll x, ll y)
{
    ll res = 1; 

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}
int main(){
    int n, k;
    cin >> n;
    while(cin >> n >> k){
        vector <int> a(4, 0);
        a[0] = 1;
        ll ninv = pr(n, mod - 2), inv2 = pr(2, mod - 2);
        for(int i = 0; i < k; i++){
            vector <int> b(4, 0);
            b[0] = (a[0] * (((n + ninv - 1) * ninv)%mod)) + ((a[1] + a[2]) * ((inv2 * ((ninv * ninv)%mod))%mod))%mod;
            b[0] %= mod;
            b[1] = ;
            a = b;
        }
        cout << b[0] << '\n';
    }
}