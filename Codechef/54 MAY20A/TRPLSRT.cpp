#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int p[n];
        set <int> S;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i] != i + 1)
            S.insert(i + 1);
        }
        stack <int> DUO;
        vector <int> ans;
        while(S.size()){
            int k = *S.begin();
            int i = p[k-1];
            int j = p[i-1];
            // cout << i << ' ' << j << ' ' << k << '\n';
            if(k == j){
                S.erase(k);
                S.erase(i);
                DUO.push(i);
                DUO.push(k);
            }
            else{
                S.erase(i);
                S.erase(j);
                p[k-1] = p[j-1];
                if(p[k-1] == k){
                    S.erase(k);
                }
                ans.push_back(i);
                ans.push_back(j);
                ans.push_back(k);
            }
        }
        if((DUO.size() / 2) & 1){
            cout << "-1\n";
            continue;
        }
        while(DUO.size()){
            int i = DUO.top();
            DUO.pop();
            int j = DUO.top();
            DUO.pop();
            int k = DUO.top();
            DUO.pop();
            int l = DUO.top();
            DUO.pop();
            ans.push_back(i);
            ans.push_back(j);
            ans.push_back(k);
            ans.push_back(k);
            ans.push_back(i);
            ans.push_back(l);
        }
        int K = ans.size() / 3;
        cout << K << '\n';
        for(int i = 0; i < K; i++){
            cout << ans[3*i] << ' ' << ans[3*i + 1] << ' ' << ans[3*i + 2] << '\n';
        }
    }
}