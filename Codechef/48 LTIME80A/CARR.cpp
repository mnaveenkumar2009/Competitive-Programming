#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define mod 1000000007

int pr(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}

vector <vector <ll> > mul(vector <vector <ll> > &a,vector <vector <ll> > &b){
    ll n=a.size();
    vector <vector <ll> > res(n,vector<ll> (n));
    int i, j, k; 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < n; k++)
                res[i][j] = (res[i][j]+(a[i][k]*b[k][j])%mod)%mod;
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        m %= mod;
        vector < vector <ll> > mat(2,vector <ll> (2,0)),id(2,vector<ll> (2,0)), res = id;
        id[0][0]=1;
        id[1][1]=1;
        res = id;
        mat[1][0] = m - 1;
        mat[1][1] = m - 1;
        mat[0][1] = 1;
        mat[0][0] = 0;
        if(n==1){
            cout<< m % mod << "\n";
            continue;
        }
        n -= 2;
        // cout << n << '\n';
        while(n){
            if(n&1){
                res = mul(res, mat);
            }
            mat = mul(mat, mat);
            n /= 2;
        }
        // cout << res[0][0] << ' ' << res[0][1] << '\n';
        // cout << res[1][0] << ' ' << res[1][1] << '\n';
        int a1 = m * (m - 1);
        a1 %= mod;
        int ans = (res[0][0] + res[1][0]) * m + (res[0][1] + res[1][1]) * a1;
        cout << (ans % mod) << '\n';
    }
}