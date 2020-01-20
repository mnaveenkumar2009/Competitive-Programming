#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define N 100005

long long dp[N][4];
long long l[N], r[N], c[N];
bool vis[N];

void f(int node){
    if(vis[node])
        return;
    vis[node] = 1;
    // cout<<node<<' '<<c[node]<<'\n';
    long long L[4]={0}, R[4]={0};
    if(l[node] == -1){
        L[0] = 1;
        L[3] = 1;
    }
    else{
        f(l[node]);
        for(int i = 0; i < 4; i++)
            L[i] = dp[l[node]][i];
    }
    if(r[node] == -1){
        R[0] = 1;
        R[3] = 1;
    }
    else{
        f(r[node]);
        for(int i = 0; i < 4; i++)
            R[i] = dp[r[node]][i];
    }
    dp[node][0] = (L[3]*R[3])%mod;
    dp[node][1] = (L[2]*R[2])%mod + (L[2]*R[3])%mod + (L[3]*R[2])%mod;
    dp[node][2] = (L[1]*R[1])%mod + (L[1]*R[3])%mod + (L[3]*R[1])%mod;
    dp[node][3] = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            int x = !((i/2)&(j/2)), y = !((i&1)&(j&1));
            if(x&&y){
                dp[node][3] += (L[i]*R[j])%mod;
                dp[node][3] %= mod;
            }
        }
    if(c[node] == 0){
        dp[node][0] += dp[node][2];
        dp[node][1] += dp[node][3];
        dp[node][3] = dp[node][2] = 0;
    }
    if(c[node] == 1){
        dp[node][2] += dp[node][0];
        dp[node][3] += dp[node][1];
        dp[node][0] = dp[node][1] = 0;
    }
    for(int i = 0; i < 4; i++)
        dp[node][i]%=mod;
}
int main(){
    int n;
    cin >> n;
    set <int> cur;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            dp[i][j] = 0;
        }
        l[i] = r[i] = c[i] = vis[i] = 0;
    }
    for(int i = 0 ;i < n; i++){
        cin >> l[i] >> r[i] >> c[i];
        l[i]--;
        r[i]--;
        cur.insert(l[i]);
        cur.insert(r[i]);
    }
    // for(auto it:cur)cout<<it<<' ';cout<<'\n';
    int i = 0;
    for(auto it:cur){
        if(it!=-1){
            if(it!=i++)break;
        }
    }
    i--;
    // i is root
    if(i==-1)
        i = 0;
    f(i);
    cout<<(dp[i][1]+dp[i][2])%mod<<'\n';
}