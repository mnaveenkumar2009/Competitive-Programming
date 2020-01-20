#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[3];
        int ans = 0;
        for(int i = 0; i < 3; i++){
            cin >> a[i];
        }
        int y = a[2]/2;
        y = min(y, a[1]);
        a[1] -= y;
        ans += 3*y;
        int x = a[1]/2;
        x = min(x, a[0]);
        ans += 3*x;
        cout << ans << '\n';
    }
}