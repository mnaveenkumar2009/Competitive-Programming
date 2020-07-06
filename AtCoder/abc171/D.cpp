#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, sum = 0, y;
    cin >> n;
    int a[100003];
    memset(a, 0, sizeof(a));
    while(n--){
    	cin >> x;
    	sum += x;
    	a[x]++;
    }
    cin >> q;
    while(q--){
    	cin >> x >> y;
    	sum += a[x] * (y - x);
    	a[y] += a[x];
    	a[x] = 0;
    	cout << sum << '\n';
    }
}