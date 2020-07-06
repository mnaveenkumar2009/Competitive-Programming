#include <bits/stdc++.h>
using namespace std;

signed main(){
    srand(time(0));
    int n, f;
    cin >> n >> f;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector <int> D(n, 0), U(n, 0), L(n, 0), R(n, 0);
    for(int i = 0; i < n; i++){
        L[i] = 0;
        for(int j = 0; j < n; j++){
            if(L[i] + a[i][j] > f)break;
            L[i] += a[i][j];
        }
        R[i] = 0;
        for(int j = n-1; j >= 0; j--){
            if(R[i] + a[i][j] > f)break;
            R[i] += a[i][j];
        }
    }
    for(int j = 0; j < n; j++){
        U[j] = 0;
        for(int i = 0; i < n; i++){
            if(U[j] + a[i][j] > f)break;
            U[j] += a[i][j];
        }
        D[j] = 0;
        for(int i = n-1; i >= 0; i--){
            if(D[j] + a[i][j] > f)break;
            D[j] += a[i][j];
        }
    }
    vector <pair <char, int> > ANS;
    while(*max_element(D.begin(), D.end())){
        int x = *max_element(D.begin(), D.end());
        x = max(*max_element(U.begin(), U.end()), x);
        x = max(*max_element(L.begin(), L.end()), x);
        x = max(*max_element(R.begin(), R.end()), x);
        vector <pair <char, int> > XX;
        for(int i = 0; i < n; i++){
            if(D[i] == x){
                XX.push_back({'D', i});
            }
            if(L[i] == x){
                XX.push_back({'L', i});
            }
            if(R[i] == x){
                XX.push_back({'R', i});
            }
            if(U[i] == x){
                XX.push_back({'U', i});
            }
        }
        // cout << x << '\n';
        // for(auto i:XX){
        //     cout << i.first << ' ' << i.second << '\n';
        // }
        pair <char, int> ans =  XX[rand() % (int)(XX.size())];
        ANS.push_back(ans);
        // cout << ans.first << ' ' << ans.second << '\n';
        // break;
        int ind = ans.second;
        vector <bool> AffR(n, 0), AffC(n, 0);
        if(ans.first == 'D'){
            AffC[ind] = 1;
            int cur = 0;
            for(int i = n-1; i >= 0; i--){
                if(cur + a[i][ind] > f)break;
                cur += a[i][ind];
                if(a[i][ind]){
                    AffR[i] = 1;
                }
                a[i][ind] = 0;
            }
        }
        if(ans.first == 'U'){
            AffC[ind] = 1;
            int cur = 0;
            for(int i = 0; i < n; i++){
                if(cur + a[i][ind] > f)break;
                cur += a[i][ind];
                if(a[i][ind]){
                    AffR[i] = 1;
                }
                a[i][ind] = 0;
            }
        }
        if(ans.first == 'L'){
            AffR[ind] = 1;
            int cur = 0;
            for(int j = 0; j < n; j++){
                if(cur + a[ind][j] > f)break;
                cur += a[ind][j];
                if(a[ind][j]){
                    AffC[j] = 1;
                }
                a[ind][j] = 0;
            }
        } 
        if(ans.first == 'R'){
            AffR[ind] = 1;
            int cur = 0;
            for(int j = n-1; j >= 0; j--){
                if(cur + a[ind][j] > f)break;
                cur += a[ind][j];
                if(a[ind][j]){
                    AffC[j] = 1;
                }
                a[ind][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!AffR[i])continue;
            L[i] = 0;
            for(int j = 0; j < n; j++){
                if(L[i] + a[i][j] > f)break;
                L[i] += a[i][j];
            }
            R[i] = 0;
            for(int j = n-1; j >= 0; j--){
                if(R[i] + a[i][j] > f)break;
                R[i] += a[i][j];
            }
        }
        for(int j = 0; j < n; j++){
            if(!AffC[j])continue;
            U[j] = 0;
            for(int i = 0; i < n; i++){
                if(U[j] + a[i][j] > f)break;
                U[j] += a[i][j];
            }
            D[j] = 0;
            for(int i = n-1; i >= 0; i--){
                if(D[j] + a[i][j] > f)break;
                D[j] += a[i][j];
            }
        }
    }
    cout << ANS.size() << '\n';
    for(auto ans:ANS){
        cout << ans.first << ' ' << ans.second + 1 << '\n';
    }
}