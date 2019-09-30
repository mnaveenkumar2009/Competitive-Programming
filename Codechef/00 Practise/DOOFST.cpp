#include <bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int n, m, u, v, tot;
    cin >> n >> m;
    vector <int> G[n], col(n, 0), siz(n, 0);
    while(cin >> u >> v)
        u < v? G[u-1].push_back(v-1) : G[v-1].push_back(u-1);
    u = tot = 0;
    for(int i = 0; i < n; siz[col[i]]++, i++)
        if(col[i] == tot){
            for(auto A : G[i])
                col[A] == tot ? col[A]++ : 1;
            tot++;
        }
    for(int sizz : siz)
        u += (sizz * (sizz - 1)) / 2;
    int ans = ceil(log2(tot));
    if( u != ((n * (n - 1)) / 2 - m) || ans * n > 1e6)
        ans = -1;
    cout << ans << '\n';
    for (int i = 0; i < ans; cout << '\n', i++)
        for (int j = 0; j < n; j++)
            cout << (col[j]>>i) % 2;
}