#include <bits/stdc++.h>
using namespace std;
#define int long long

int X = (1LL<<32) - 1;
signed main(){
    int t;
    cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(t--){
        map <int, vector <int> >pos;
        int n;
        cin >> n;
        vector <int> a(n);
        vector <bool> used(n, 0);
        vector <int> ans;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]].push_back(i + 1);
        }
        X = (1LL<<32) - 1;
        while(X){
            int F = 0;
            for(int i = 0; i < n; i++){
                if(!used[i]){
                    F = i;
                    break;
                }
            }
            if(used[0] && F==0){
                break;
            }
            for(int i = 0; i < n; i++){
                if(!used[i])
                    if((a[F]&X) < (a[i]&X))
                        F = i;
            }
            if(!(a[F] & X))
                break;
            used[F] = 1;
            F = a[F];
            ans.push_back(F);
            while(X > F)
                X /= 2;
            X *= 2;
            X++;
            for(int j = (X+1)/2; j >= 1; j/=2)
                if(F & j)
                    X ^= j;
                else
                    break;
        }
        for(int i = 0; i < n; i++){
            if(!used[i])
                ans.push_back(a[i]);
        }
        int Ans = 0;
        for(int i = 0; i < n; i++){
            int G = 0;
            for(int j = 0; j <= min(32LL, n - i - 1); j++){
                G |= ans[j];
            }
            Ans += G;
        }
        cout << Ans << '\n';
        for(int i = 0; i < n; i++){
            cout << pos[ans[n - i - 1]][pos[ans[n - i - 1]].size() - 1] << ' ';
            pos[ans[n - i - 1]].pop_back();
        }
        cout << '\n';
    }
}