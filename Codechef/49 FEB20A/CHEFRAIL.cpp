#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, ans = 0;
        cin >> n >> m;
        int X[n], Y[m];
        vector <bool> Mx(2e5 + 10, 0), My(2e5 + 10, 0);
        for(int i = 0; i < n; i++){
            cin >> X[i];
            Mx[X[i] + 1e5] = 1;
        }
        for(int i = 0; i < m; i++){
            cin >> Y[i];
            My[Y[i] + 1e5] = 1;
        }
        if(Mx[1e5])
            ans += (n - 1) * m;
        if(My[1e5])
            ans += n * (m - 1);
        for(int i = 0; i < m; i++){
            vector<bool> done(1e5+2, 0);
            int x = abs(Y[i]);
            vector <int> div;
            for(int j = 1; j * j <= x; j++){
                if(x % j == 0){
                    div.push_back(j);
                    if(j*j != x){
                        div.push_back(x/j);
                    }
                }
            }
            sort(div.begin(), div.end());
            int S = div.size();
            for(int j = 0; j < S; j++){
                for(int k = j; k < S; k++){
                    int cur = div[j] * div[k];
                    if(cur > x){
                        break;
                    }
                    if(done[cur])continue;
                    done[cur] = 1;
                    if((x*x)/cur <= 1e5){
                        if(Mx[(x*x)/cur + 1e5] && Mx[-cur + 1e5])
                            ans++;
                        if(Mx[-((x*x)/cur) + 1e5] && Mx[cur + 1e5] && cur != x)
                            ans++;
                    }
                }
            }
        }
        // cout << ans << '\n';
        for(int i = 0; i < n; i++){
            vector<bool> done(1e5+2, 0);
            int x = abs(X[i]);
            vector <int> div;
            for(int j = 1; j * j <= x; j++){
                if(x % j == 0){
                    div.push_back(j);
                    if(j*j != x){
                        div.push_back(x/j);
                    }
                }
            }
            sort(div.begin(), div.end());
            int S = div.size();
            for(int j = 0; j < S; j++){
                for(int k = j; k < S; k++){
                    int cur = div[j] * div[k];
                    if(cur > x){
                        break;
                    }
                    if(done[cur])continue;
                    done[cur] = 1;
                    // cout << i << ' ' << cur  << ' ' << x << '\n';
                    if((x*x)/cur <= 1e5){
                        if(My[(x*x)/cur + 1e5] && My[-cur + 1e5])
                            ans++;
                        if(My[-((x*x)/cur) + 1e5] && My[cur + 1e5] && cur != x)
                            ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}