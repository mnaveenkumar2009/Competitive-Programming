#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 2;

int n;
vector <pair <pair <int,int>, int> > tree[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i) {
        // tree[i] = tree[i<<1] + tree[i<<1|1];
        set <pair <int, int> > X;
        vector <pair <int, int> > Y;
        for(int fff = 0; fff < 2; fff++){
            for(auto j:tree[i<<1|fff]){
                auto it = X.lower_bound({j.first.first, -1e10});
                if(it != X.end()){
                    if((*it).first == j.first.first){
                        int XXX = (j.second + (*it).second);
                        X.erase(it);
                        X.insert({j.first.first, XXX});
                    }
                    else{
                        X.insert({j.first.first, j.second});
                    }
                }
                else{
                    X.insert({j.first.first, j.second});
                }
                it = X.lower_bound({j.first.second + 1, -1e10});
                if(it != X.end()){
                    if((*it).first == j.first.second + 1){
                        int XXX = (-j.second + (*it).second);
                        X.erase(it);
                        X.insert({j.first.second + 1, XXX});
                    }
                    else{
                        X.insert({j.first.second + 1, -j.second});
                    }
                }
                else{
                    X.insert({j.first.second + 1, -j.second});
                }
            }
        }

        for(auto j:X){
            Y.push_back(j);
        }
        int NN = Y.size();
        int cur = 0;
        for(int j = 0; j < NN - 1; j++){
            cur += Y[j].second;
            if(cur)
                tree[i].push_back({{Y[j].first, Y[j+1].first - 1}, cur});
        }
    }
}
int query(int l, int r, int x) {
    int res = 0;
    pair <pair <int,int>, int> SSS = {{x, x}, -1e9};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            if(tree[l].size() != 0){
                int pos = lower_bound(tree[l].begin(), tree[l].end(), SSS) - tree[l].begin();
                if(pos == tree[l].size()){
                    pos--;
                }
                if(pos >= 0){
                    if(tree[l][pos].first.first > x){
                        pos--;
                    }
                }
                if(pos >= 0){
                    if(tree[l][pos].first.second >= x && tree[l][pos].first.first <= x)
                        res += tree[l][pos].second;
                }
            }
            l++;
        }
        if (r&1){
            r--;
            if(tree[r].size() != 0){
                int pos = lower_bound(tree[r].begin(), tree[r].end(), SSS) - tree[r].begin();
                if(pos == tree[r].size()){
                    pos--;
                }
                if(pos >= 0){
                    if(tree[r][pos].first.first > x){
                        pos--;
                    }
                }
                if(pos >= 0){
                    if(tree[r][pos].first.second >= x && tree[r][pos].first.first <= x)
                        res += tree[r][pos].second;
                }
            }
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> n >> q;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i){
                int l = min(a[i], a[i-1]), r = max(a[i], a[i-1]);
                tree[n + i - 1].push_back({{l, r}, 1});
            }
        }
        build();
        // for(int i = 0; i < 2 * n; i++){
        //     cout << i << '\n';
        //     for(auto j:tree[i]){
        //         cout << j.first.first << ' ' << j.first.second << ' ' << j.second << ' ';
        //     }cout << '\n';
        // }
        while(q--){
            int x1, x2, y;
            cin >> x1 >> x2 >> y;
            cout << query(x1 - 1, x2 - 1, y) << '\n';
        }
    }
}