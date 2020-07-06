#include <bits/stdc++.h>
using namespace std;

#define int long long
#define p 31
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
    int P[100005], invP[100005];
    P[0] = invP[0] = 1;
    for(int i = 1; i < 100005; i++){
        P[i] = (P[i-1] * p) % mod;
        invP[i] = pr(P[i], mod - 2);
    }
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size(), ans = 0;
        int hah[n];
        for(int i = 0; i < n; i++){
            hah[i] = s[i] - 'a';
            if(i)
                hah[i] += (hah[i-1] * p);
            hah[i] %= mod;
        }
        for(int i = 2; i < n; i += 2){
            // s[i:n]
            int x = hah[i/2 - 1], y = hah[i-1] - P[i/2] * hah[i/2 - 1];
            x %= mod;
            x += mod;
            x %= mod;
            y %= mod;
            y += mod;
            y %= mod;
            if(x == y){
                int siz = (n - i) / 2;
                x = hah[n-1] - hah[n-1-siz] * P[siz], y = hah[i + siz - 1] - P[siz] * hah[i-1];
                x %= mod;
                x += mod;
                x %= mod;
                y %= mod;
                y += mod;
                y %= mod;
                if(x == y){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}