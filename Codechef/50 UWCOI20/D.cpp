#include <bits/stdc++.h>
using namespace std;

 #define int long long
const int N = 2e6 + 2;
#define ll long long
int n;
int tree1[2 * N], tree2[2*N];

void modify1(ll p, ll value) {
    for (tree1[p += n] = value; p > 1; p >>= 1)
        tree1[p>>1] = max(tree1[p],tree1[p^1]);
}

void modify2(ll p, ll value) {
    for (tree2[p += n] = value; p > 1; p >>= 1)
        tree2[p>>1] = min(tree2[p],tree2[p^1]);
}
int query1(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, tree1[l++]);
        if (r&1) res = max(res, tree1[--r]);
    }
    return res;
}
int query2(int l, int r) {
    int res = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, tree2[l++]);
        if (r&1) res = min(res, tree2[--r]);
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n][n];
        string s[n];
        int P[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
            for(int j = 0; j < n; j++){
                a[i][j] = s[i][j] - '0';
                if(a[i][j]){
                    P[i] = j;
                }
            }
            modify1(i, P[i]);
            modify2(i, P[i]);
        }

        int ans = 0;
        for(int S = 1; S <= n; S++){
            for(int i = 0; i <= n - S; i++){
                int mini = 1e9, maxi = 0;
                maxi = query1(i, i + S);
                mini = query2(i, i + S);

                if(maxi == mini + S - 1)
                    ans++;
            }
        }   
        cout << ans << '\n';
    }

}