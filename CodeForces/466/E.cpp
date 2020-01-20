#include <bits/stdc++.h>
using namespace std;
#define N 100006
int bj[N][30], lev[N];
int dsupar[N], siz[N], par[N], root[N];

int level(int node){
    if(par[node] == -1)
        return lev[node] = 0;
    if(lev[node] != -1)
        return lev[node];
    return lev[node] = level(par[node]) + 1;
}

bool lca(int u, int v){
    if(lev[v] < lev[u])
        return 0;
    for (int i = 25; i >= 0; i--)
        if ((lev[v] - (1LL << i)) >= lev[u])
            v = bj[v][i];
    return (u == v);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        dsupar[i] = root[i] = i;
        siz[i] = 1;
        par[i] = lev[i] = -1;
    }

    vector <int> D, Q;
    while(m--){
        int t, x, y;
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            par[--x] = --y;
            while(x != dsupar[x])
                x = dsupar[x];
            while(y != dsupar[y])
                y = dsupar[y];
            root[x] = root[y];
            if(siz[x] < siz[y])
                swap(x,y);
            dsupar[y] = x;
            siz[x] = siz[x] + siz[y];
        }
        if(t == 2){
            cin >> x;
            D.push_back(--x);
            while(x != dsupar[x])
                x = dsupar[x];
            D.push_back(root[x]);
        }
        if(t == 3){
            cin >> x >> y;
            Q.push_back(x-1);
            Q.push_back(D[2*y-2]);
            Q.push_back(D[2*y-1]);
        }
    }

    for(int i = 0; i < n; i++)
        bj[i][0] = par[i];
    for(int j = 1; j < 30; j++)
        for(int i = 0; i < n; i++){
            bj[i][j] = -1;
            if(bj[i][j-1] != -1)
                bj[i][j] = bj[bj[i][j-1]][j-1];
        }
    
    for(int i = 0; i < n; i++)
        level(i);

    for(int i = 0; i < Q.size()/3; i++)
        if(lca(Q[3*i], Q[3 * i + 1]) && lca(Q[3 * i + 2], Q[3*i]))
            cout<<"YES\n";
        else
            cout<<"NO\n";
}