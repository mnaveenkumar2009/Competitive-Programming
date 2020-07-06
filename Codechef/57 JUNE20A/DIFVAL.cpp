#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/45428?#comment-304665 
// https://ideone.com/5xMHRD

#define MxN 200008

int d[MxN];
vector <int> Children[MxN];
int timer;
int tin[MxN], tout[MxN];
int euler_tour[MxN * 2];

void dfs(int node, int dep){
    euler_tour[++timer] = node;
    tin[node] = timer;
    d[node] = dep;
    for(auto child:Children[node])
        dfs(child, dep + 1);
    euler_tour[++timer] = node;
    tout[node] = timer;
}

const int maxn = 4e5, maxk = 2e5 + 1;
int root[maxn], L[16 * maxn], R[16 * maxn], sum[16 * maxn];
int rt = 1, sz = 1;
int lpos[maxk];
 
int copy(int v, int &u)
{
    L[sz] = L[v];
    R[sz] = R[v];
    sum[sz] = sum[v];
    return u = sz++;
}
 
void make_root()
{
    copy(root[rt - 1], root[rt]);
    rt++;
}
 
void add(int pos, int x, int v = root[rt - 1], int l = 0, int r = maxn)
{
    sum[v] += x;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(pos < m)
        add(pos, x, copy(L[v], L[v]), l, m);
    else
        add(pos, x, copy(R[v], R[v]), m, r);
}
 
int get(int a, int b, int v, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r);
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        rt = 1;
        sz = 1;
        timer = 0;
        int n;
        cin >> n;
        int A[n+1], P[n+1];
        for(int i = 1; i <= n; i++){
            Children[i].clear();
        }
        P[1] = -1;
        bool we = 1;
        for(int i = 2; i <= n; i++){
            cin >> P[i];
            if(P[i] != i - 1)we = 0;
            Children[P[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        dfs(1,0);
        for(int i = 1; i <= 2*n; i++){
            // cout << i << ' ' << euler_tour[i] << ' ' << lpos[A[euler_tour[i]]] << ' ' << A[euler_tour[i]] << ' ' << d[euler_tour[i]] << '\n';
            make_root();
            add(lpos[A[euler_tour[i]]], 0, d[euler_tour[i]]);
            // add(lpos[A[euler_tour[i]]], 0);
            lpos[A[euler_tour[i]]] = i;
            add(lpos[A[euler_tour[i]]], 1, d[euler_tour[i]]);
            // add(lpos[A[euler_tour[i]]], 1);
        }
        int q, l, r;
        cin >> q;
        int ans = 0, xq, dq;
        while(q--){
            cin >> xq >> dq;
            xq ^= ans;
            dq ^= ans;
            l = tin[xq];
            r = tout[xq];
            // cout << (ans = gett(6, 12, root[11], d[xq] + dq)) << '\n';
            cout << (ans = gett(l, r + 1, root[r], d[xq] + dq)) << '\n';
        }
    }
}