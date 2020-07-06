#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        pair <int, int> Q[q];
        int ans[q];
        for(int i = 0; i < q; i++){
            cin >> Q[i].first >> Q[i].second;
        }
        if(k >= 10){
            for(int i = 0; i < q; i++){
                cout << "1 " << Q[i].first << ' ' << Q[i].second << ' ' << m/2 << endl;
                cin >> ans[i];
            }
            cout << "2 ";
            for(int i = 0; i < q; i++)
                cout << ans[i] << ' ';
            cout << endl;
            cin >> n;
        }
        else{
            cout << "2 ";
            for(int i = 0; i < q; i++)
                cout << m - 1 << ' ';
            cout << endl;
            cin >> n;
        }
    }
}