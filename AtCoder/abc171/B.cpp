#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << accumulate(a, a + k, 0) << '\n';
}