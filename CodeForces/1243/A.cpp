#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, min(a[i], n-i));
        }
        cout << ans << '\n';
    }
}