#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int n;
    cin >> n;
    while(n--){
        int l, r, j, ans =0;
        cin >> l >> r;
        for(j = 63; j >0; j--)
            if((l&(1LL<<j)) != (r&(1LL<<j)))
                break;
        r|=((1LL << j)-1);
        cout << r << '\n';
    }
}