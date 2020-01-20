#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        long long ans = 0;
        vector <int> col(n + 1, 0);
        vector <pair <int, pair <int, int> > > edges(n - 1);
        for(int i = 0; i < n - 1; i++){
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());
        for(auto edge: edges){
            int u = edge.second.first, v = edge.second.second;
            if(col[u] < k && col[v] < k){
                col[u]++;
                col[v]++;
                ans += edge.first;
            }
        }
        cout << ans << '\n';
    }
}