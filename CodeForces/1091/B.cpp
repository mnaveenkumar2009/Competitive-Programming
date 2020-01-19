#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int X = 0, Y = 0, A = 0, B = 0;
    for(int i = 0; i < 2*n; i++){
    	int x, y;
    	cin >> x >> y;
    	X += x;
    	Y += y;
    }
    cout << X/n << ' ' << Y/n << '\n';
}