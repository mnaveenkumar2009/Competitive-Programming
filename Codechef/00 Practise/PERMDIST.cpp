#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6+2;
int n;
int tree[2 * N], tree2[2 * N];

void modify(int p, int value) {
    tree2[p+n] = value;
    for (tree[p += n] = value; p > 1; p >>= 1){
        tree[p>>1] = max(tree[p], tree[p^1]);
        tree2[p>>1] = min(tree2[p], tree2[p^1]);
    }
}
int query_max(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tree[l++]);
        if (r&1) res = max(tree[--r], res);
    }
    return res;
}
int query_min(int l, int r) {
    int res = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, tree2[l++]);
        if (r&1) res = min(tree2[--r], res);
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> n >> q;
        int p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            modify(i, p[i]);
        }
        while(q--){
            int x, y;
            cin >> x >> y;
            if(x > y)
                swap(x, y);
            x--;
            y--;
            if(x == y){
                cout << "0\n";
            }
            else{
                if(p[x] < p[y]){
                    cout << "1\n";
                }
                else{
                    int mini = query_min(0, x);
                    int maxi = query_max(y+1, n);
                    if(mini < p[y] || maxi > p[x]){
                        cout << "2\n";
                    }
                    else{
                        if(mini < min(p[x], maxi) && maxi > max(p[y], mini)){
                            cout << "3\n";
                        }
                        else{
                            cout << "-1\n";
                        }
                    }
                }
            }
        }
    }
}