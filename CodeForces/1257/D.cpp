#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll N = 2e6+2;
ll n, m;
ll tree[2 * N], tree2[2*N];
void modify(ll p, ll value) {
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = max(tree[p],tree[p^1]);
}
ll query(ll l, ll r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tree[l++]);
        if (r&1) res = max(res, tree[--r]);
    }
    return res;
}
void modify2(ll p, ll value) {
    for (tree2[p += m] = value; p > 1; p >>= 1) tree2[p>>1] = max(tree2[p],tree2[p^1]);
}
ll query2(ll l, ll r) {
    ll res = 0;
    for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tree2[l++]);
        if (r&1) res = max(res, tree2[--r]);
    }
    return res;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            modify(i, a[i]);
        }
        cin >> m;
        int p[m];
        pair <int, int> b[m];
        for(int i = 0; i < m; i++){
            cin >> b[i].first >> b[i].second;
        }
        sort(b, b+m);
        for(int i = 0; i < m; i++){
            p[i] = b[i].first;
            modify2(i, b[i].second);
        }

        int day = 0, l = 0;
        while(l != n){
            int low = 0, high = n - l;
            while(low < high){
                int mid = (low + high)/2;
                if(low == mid)mid++;
                int req_pow = query(l, l + mid);
                int pos = lower_bound(p, p+m, req_pow) - p;
                int can_kill = query2(pos, m);
                if(can_kill >= mid)
                    low = mid;
                else
                    high = mid - 1;
            }
            if(low == 0){
                day = -1;
                break;
            }
            l += low;
            day++;
        }
        cout << day << '\n';
    }
}