#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll anss = 1;
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
void f(ll n, ll x){
    // cout << n << x << '\n';
    ll y = x;
    while(1){
        // cout << x << ' '<< n/y << '\n';
        // cout <<pr(x, n / y)<<'\n';
        // cout << anss << '\n';
        anss *= pr(x, n / y);
        anss %= mod;
        // cout << anss << '\n';
        if(n/y < x)
            break;
        y *= x;
    }
}
int main(){
    ll x, n;
    cin >> x >> n;
    for(ll i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            f(n, i);
        }
        while( x % i == 0){
            x/=i;
        }
    }
    if(x != 1){
        f(n, x);
    }
    cout << anss << '\n';
}