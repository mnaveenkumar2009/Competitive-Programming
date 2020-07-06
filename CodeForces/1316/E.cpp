#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    pair <int, int> a[n];
    int s[n][7];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    int audi = 0;
    for(int i = 0; i < k; i++){
        audi += a[i].first;
    }

    for(int mask = 0; mask < (1 << p); i++){
        
        for(int i = 0; i < p; i++){

        }
    }
}