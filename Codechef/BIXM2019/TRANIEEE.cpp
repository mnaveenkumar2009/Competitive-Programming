#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int, bool> S;
int n, St, En;
pair <int, int> DP[1000006];
int Phi[1000006];

void computeTotient(int n){
    for (int i = 1; i <= n; i++)
        Phi[i] = i;
    for (int p=2; p<=n; p++){
        if(Phi[p] == p){
            Phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p)
                Phi[i] = (Phi[i]/p) * (p-1);
        } 
    }
}
pair <int, int> F(int N){
    // cout << N <<'\n';
    if(DP[N].first != -1)
        return DP[N];
    if(N == En)
        return DP[N] = {0, N};
    DP[N] = {-2, -2};
    if(N == 1){
        return DP[N];
    }
    if(S[Phi[N]]){
        pair <int, int> XXX = F(Phi[N]);
        if(XXX.first != -2){
            DP[N].first = 1 + XXX.first;
            DP[N].second = N + XXX.second;
        }
    }
    if(N*N <= 1e6){
        if(N==1)
            return DP[N];
        if(S[N*N]){
            pair <int, int> XXX = F(N*N);
            if(XXX.first != -2){
                XXX.first++;
                XXX.second += N;
                if(DP[N].first == -2)
                    DP[N] = XXX;
                else{
                    DP[N] = min(DP[N], XXX);
                }
            }
        }
    }
    return DP[N];
}
signed main(){
    cin >> n >> St >> En;
    for(int i = 0; i < 1e6; i++){
        DP[i] = {-1, -1};
    }
    while(cin >> n)
        S[n] = 1;
    computeTotient(1e6);
    for(int i = 0; i < 1e1; i++){
        // cout << Phi[i] <<'\n';
    }
    F(St);
    cout << DP[St].first << ' ' << DP[St].second << '\n';
}