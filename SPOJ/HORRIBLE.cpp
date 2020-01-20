#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 2;
int n, h;
int tree[2 * N], lazy[2 * N], Node_Siz[2 * N];

void apply(int p, int value) {
    tree[p] += value * Node_Siz[p];
    if(p < n) lazy[p] += value;
}

void push(int p) {
    for(int s = h; s > 0; --s) {
        int i = p >> s;
        if(lazy[i] != 0) {
            apply(i<<1, lazy[i]);
            apply(i<<1|1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void modify(int l, int r, int value) {
    l += n, r += n;
    int l0 = l, r0 = r - 1;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    while (l0 > 1) l0 >>= 1, tree[l0] = (tree[l0<<1] + tree[l0<<1|1]) + lazy[l0] * Node_Siz[l0];
    while (r0 > 1) r0 >>= 1, tree[r0] = (tree[r0<<1] + tree[r0<<1|1]) + lazy[r0] * Node_Siz[r0];
}

int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    int res = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> n >> c;
        for(int i = n; i < 2 * n; i++){
            Node_Siz[i] = 1;
            lazy[i] = tree[i] = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            Node_Siz[i] = Node_Siz[i<<1] + Node_Siz[i<<1|1];
            lazy[i] = tree[i] = 0;
        }
        h = sizeof(int) * 8 - __builtin_clz(n);
        while(c--){
            bool choice;
            int p, q, val;
            cin >> choice >> p >> q;
            if(choice)
                cout << query(p - 1, q) << '\n';
            else{
                cin >> val;
                modify(p - 1, q, val);
            }
        }
    }
}