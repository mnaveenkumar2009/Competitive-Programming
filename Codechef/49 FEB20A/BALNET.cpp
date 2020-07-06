#include <bits/stdc++.h>
using namespace std;
// 2 sat template : https://cp-algorithms.com/graph/2SAT.html

int n, m, cl;
vector<int> g[2000006], gt[2000006];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int &u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    for (int &u : gt[v^1]) {
        if (!used[u^1])
            dfs1(u^1);
    }
    order.push_back(v);
}

void dfs2(int v) {
    comp[v] = cl;
    for (int &u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u);
    }
    for (int &u : g[v^1]) {
        if (comp[u^1] == -1)
            dfs2(u^1);
    }
}

bool solve_2SAT() {
    n = m * 2;
    used.clear();
    comp.clear();
    assignment.clear();
    order.clear();
    used.resize(n);
    comp.resize(n);
    assignment.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    cl = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1){
            dfs2(v);
            cl++;
        }
    }

    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void Add(int u, int v){

    if(find(g[v].begin(), g[v].end(), u^1) != g[v].end())
        return;
    if(find(g[u^1].begin(), g[u^1].end(), v) != g[u^1].end())
        return;
    g[u].push_back(v);
    gt[v].push_back(u);
}
void Rem(int u, int v){
    g[u].pop_back();
    gt[v].pop_back();
    g[v^1].pop_back();
    gt[u^1].pop_back();
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> m;
        for(int i = 0; i < 2*m; i++){
            g[i].clear();
            gt[i].clear();
        }
        vector <int> A(n, -1);
        int P[m], Q[m];
        Add(0, 2 * m - 2);
        Add(1, 2 * m - 2);

        for(int i = 0; i < m; i++){
            int X, Y, u = -1, v = -1;
            cin >> X >> Y;
            int B = A[X-1], C = A[Y-1];
            if(B != -1 && C != -1){
                if(P[C] == Y)
                    v = 2*C + 1;
                else
                    v = 2*C;
                if(P[B] == X)
                    u = 2*B;
                else
                    u = 2*B + 1;
            }
            else{
                u = 2*m - 2;
                if(C != -1){
                    if(P[C] == Y)
                        v = 2*C + 1;
                    else
                        v = 2*C;
                }
                if(B != -1){
                    if(P[B] == X)
                        v = 2*B + 1;
                    else
                        v = 2*B;
                }
            }
            if(u != -1 && v != -1){
                Add(u, v);
                // if(!solve_2SAT())
                //     Rem(u, v);
            }
            P[i] = X;
            Q[i] = Y;
            A[X - 1] = i;
            A[Y - 1] = i;
        }
        (solve_2SAT());
        string ans(m, 'v');
        for(int i = 0; i < m; i++){
            if(assignment[i])
                ans[i] = ('^');
            // else
            //     cout << ('v');
        }
        cout << ans << '\n';
    }
}