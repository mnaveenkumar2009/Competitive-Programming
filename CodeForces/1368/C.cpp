#include <bits/stdc++.h>
using namespace std;

#define int long long

void prin(int x, int y){
    cout << x << ' ' << y + 1 << '\n';
    cout << x << ' ' << y + 2 << '\n';
    cout << x + 1 << ' ' << y << '\n';
    cout << x + 1 << ' ' << y + 2 << '\n';
    cout << x + 2 << ' ' << y << '\n';
    cout << x + 2 << ' ' << y + 1 << '\n';
    cout << x + 2 << ' ' << y + 2 << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << 8 * (n + 1) - n << '\n';
    n++;
    int curx = 1, cury = 1;
    cout << curx << ' ' << cury << '\n';
    while(n--){
        prin(curx, cury);
        curx += 2;
        cury += 2;
    }
}