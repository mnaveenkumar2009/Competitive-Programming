#include <bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, p, aa = 1e9, bb = 1e9;
    cin >> n >> m >> p;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%p != 0){
            aa = min(aa, i);
        }
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        if(b[i]%p != 0){
            bb = min(bb, i);
        }
    }
    cout << aa + bb << '\n';
}