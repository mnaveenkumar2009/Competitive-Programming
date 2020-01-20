#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, q, k, m;
    cin >> n >> q >> k >> m;
    int k2 = k % m-1;
    vector <int> E(100, 0), Q(1e6, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        E[x]++;
    }
    for(int t = 0; t < 1e6; t++){
        vector <int> newE(100, 0);
        if(Q[t]!=-1)
            newE[Q[t]]++;
        for(int i = 0; i < 100; i++){
            // x^y % m = x^ (y%(m-1)) %m
            pr(i, )
        }
    }
}