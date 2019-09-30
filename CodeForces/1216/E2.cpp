#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll num(ll n, bool c){
    ll ret = 0, cp = 1;
    while(n - cp + 1 >= 0){
        if(c)
            ret += ((n - cp + 1)*(n - cp + 2))/2;
        else
            ret += (n - cp + 1);
        if(ret > 1e18)
            return ret;
        cp*=10;
    }
    return ret;
}
int main(){
    
    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        k--;
        int c = 2;
        char a[100];
        while(c--){
            ll low = 0, high = 1e9;
            while(low != high){
                ll mid = (low+high)/2;
                if(mid == low) mid++;
                if(num(mid, c) > k){
                    high = mid - 1;
                }
                else{
                    low = mid;
                }
            }
            k -= num(low, c);
            sprintf(a,"%d", (int)low + 1);
        }
        cout<<a[k]<<'\n';
    }
}