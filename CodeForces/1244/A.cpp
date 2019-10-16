#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        long double a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans = ceil(b/d) + ceil(a/c);
        if(ans <= k){
            cout << ceil(a/c) << ' ' << ceil(b/d) << '\n';
        }
        else{
            cout << "-1\n";
        }

    }
}