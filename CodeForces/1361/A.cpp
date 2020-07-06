#include <bits/stdc++.h>
using namespace std;

#define int long long


vector <int> adj[500005];
pair <int, int> A[500005];

bool f(int i, int j){
    return A[i].first < A[j].first;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for(int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    bool we = 1;
    for(int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end(), f);
        bool x = 0;
        if(A[i].first == 1)
            x = 1;
        else{
            x = 1;
            int cur = 0;
            for(auto j:adj[i]){
                if(A[j].first > A[i].first)
                    break;
                if(A[j].first > cur){
                    if(cur != A[j].first - 1)
                        x = 0;
                    cur = A[j].first;
                }
            }
        }
        for(auto j:adj[i]){
            if(A[j].first == A[i].first){
                we = 0;
            }
        }
        we &= x;
    }
    if(!we){
        cout << "-1\n";
        return 0;
    }
    sort(A, A + n);
    for(int i = 0; i < n; i++){
        cout << A[i].second + 1 << ' ';
    }
    cout << '\n';
}