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
        int n, x;
        cin >> n >> x;
        int a[n];
        int ans = 0;    
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        if(lower_bound(a, a+n, x) == a + n){
            int X = a[n-1];
            int H = ceil((double)x/(double)X);
            cout << H << '\n';
        }
        else{
            int X = *lower_bound(a, a+n, x);
            if(x == X){
                cout <<"1\n";
            }
            else{
                cout << "2\n";
            }
        }
    }
}