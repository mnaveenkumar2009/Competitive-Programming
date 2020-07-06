#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int pr(int x, int y){
    x %= mod;
    int res = 1;
    while(y){
        if(y&1)
            res= (res * x) % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

const int inv6 = pr(6, mod -2);
int sigmansquare(int x){
     return (((x * (2*x + 1)) % mod) * (((x + 1) * inv6) % mod)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set <int> P;
    for(int i = 2; i <= 1e6; i++){
        int cur = i * i * i;
        while(1){
            int XX = sqrtl(cur);
            if(XX*XX != cur)
                P.insert(cur);
            if(1e18  / i < cur){
                break;
            }
            cur *= i;
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        
        for(auto i:P){
            if(i > n)
                break;
            ans = (ans + (n/i) * i) % mod;
        }
        int SQN = sqrtl(n);
        for(int i = 1; i * i <= SQN; i++){
            ans = (ans + (n/(i*i)) * (i * i)) % mod;
        }
        
        int cur = sqrtl(SQN) + 1;
        while(cur * cur <= n){
            int r = cur;
            int XX = n/(cur*cur);
            r = sqrtl(n/XX);
            // cout << cur << ' ' << r << '\n';
            ans = (ans + (sigmansquare(r) - sigmansquare(cur - 1)) * (XX)) % mod;
            cur = r + 1;
        }
        ans += mod;
        ans %= mod;
        // cout << n << ' ' <<  ans << '\n';
        cout << ans << '\n';
    }
}