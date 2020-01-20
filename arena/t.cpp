#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int x){
    if(x == 0){
        return 0;
    }
    if(x&1){
        return (x * (x - 1))/2;
    }
    int ret = 0;
    while(x % 2 == 0){
        x/=2;
        ret += x;
    }
    return ret + (x * (x - 1))/2;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int y;
    cin >> y;
    bool we = 0;
    set <int> ans;
    for(int i = 1; i < 32; i++){
        int b = (1LL << i) - 1;
        // cout << b*b + 8 * y << '\n';
        int n = (-b + sqrtl(b*b + 8 * y))/2;
        if(n < 0)continue;  
        n *= (1LL << i);
        if(f(n) == y){
            ans.insert(n);
        }
    }
    int n = 1 + sqrtl(1 + 8 * y);
    if(f(n/2) == y){
        ans.insert(n/2);
        we = 1;
    }
    if(ans.size() == 0){
        cout << "-1";
    }
    else
        for(auto i:ans)cout << i << ' ';
}