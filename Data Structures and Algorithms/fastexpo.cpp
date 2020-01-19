#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    #define int long long
    int n, m;
    int ans = 1;
    cin >> n >> m;
    while(m){
        if(m & 1){
            m--;
            ans = (ans * n) % mod;
        }
        n = (n * n) % mod;
        m >>= 1;
    }
    cout << ans << '\n';
}