#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector <int> c(20, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 20; j++){
            if(a[i] & (1LL<<j)){
                c[j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = 19; j >= 0; j--){
            if(c[j]){
                c[j]--;
                x |= (1<<j);
            }
        }
        ans += x * x;
    }
    cout << ans;
}