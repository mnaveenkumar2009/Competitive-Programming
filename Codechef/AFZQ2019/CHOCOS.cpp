#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, k, x;
    cin >> n >> k >> x;
    int c[2] = {0, 0};
    string s;
    cin >> s;
    for(int i= 0; i < n;i++){
        c[s[i] - '0']++;
    }
    if(x==1){
        c[0] = (c[0] % k);
        c[0] = min(c[0], k- c[0]);
        c[1] = n - c[0];
        if(k!=n){
            if(k&1){
                c[0] = 0;
            }
            else{
                c[0] = c[0]%2;
            }
        }
        cout << n - c[0] << '\n';
    }
    else{
        cout << c[1] << '\n';
    }
}