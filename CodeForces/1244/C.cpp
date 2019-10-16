#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    for(int y = 0; y < 1e6; y++){
        int x = p - y*d;
        if(x%w)continue;
        x/=w;
        if(x+y>n)continue;
        if(x<0)continue;
        cout << x << ' ' << y << ' ' << n -(x+y) << '\n';
        return 0;
    }
    cout << "-1\n";
    return 0;
}