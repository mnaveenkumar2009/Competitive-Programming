#include <bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int n, m, u, v, tot;
    cin >> n >> m;
    vector <int> G[n], col(n, 0), siz(n, 0), adj(n, 0);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u-1]++;adj[v-1]++;
        u < v? G[u-1].push_back(v-1) : G[v-1].push_back(u-1);
    }
    u = tot = 0;
    for(int i = 0; i < n; siz[col[i]]++, i++)
        if(col[i] == tot){
            for(auto A : G[i])
                col[A] == tot ? col[A]++ : 1;
            tot++;
        }
    for(int sizz : siz)
        u += (sizz * (sizz - 1)) / 2;
    for(int i = 0; i < n; i++){
        for(auto A : G[i])
            if(col[A] == col[i])
                tot = -1;
    }
    if(u != ((n * (n - 1)) / 2 - m) || tot != 3)
        cout << "-1\n";
    else
        for (int i = 0; i < n; i++)
            cout << (col[i] + 1) <<' ';
}