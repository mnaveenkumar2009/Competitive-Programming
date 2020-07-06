#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        pair <int, int> a[n];
        vector <pair <pair <int, int>, int> > B;
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
            B.push_back({{a[i].second - a[i].first, ((a[i].first % c) + c) % c}, a[i].first});
        }
        sort(B.begin(),B.end());
        int ans = 1, cur = 0;
        int ans2 = 0;
        for(int i = 1; i < n; i++){
            if(B[i].first != B[i-1].first){
                for(int j = cur; j < i; j++){
                    ans2 += abs(B[j].second - B[cur + (i - cur - 1)/2].second)/c;
                }
                cur = i;
                ans++;
            }
        }
        for(int j = cur; j < n; j++){
            ans2 += abs(B[j].second - B[cur + (n - cur - 1)/2].second)/c;
        }
        cout << ans << ' ' << ans2 << '\n';
    }
}