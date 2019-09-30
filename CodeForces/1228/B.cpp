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
    int h, w;
    cin >> h>> w;
    int ans = 1;
    vector < vector <int> > A(h, vector <int> (w, -1));
    for(int i = 0; i < h; i++){
        int x;
        cin >> x;
        if(x<w){
        if(A[i][x] == -1){
            A[i][x] = 1;
        }
        else{
            if(A[i][x] != 1){
                cout << 0;
                return 0;
            }
        }}
        while(x--){
            if(A[i][x] == -1){
                A[i][x] = 0;
            }
            else{
                if(A[i][x] != 0){
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    for(int i = 0; i < w; i++){
        int x;
        cin >> x;
        if(x<h){
        if(A[x][i] == -1){
            A[x][i] = 1;
        }
        else{
            if(A[x][i] != 1){
                cout << 0;
                return 0;
            }
        }}
        while(x--){
            if(A[x][i] == -1){
                A[x][i] = 0;
            }
            else{
                if(A[x][i] != 0){
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    // cout <<"DSf "<<ans<<'\n';
    for(int i = 0; i <h;i++){
        for(int j = 0;j <w;j++){
            if(A[i][j] == -1)
                ans = (ans*2)%mod;
        } 
    }
    cout << ans<<'\n';
}
