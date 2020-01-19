#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int y, b, r;
    cin >> y >> b >> r;
   	cout << max(min(y * 3 + 3, min(b*3, r *3  - 3)), 0LL) << '\n';
}