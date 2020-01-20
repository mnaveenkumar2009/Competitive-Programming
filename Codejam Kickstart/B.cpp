#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int TC = 1; TC <= t; TC++){
        long long n, m, ans = -1, k = 0;
        cin >> n >> m;
        long long a[n];
        int ones[63];
        memset(ones, 0, sizeof(ones));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int bit = 62; bit >= 0; bit--){
                ones[bit] += (a[i]>>bit)&1;
            }
        }
        for(int bit = 62; bit >= 0; bit--){
            if(ones[bit] >= n - ones[bit])
                k |= (1LL << bit);
        }
        int cur_sum = 0;
        for(int i = 0; i < n; i++)
            cur_sum += a[i] ^ k;
        if(cur_sum <= m){
            for(int bit = 60; bit >= 0; bit--){
                if(ones[bit] < n - ones[bit]){
                    long long num = 1LL << bit;
                    if(num * (n - 2*ones[bit]) < num)
                        continue;
                    if(num * (n - 2*ones[bit]) <= m - cur_sum){
                        k |= (1LL << bit);
                        cur_sum += num * (n - 2*ones[bit]);
                    }
                }
            }
            ans = k;
        }
        cout << "Case #" << TC << ": " << ans << '\n';
    }
}