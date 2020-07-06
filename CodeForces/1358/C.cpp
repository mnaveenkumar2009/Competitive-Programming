#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int numberOfPaths(int m, int n) {
    // return min(n, m);
    if(m > 2)m = 2;
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, w, z;
        cin >> w >> x >> y >> z;
        cout << numberOfPaths(y - w + 1, z - x + 1) << '\n';
    }
}