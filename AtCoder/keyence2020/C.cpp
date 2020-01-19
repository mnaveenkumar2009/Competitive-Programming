#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, s;
    cin >> n >> k >> s;
    for(int i = 0; i < k; i++){
    	cout << s << ' ';
    }
    for(int i = k; i < n; i++){
    	cout << (int)((s == 1e9) ? (1e9 - 1): 1e9) << ' ';
    }
    cout << '\n';
}