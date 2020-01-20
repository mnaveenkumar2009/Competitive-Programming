#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
int n, m;
vector <int> a(MAXN);
int maxi[MAXN], mini[MAXN];
int X[MAXN], Y[MAXN];
unordered_map <int, vector <int> > mxpos, mnpos;
int MX(int P){
    if(X[P] != -1)
        return X[P];
    int num = a[P] - 2 - P; // at -1 -> a[p] - 1 - p - 1
    int posi = upper_bound(mxpos[num].begin(), mxpos[num].end(), P) - mxpos[num].begin();
    if(posi == mxpos[num].size())
        return X[P] = a[P] + m - P - 1;
    return X[P] = MX(mxpos[num][posi]);
}
int MN(int P){
    if(Y[P] != -1)
        return Y[P];
    int num = a[P] + 2 + P; // at -1 -> a[p] - 1 - p - 1
    int posi = upper_bound(mnpos[num].begin(), mnpos[num].end(), P) - mnpos[num].begin();
    if(posi == mnpos[num].size())
        return Y[P] = a[P] + 1 - m + P;
    return Y[P] = MN(mnpos[num][posi]);
}
signed main(){
    cin >> n >> m;
    bool we = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        if(a[i] == 1)
            we = 1;
        X[i] = Y[i] = -1;
        mxpos[a[i] - 1 - i].push_back(i);
        mnpos[a[i] + 1 + i].push_back(i);
    }

    for(int i = 0; i < m; i++){
        MX(i);
        MN(i);
        // cout << X[i] << ' '<< Y[i]<< '\n';
    }
    // cout <<"MXMN\n";
    for(int i = 1; i <= n; i++){
        if(mnpos[i].size() == 0)
            mini[i - 1] = max(1LL, i - m - 1);
        else
            mini[i - 1] = max(Y[mnpos[i][0]], i - m - 1);
        if(mxpos[i].size() == 0)
            maxi[i - 1] = min(n, i + m + 1);
        else
            maxi[i - 1] = min(i + m + 1, X[mxpos[i][0]]);
        mini[i - 1] = max(1LL, mini[i - 1]);
        maxi[i - 1] = min(n, maxi[i - 1]);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += maxi[i - 1] - mini[i - 1] + 1;
    }
    if(n == 1){
        ans = 1 - we;
    }
    cout << ans << '\n';
}