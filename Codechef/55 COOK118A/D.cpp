#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

const int N = 1e5 + 2;
int n = N;
int tree[2 * N];
void modify(ll p, ll value) {
    for (tree[p += n] = value; p > 1; p >>= 1)
        tree[p>>1] = tree[p] + tree[p^1];
}
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x = time(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        // for(int i = 0; i < n; i++)modify(i, 0);
        int a[n];
        pair <int, int> XX[n];
        for(int i = 0; i < n; i++){
            cin >> XX[i].first;
            XX[i].second = i;
        }
        sort(XX, XX + n);
        for(int i = 0; i < n; i++){
            a[XX[i].second] = i;
        }
        int tot = n * (n + 1);
        tot /= 2;
        ll low = 0, high = tot;
        while(low < high){
            ll mid = (low + high) / 2;
            if(mid == low)mid++;
            int r = -1, le = 0;
            int cur = 0;
            for(int i = 0; i < n; i++){
                if(i){
                    modify(a[i-1], 0);
                    cur -= query(0, a[i-1]);
                }
                if(r < i){
                    modify(a[i], 1);
                }
                r = max(r, i);
                while(r < n - 1){
                    r++;
                    int X = query(a[r], n);
                    if(cur + X >= mid){
                        r--;
                        break;
                    }
                    modify(a[r], 1);
                    cur += X;
                }
                le += r - i + 1;
            }
            if(le * 2 >= tot){
                high = mid - 1;
            }
            else{
                low = mid;
            }
            for(int i = 0; i < n; i++){
                modify(a[i], 0);
            }
        }
        cout << low << '\n';
    }
    // cout << (time(0) - x) << '\n';
}