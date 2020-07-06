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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int a[n];
        long long ans = 0, cur_grt[2] = {0, 0};
        vector <int> freq(2*n + 1), p(2*n + 1);
        freq[n] = 1;
        int x = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                x++;
                cur_grt[x&1] -= freq[x + n];
            }
            if(s[i] == ')'){
                cur_grt[x&1] += freq[x + n];
                x--;
                a[i] = cur_grt[(x+1)&1] - p[x + n];
                ans = (ans + a[i] * (n - i)) % mod;
                p[x + n] += a[i];
            }
            freq[x + n]++;
        }
        ans = (ans * pr((n * (n + 1))/2,mod - 2)) % mod;
        cout << ans << '\n';
    }
}