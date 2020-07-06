#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q, l, r, x;
        cin >> n >> q;
        set <int> S;
        for(int i = 0; i < n; i++)
            S.insert(i);
        vector <pair <int, int> > A;
        while(q--){
            cin >> l >> r >> x;
            if(x == 1)
                A.push_back({r - 1, l - 1});
            else{
                auto l_pos = S.lower_bound(l-1), r_pos = S.upper_bound(r-1);
                S.erase(l_pos, r_pos);
            }
        }
        sort(A.begin(), A.end());
        vector <int> ans(n, 0);
        int done_r = -1;
        for(auto P:A){
            if(P.second > done_r){
                auto i = S.upper_bound(P.first);
                i--;
                ans[(*i)] = 1;
                done_r = *i;
            }
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}