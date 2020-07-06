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
        int m = 0, k = 0;
        int n;
        cin >> n;
        int a[n];
        vector<int> b;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] != -1){
                if(i){
                    if(a[i-1] == -1){
                        b.push_back(a[i]);
                    }
                    else{
                        m = max(m, abs(a[i] - a[i-1]));
                    }
                }
            }
            else{
                if(i){
                    if(a[i-1] != -1){
                        b.push_back(a[i-1]);
                    }
                }
            }
        }
        if((int)b.size()){
            sort(b.begin(), b.end());
            int x = (b.size());
            k = (b[0] + b[x-1]) / 2;
            m = max(m, max(abs(k - b[0]), abs(b[x-1] - k)));
            cout << m << ' ' << k << '\n';
        }
        else
            cout << m << ' ' << 0 << '\n';
    }
}