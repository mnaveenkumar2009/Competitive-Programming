#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x, k;
        cin >> x >> k;
        vector <int> P;
        int Y = x;
        for(int i = 2; i * i <= Y; i++){
            while(x % i == 0){
                P.push_back(i);
                x/=i;
            }
        }
        if(x != 1)
            P.push_back(0);
        if(P.size() >= k){
            cout << "1\n";
        }
        else
        cout << "0\n";
    }
}