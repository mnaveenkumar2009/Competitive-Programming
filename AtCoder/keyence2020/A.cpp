#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, w, h;
    cin >> h >> w >> n;
    if(h < w)
    	swap(h, w);
    cout << n/h + ((n % h) > 0) << '\n';
}