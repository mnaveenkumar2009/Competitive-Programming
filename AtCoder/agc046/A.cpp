#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    // 360/x
    int y = 1;
    while((y * 360) % x){
        y++;
    }
    cout << (y*360)/x << '\n';
}