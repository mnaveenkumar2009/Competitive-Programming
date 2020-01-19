#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 2;
int h;
int tree[2 * N], lazy[N];

void apply(int p, int value) {
    tree[p] = max(tree[p], value);
    if(p < N) lazy[p] = max(lazy[p], value);
}

void push(int p) {
    for(int s = h; s > 0; --s) {
        int i = p >> s;
        if(lazy[i] != 0) {
            apply(i<<1, lazy[i]);
            apply(i<<1|1, lazy[i]);
        }
    }
}

void modify(int l, int r, int value) {
    l += N, r += N;
    int l0 = l, r0 = r - 1;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    while (l0 > 1) l0 >>= 1, tree[l0] = max(max(tree[l0<<1], tree[l0<<1|1]), lazy[l0]);
    while (r0 > 1) r0 >>= 1, tree[r0] = max(max(tree[r0<<1], tree[r0<<1|1]), lazy[r0]);
}

int query(int l, int r) {
    l += N, r += N;
    push(l);
    push(r - 1);
    int res = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tree[l++]);
        if (r&1) res = max(res, tree[--r]);
    }
    return res;
}
signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 2 * N; i++){
        lazy[i] = tree[i] = 0;
    }
    h = sizeof(int) * 8 - __builtin_clz(N);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        modify(l - 1, r, r - 1);
    }
    int a[N];
    for(int i = 0; i < N; i++){
        a[i] = query(i, i + 1);
        if(a[i] == 0)
            a[i] = i;
        // if(i < 20)
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    int jump[N][30];
    for(int j = 0; j < 30; j++)
        for(int i = 0; i < N; i++){
            if(j){
                jump[i][j] = jump[jump[i][j-1]][j-1];
            }
            else{
                jump[i][j] = a[i];
            }
        }
    while(m--){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int ans = 0;
        while(1){
            if(jump[x][0] == x){
                cout << "-1\n";
                break;
            }
            if(jump[x][0] >= y){
                cout << ans + 1 << '\n';
                break;
            }
            for(int i = 29; i >= 0; i--){
                if(jump[x][i] < y){
                    ans += (1LL << i);
                    x = jump[x][i];
                }
            }
        }
    }
}