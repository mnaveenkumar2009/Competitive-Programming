#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    struct DP{
        string X;
        int A[20][20];
        DP(){
            memset(A, 0, sizeof(A));
        }
        void C(bool x){
            memset(A, 0, sizeof(A));
            if(x){
                for(int i = 0; i < 20; i++)
                    A[i][i] = 1;
            }
        }
    };
    string B_S1, B_S2;
    vector <DP> S1, S2;
    
    while(q--){
        string s;
        cin >> s;
        if(s == "add"){
            string X;
            cin >> X;
            if(S2.empty()){
                DP T;
                T.C(1);
                B_S2 = X;
                T.X = X;
                S2.push_back(T);
            }
            else{
                DP T;
                T.X = X;
                int S2s = S2.size()-1;
                for(int i = 0; i < n; i++){
                    if(i && (S2[S2s].X[i-1] == X[i]))
                        for(int j = 0; j < n; j++){
                            T.A[i][j] = (T.A[i][j] + S2[S2s].A[i-1][j]) % mod;
                        }
                    if(S2[S2s].X[i] == X[i])
                        for(int j = 0; j < n; j++){
                            T.A[i][j] = (T.A[i][j] + S2[S2s].A[i][j]) % mod;
                        }
                    if((i != n-1) && (S2[S2s].X[i+1] == X[i]))
                        for(int j = 0; j < n; j++){
                            T.A[i][j] = (T.A[i][j] + S2[S2s].A[i+1][j]) % mod;
                        }
                }
                S2.push_back(T);
            }
        }
        if(s == "remove"){
            if(S1.empty()){
                S1 = S2;
                reverse(S1.begin(), S1.end());
                B_S1 = S1[0].X;
                S2.clear();
                int S1s = S1.size() - 1;
                S1[0].C(1);
                for(int j = 1; j < S1s; j++){
                    S1[j].C(0);
                    for(int i = 0; i < n; i++){
                        if(i && (S1[j-1].X[i-1] == S1[j].X[i]))
                            for(int k = 0; k < n; k++){
                                S1[j].A[i][k] = (S1[j].A[i][k] + S1[j-1].A[i-1][k]) % mod;
                            }
                        
                        if(S1[j-1].X[i] == S1[j].X[i])
                            for(int k = 0; k < n; k++){
                                S1[j].A[i][k] = (S1[j].A[i][k] + S1[j-1].A[i][k]) % mod;
                            }
                        if((i != n-1) && (S1[j-1].X[i+1] == S1[j].X[i]))
                            for(int k = 0; k < n; k++){
                                S1[j].A[i][k] = (S1[j].A[i][k] + S1[j-1].A[i+1][k]) % mod;
                            }
                    }
                }
            }
            S1.pop_back();
        }
        if(s == "path"){
            int c, d;
            cin >> c >> d;
            c--;d--;
            int S2s = S2.size() - 1, S1s = S1.size() - 1;
            if(S1.empty())
                cout << S2[S2s].A[d][c] << '\n';
            if(S2.empty())
                cout << S1[S1s].A[c][d] << '\n';
                
            if(!S1.empty() && !S2.empty()){
                int Q2[n];
                memset(Q2, 0, sizeof(Q2));
                int ans = 0;
                for(int i = 0; i < n; i++){
                    if(i && (B_S1[i-1] == B_S2[i]))
                        Q2[i] = S1[S1s].A[c][i-1];
                    if((B_S1[i] == B_S2[i]))
                        Q2[i] = (Q2[i] + S1[S1s].A[c][i]) % mod;
                    if((i != n-1) && (B_S1[i+1] == B_S2[i]))
                        Q2[i] = (Q2[i] + S1[S1s].A[c][i+1]) % mod;
                }
                for(int i = 0; i < n; i++)
                    ans = ((long long)ans + (long long)S2[S2s].A[d][i] * Q2[i]) % mod;
                cout << ans << '\n';
            }
        }
    }
}