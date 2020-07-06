#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

ld dist(ld x1, ld y1, ld x2, ld y2){
    ld x = x1 - x2;
    ld y = y1 - y2;
    return sqrtl(x * x + y * y);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        ld w, h;
        cin >> n >> m >> w >> h;
        ld x[m], y[m];
        string s;
        cin >> s;
        for(int i = 0; i < m; i++){
            cin >> x[i] >> y[i];
        }
        int U = 0, D = 0, R = 0, L = 0;
        for(int i = 0; i < n; i++){
            // for(int j= 0 ; j < m ;j++){
            //     cout << x[j] << ' ' << y[j ] << '\n';
            // }
            if(s[i] == 'U'){
                U++;
                // h /= 2.0;
                // for(int j = 0; j < m; j++){
                //     if(y[j] > h){
                //         y[j] = 2 * h - y[j];
                //     }
                // }
            }
            if(s[i] == 'D'){
                D++;
                // h /= 2.0;
                // for(int j = 0; j < m; j++){
                //     if(y[j] < h){
                //         y[j] = 2 * h - y[j];
                //     }
                // }
                // for(int j = 0; j < m; j++){
                //     y[j] -= h;
                // }
            }
            if(s[i] == 'R'){
                // w /= 2.0;
                // for(int j = 0; j < m; j++){
                //     if(x[j] > w){
                //         x[j] = 2 * w - x[j];
                //     }
                // }
                R++;
            }
            if(s[i] == 'L'){
                L++;
                // w /= 2.0;
                // for(int j = 0; j < m; j++){
                //     if(x[j] < w){
                //         x[j] = 2 * w - x[j];
                //     }
                // }
                // for(int j = 0; j < m; j++){
                //     x[j] -= w;
                // }
            }
        }
        ld ans = 1e14;
        for(int i = 0; i < m; i++){
            // cout <<x[i] << ' ' << y[i] << '\n';
            for(int j = i + 1; j < m; j++){
                ans = min(dist(x[i], y[i], x[j], y[j]), ans);
            }
        }
        if( U || D >= 2){
            for(int i = 0; i < m; i++){
                ld X = x[i];
                ld Y = y[i] + (h - y[i]) * 2;
                ans = min(dist(x[i], y[i], X, Y), ans);
            }   
        }
        if( D || U >= 2){
            for(int i = 0; i < m; i++){
                ans = min(2 * y[i], ans);
            }   
        }
        if(L || R >= 2){
            for(int i = 0; i < m; i++){
                ans = min(2 * x[i], ans);
            }   
        }
        if(R||L >=2){
            for(int i = 0; i < m; i++){
                ld Y = y[i];
                ld X = x[i] + (w - x[i]) * 2;
                ans = min(dist(x[i], y[i], X, Y), ans);
            }   
        }
        cout << fixed << setprecision(9) << ans << '\n';
    }
}