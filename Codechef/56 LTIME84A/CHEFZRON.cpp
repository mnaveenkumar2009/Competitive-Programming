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
        int n;
        cin >> n;
        int a[n], S = 0;
        vector<int> p;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            S += a[i];
            if(a[i]){
                p.push_back(i);
            }
        }
        if(p.size() == 0){
            cout << "0\n";
            continue;
        }
        if(S == 1){
            cout << "-1\n";
            continue;
        }
        if(S == 2){
            cout << p[1] - p[0] << "\n";
            continue;
        }
        int ans = p[1] - p[0];
        p.erase(p.begin());
        int prev = p[0];
        ans += p[p.size() - 1] - p[p.size() - 2];
        for(int i = 1; i < p.size() - 2; i++){
            if(p[i] - prev <= p[i + 1] - p[i]){
                ans += p[i] - prev;
                continue;
            }
            else{
                ans += p[i + 1] - p[i];
                prev = p[i + 1];
                i++;
            }
        }
        cout << ans << '\n';
    }
}