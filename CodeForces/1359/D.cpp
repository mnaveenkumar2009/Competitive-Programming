#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100004];

// int f(int l, int r){
//     if(l > r){
//         return -1e9;
//     }
//     cout << l << ' ' << r << '\n';

//     int max_so_far = -1e9, max_ending_here = 0, startt =l, endd = l, ss=l; 
  
//     for (int i = l; i <= r; i++) {
//         max_ending_here += a[i];
  
//         if (max_so_far < max_ending_here) 
//         { 
//             max_so_far = max_ending_here; 
//             startt = ss; 
//             endd = i; 
//         }       
//         if (max_ending_here < 0) 
//         { 
//             max_ending_here = 0; 
//             ss = i + 1; 
//         } 
//     }     
//     int maxi = -1e9;
//     for(int i = startt; i < endd; i++){
//         maxi = max(maxi, a[i]);
//     }
//     int minind = n, maxind = 0;
//     for(int i = startt; i < endd; i++){
//         if(a[i] == maxi){
//             minind = min(minind, i);
//             maxind = max(maxind, i);
//         }
//     }
//     cout << l << ' ' << minind << ' ' << maxind << ' ' <<r << '\n';
//     // return max(max_so_far, max(f(l, minind - 1), f(maxind + 1, r)));
// }
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // cout << f(0, n - 1) << '\n';
    int dp[n][61];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 61; j++){
            dp[i][j] = -1e9;
        }
    }

    for(int i = 0; i < n; i++){
        dp[i][a[i] + 30] = a[i];
        if(i){
            for(int j = 0; j < 61; j++){
                if(dp[i-1][j] >= 0)
                    dp[i][max(j, a[i] + 30)] = max(dp[i-1][j] + a[i], dp[i][max(j, a[i] + 30)]);
            }
        }
    }
    int ans = -1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 61; j++){
            ans = max(ans, dp[i][j] - (j - 30));
        }
    }
    cout << ans << '\n';
}