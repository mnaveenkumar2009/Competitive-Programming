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
        int n, m;
        cin >> n >> m;
        vector <pair <int, pair <int, int> > > A(n);
        for(int i = 0; i < n; i++){
            cin >> A[i].first >> A[i].second.first >> A[i].second.second;
        }
        sort(A.begin(), A.end());
        string ans = "YES";
        int l[n], r[n];
        for(int i = 0; i < n; i++){
            l[i] = -1e10;
            r[i] = 1e10;
        }
        for(int i = 0; i < n; i++){
            if(m < A[i].second.first - A[i].first || m > A[i].second.second + A[i].first){
                // cout << i << '\n';
                ans = "NO";
            }
            for(int j = 0; j < i; j++){
                l[j] = max(A[i].second.first - (A[i].first - A[j].first), l[j]);
                r[j] = min(A[i].second.second + (A[i].first - A[j].first), r[j]);
            }
        }
        for(int i = 0; i < n; i++)
            if(l[i] > r[i]){
                // cout << i << '\n';
                ans = "NO";
            }
        for(int i = 0; i < n; i++){
            if(l[i] > A[i].second.second || r[i] < A[i].second.first)
                ans = "NO";
        }
        cout << ans << '\n';
    }
}