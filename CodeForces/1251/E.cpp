#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> p(n), m(n);
        multiset <pair <int, int> > S;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> m[i] >> p[i];
            S.insert({m[i], p[i]});
        }
        int k = 0;
        while(S.size()){
            auto it = S.begin();
            while(it->first <= k){
                S.erase(S.begin());
                k++;
                if(!S.size())break;
                it = S.begin();
            }
            if(!S.size())break;
            int kk = k;
            auto X = *S.begin();
            for(auto i: S){
                if(i.first != kk + 1 && i.first != kk){
                    X = i;
                    break;
                }
                else{
                    if(i.first == kk+1)
                        kk++;
                }
            }
            if(S.lower_bound({kk, 1e14})==S.end()){
                it = S.end();
                it--;
                X = *it;
                while(it -> first == X.first){
                    it--;
                    if(it == S.begin())break;
                }
                if(it -> first != X.first)
                    it++;
            }
            else
                it = S.lower_bound(X);
            while(it!=S.end()){
                if(X.second > it->second){
                    X = *it;
                }
                it++;
            }
            ans += X.second;
            S.erase(S.find(X));
            k++;
        }
        cout << ans << '\n';
    }
}