#include <bits/stdc+.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int F[20][20];
    memset(F, 0, sizeof(F));
    for(int i = 1; i < s.length(); i++){
        F[s[i] - '0'][s[i-1] - '0']++;
        F[s[i-1] - '0'][s[i] - '0']++;
    }
    int PRE[1 << 20][20];
    int DP[1 << 20];
    memset(DP, INT_MAX, sizeof(DP));
    memset(PRE, 0, sizeof(PRE));
    for(int mask = 0; mask < (1<<20); mask++){
        for(int j = 0; j < 20; j++){
            if(mask & (1 << j)){
                continue;
            }
            else{
                PRE[mask][j] = 
            }
        }
    }
    DP[0] = 0;
    for(int mask = 0; mask < (1<<20); mask++){
        for(int j = 0; j < 20; j++){
            if(mask & (1 << j)){
                int cost = 0;
                DP[mask] = min(DP[mask ^ (1 << j)] + cost, DP[mask]);
            }
        }
    }
}