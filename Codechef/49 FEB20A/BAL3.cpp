#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string ans = "failure";
        int P[m], Q[m];
        for(int i = 0; i < m; i++)
            cin >> P[i] >> Q[i];
        if(n >= m * 2){
            for(int i = 0; i < m; i++)
                cout << '^';
            cout << '\n';
            continue;
        }
        for(int mask = 0; mask < (1<<(m - 1)); mask++){
            int K = 0;
            vector <int> Fn(n, 1);
            for(int i = 0; i < m; i++){
                if((mask >> i)&1){
                    Fn[P[i] - 1] += Fn[Q[i] - 1];
                    Fn[Q[i] - 1] = 0;
                }
                else{
                    Fn[Q[i] - 1] += Fn[P[i] - 1];
                    Fn[P[i] - 1] = 0;
                }
            }
            for(int i = 0; i < n; i++)
                K += (Fn[i] > 0);
            if(K >= (n + 1)/2){
                ans = "";
                for(int i = 0; i < m; i++){
                    if((mask >> i)&1){
                        ans.push_back('^');
                    }
                    else
                        ans.push_back('v');
                }
                cout << ans << '\n';
                // break;
            }
        }
        assert(ans != "failure");
        // cout << ans << '\n';
    }
}