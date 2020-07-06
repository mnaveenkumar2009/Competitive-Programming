#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int n, p;
vector <int> b(1e6 + 500, 0), c(1e6 + 500, 0);

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
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> p;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        if(p == 1){
            cout << (n % 2) << '\n';
            continue;
        }
        bool we = 0;
        vector<int> vis;
        for(int i = n - 1; i >= 0; i--){
            // for(int j = 0; j < 10; j++){
            //     cout << b[j] << ' ';
            // }
            // cout << '\n';
            // for(int j = 0; j < 10; j++){
            //     cout << c[j] << ' ';
            // }
            // cout << '\n';
            if(!we){
                ans += pr(p, a[i]);
                ans %= mod;
                c[a[i]]++;
                vis.push_back(a[i]);
                we = 1;
            }
            else{
                b[a[i]]++;
                vis.push_back(a[i]);
                ans -= pr(p, a[i]);
                ans %= mod;
                int j = a[i];
                while(b[j] == p){
                    b[j] = 0;
                    j++;
                    b[j]++;
                    vis.push_back(j);
                }
                if(b[j] == 1 && c[j] == 1){
                    vis.push_back(j);
                    b[j] = c[j] = 0;
                    we = 0;
                }
            }
        }
        for(auto i:vis){
            b[i] = c[i] = 0;
        }
        cout << (ans + mod) % mod << '\n';
    }
}