#include <bits/stdc++.h>
using namespace std;

#define int long long
int Place[20], n;

int f(vector <int> a){
    int x, y, ind = -1;
    vector <int> Y;
    for(int i = 0; i < n; i++){
        if(Place[a[i]] !=  Place[i]){
            x = Place[a[i]];
            ind = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(Place[a[i]] != Place[i] && (Place[i] == x)){
            Y.push_back(i);
        }
    }
    int ret = (ind != -1) * 1e9;
    for(auto i:Y){
        vector <int> a2 = a;
        swap(a2[ind], a2[i]);
        ret = min(ret, 1 + f(a2));
    }
    return ret;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        vector <int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
            Place[i] = i;
        }
        while(m--){
            int u, v;
            cin >> u >> v;
            u--;v--;
            int x = Place[u], y = Place[v];
            for(int i = 0; i < n; i++){
                if(Place[i] == x)
                    Place[i] = y;
            }
        }
        cout << f(p) << '\n';
    }
}