#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n], c[k];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0 ;i < k; i++){
            cin >> c[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        set <pair <int, int> > X;
        vector <vector <int> > ans;
        for(int i = 0; i < n; i++){
            int x = a[i] - 1;
            auto it = X.lower_bound({c[x] - 1, 1e9});
            if(it == X.begin()){
                vector <int> A(1, a[i]);
                X.insert({1, (int)ans.size()});
                ans.push_back(A);
            }
            else{
                it--;
                int ind = it->second;
                ans[ind].push_back(a[i]);
                X.erase(it);
                X.insert({(int)ans[ind].size(), ind});
            }
        }
        cout << ans.size() << '\n';
        for(auto i:ans){
            cout << i.size() << ' ';
            for(auto j:i){
                cout << j << ' ';
            }cout << '\n';
        }
    }
}