#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
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
    ll n, m;
    cin >> n >> m;
    cout << pr(pr(2, m) + mod - 1, n) << '\n';
}