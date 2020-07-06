#include <bits/stdc++.h>
using namespace std;
 
#define int long long

int F[1000005];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(F, 0, sizeof(F));
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int pref[n], a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i)
                a[i] += a[i-1];
        }
        int ans = 0;
        for(int i = 1; i < 1e6; i++){
            if(x % i == 0){
                int X = x/i;
                vector <int> b;
                for(int j = 0; j <= n - i; j++){
                    b.push_back(a[j + i - 1] - (j==0?0:a[j-1]));
                }
                if(b.size() == 0)
                    break;
                // cout << i << '\n';
                // for(auto j:b)cout << j << ' ';
                // cout << '\n';
                for(auto j:b){
                    if(j <= 1e6)
                        F[j]++;
                }
                for(auto j:b){
                    if(X-j >= 1){
                        ans += F[X-j];
                    }
                }
                for(auto j:b){
                    if(j <= 1e6)
                        F[j]--;
                }
            }
        }
        cout << ans << '\n';
    }
    
}