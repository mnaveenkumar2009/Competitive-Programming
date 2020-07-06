#include <bits/stdc++.h>
using namespace std;

#define MxN 200002

int A[MxN], P[MxN], a[MxN], d[MxN], S[MxN];
vector <int> Children[MxN];
int timer;
int tin[MxN], tout[MxN];
int euler_tour[MxN * 2];

int dfs(int node, int dep){
    euler_tour[timer] = node;
    tin[node] = timer++;
    S[node] = 1;
    a[node] = d[node] = dep;
    for(auto child:Children[node]){
        S[node] += dfs(child, dep + 1);
    }
    euler_tour[timer] = node;
    tout[node] = timer++;
    return S[node];
}
unordered_map <int, int> Dup[MxN];
bool SetComp(int i, int j){
    return (Dup[i].size() < Dup[j].size());
}
void dfs(int node){
    if(S[node] == 1){
        Dup[node].insert({A[node], node});
        return;
    }
    for(auto child:Children[node]){
        dfs(child);
    }
    sort(Children[node].begin(), Children[node].end(), SetComp);
    Dup[node].swap(Dup[Children[node][Children[node].size() - 1]]);
    for(auto child:Children[node]){
        for(auto j:Dup[child]){
            int X = Dup[node][j.first];
            int new_ins = j.second;
            if(X != 0){
                if(d[X] < d[j.second]){
                    a[j.second] = d[j.second] - d[node] - 1;
                    new_ins = X;
                }
                if(d[X] > d[j.second]){
                    a[X] = d[X] - d[node] - 1;
                }
                if(d[X] == d[j.second]){
                    if(X < j.second){
                        a[j.second] = d[j.second] - d[node] - 1;
                        new_ins = X;
                    }
                    else
                        a[X] = d[X] - d[node] - 1;
                }
            }
            Dup[node][j.first] = new_ins;
        }
    }

    int x = Dup[node][A[node]];
    int new_ins = node;
    if(x != 0)
        a[x] = d[x] - d[node] - 1;  
    Dup[node][A[node]] = new_ins;
}
void preprocess(){
    dfs(0, 0);
    dfs(0);
}


// https://codeforces.com/blog/entry/45428?#comment-304665 
// https://ideone.com/5xMHRD

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
        timer = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            Children[i].clear();
        }
        for(int i = 0; i <= n; i++)
            Dup[i].clear();
        P[0] = -1;
        bool we = 1;
        for(int i = 1; i < n; i++){
            cin >> P[i];
            P[i]--;
            if(P[i] != i - 1)
                we = 0;
            Children[P[i]].push_back(i);
        }

        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        if(we){
            rt = sz = 1;
            memset(lpos, 0, sizeof(lpos));
            memset(root, 0, sizeof(root));
            memset(L, 0, sizeof(L));
            memset(R, 0, sizeof(R));
            memset(sum, 0, sizeof(sum));

            for(int i = 0; i < n; i++){
                make_root();
                add(lpos[A[i]], -1);
                lpos[A[i]] = i + 1;
                add(i + 1, 1);
            }
            int q;
            cin >> q;
            int ans = 0, xq, dq;
            while(q--){
                cin >> xq >> dq;
                xq ^= ans;
                dq ^= ans;
                // xq to xq + dq
                // xq + dq <= n
                dq = min(dq, n - xq);
                cout << (ans = get(xq, xq + dq + 1, root[xq + dq])) << '\n';
            }
            continue;
        }
        preprocess();
        int q;
        cin >> q;
        int ans = 0, xq, dq;
        while(q--){
            cin >> xq >> dq;
            xq ^= ans;
            dq ^= ans;
            xq--;
            // cout << xq << ' ' << dq << '\n';
            ans = 0;
            for(int i = tin[xq]; i <= tout[xq]; i++){
                if(d[euler_tour[i]] - d[xq] <= min(dq, a[euler_tour[i]])){
                    ans++;
                }
            }
            ans /= 2;
            cout << ans << '\n';
        }
        // submitting to check time.
    }
}