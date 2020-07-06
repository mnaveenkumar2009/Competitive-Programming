#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

int fact[300005];

int block_s;
bool comp(pair <pair <int, int>, int> &x, pair <pair <int, int>, int> &y){
    if((x.first.second/block_s) < (y.first.second/block_s))
        return 1;
    if((x.first.second/block_s) > (y.first.second/block_s))
        return 0;
    return (x.first.first) > (y.first.first)
}
unordered_map <int, set <pair <int, int> > > D;
unordered_map <int, int> X;
int XoR;
int inv(int x){
    int res = 1;
    int y = mod - 2;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}
int ncr(int n, int r){
    int ret = fact[n] * inv((fact[n - r] * fact[r]) % mod);
    return ret % mod;
}
void inc(){
    auto it = D.lower_bound({y, 0});
    if(it != D.end()){
        if((*it).first == y){
            int F = (*it).second + 1;
            D[i].erase(it);

            D[i].insert({y, F});
        }
        else{
            D.insert({y, 1});
        }
    }
    else{
        D[i].insert({y, 1});
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for(int i = 1; i < 3e5; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 25; i++)
            D[i].clear();
        X.clear();
        int n, q;
        cin >> n;
        block_s = sqrt(n) + 2;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cin >> q;
        pair <pair <int, int>, int> Q[q];
        for(int i = 0; i < q; i++){
            cin >> Q[i].first.first >> Q[i].first.second;
            Q[i].first.first--;
            Q[i].first.second--;
            Q[i].second = i;
        }
        sort(Q, Q + q, comp);
        int curl = -1, curr = -1;
        XoR = 0;
        for(int i = 0; i < q; i++){
            int l = Q[i].first.first, r = Q[i].second.first;
            if(l > curr || r < curl){
                for(int i = 0; i < 25; i++)
                    D[i].clear();
                X.clear();
                curl = l;
                curr = l - 1;
                XoR = 0;
            }
            while(curl > l){
                curl--;
                int y = (++X[a[curl]]);
                XoR ^= y ^ (y-1);
                inc(y);
            }
            while(curl < l){
                curl++;
                int y = (--X[a[curl]]);
                XoR ^= y ^ (y+1);
                dec(y);
            }
            while(curr > r){
                curr--;
                int y = (--X[a[curl]]);
                XoR ^= y ^ (y+1);
                dec(y);
            }
            while(curr < r){
                curr++;
                int y = (++X[a[curl]]);
                XoR ^= y ^ (y-1);
                inc(y);
            }

            int ans = 0;
            for(int i = 20; i >= 0; i--){
                if(XoR & (1<<i)){
                    for(auto j:D[i]){
                        X, a
                        X ^ a ^ a - x = 0
                        ans += ncr(j.first, j.first - (j.first ^ XoR)) * j.second;
                        ans %= mod;
                    }
                    break;
                }
            }
            cout << ans << '\n';
            curl = l;
            curr = r;
        }
    }
}