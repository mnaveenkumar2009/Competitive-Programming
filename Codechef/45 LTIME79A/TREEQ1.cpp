#include <bits/stdc++.h>
using namespace std;
#define int long long

int mark[N];//mark edges
vector<int> order;//order of tour
vector<pair<int,int> > v[N];//(neighbour, edgeID)
int nxt[N];//next uncheked edge
void euler(int cur){
    for(;nxt[cur]<v[cur].size();++nxt[cur])
        if(!mark[v[cur][nxt[cur]].S]){
            mark[v[cur][nxt[cur]].S]=1;
            euler(v[cur][nxt[cur]].F);
        }
    order.PB(cur);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
    	cin >> w[i];
    }
    for(int i = 0; i < n - 1; i++){
    	int u, V;
    	v[u - 1] = {V - 1, i};
    	v[V - 1] = {u - 1, i};
    }
    euler(0);
    while(q--){
    	int t, v, x;
    	cin >> t >> v >> x;
    	
    }
}