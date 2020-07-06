#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

int pr(int x, int y){
    x %= mod;
    int res = 1;
    while(y){
        if(y&1){
            res =( res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

int End[100005];
string s;
struct Exp {
    int a[3];
}defau;

// 0 1 a a^
Exp And(Exp X, Exp Y){
    int A[3] = {0, 0, 0};
    
    int S1 = (X.a[0] + X.a[1] + X.a[2]*2) % mod;
    int S2 = (Y.a[0] + Y.a[1] + Y.a[2]*2) % mod;
    A[0] = (S1 * Y.a[0] + X.a[0] * S2 + X.a[2] * Y.a[2] * 2 - (X.a[0] * Y.a[0]) % mod + mod) % mod;
    A[1] = (X.a[1] * Y.a[1]) % mod;
    A[2] = (X.a[2] * Y.a[2] + X.a[2] * Y.a[1] + X.a[1] * Y.a[2]) % mod;
    for(int i = 0; i < 3; i++)
        X.a[i] = A[i];
    return X;
}
Exp Or(Exp X, Exp Y){
    int A[3] = {0, 0, 0};
    
    int S1 = (X.a[0] + X.a[1] + X.a[2]*2) % mod;
    int S2 = (Y.a[0] + Y.a[1] + Y.a[2]*2) % mod;
    A[1] = (S1 * Y.a[1] + X.a[1] * S2 + X.a[2] * Y.a[2] * 2 - (X.a[1] * Y.a[1]) % mod + mod) % mod;
    A[0] = (X.a[0] * Y.a[0]) % mod;
    A[2] = (X.a[2] * Y.a[2] + X.a[2] * Y.a[0] + X.a[0] * Y.a[2]) % mod;
    for(int i = 0; i < 3; i++)
        X.a[i] = A[i];
    return X;
}

Exp Xor(Exp X, Exp Y){
    int A[3] = {0, 0, 0};
    
    A[0] = (X.a[0] * Y.a[0] + X.a[1] * Y.a[1] + X.a[2] * Y.a[2] * 2) % mod;
    A[1] = (X.a[0] * Y.a[1] + X.a[1] * Y.a[0] + X.a[2] * Y.a[2] * 2) % mod;
    A[2] = ((X.a[0] + X.a[1])*Y.a[2] + (Y.a[0] + Y.a[1])*X.a[2]) % mod;
    
    for(int i = 0; i < 3; i++)
        X.a[i] = A[i];
    return X;
}

Exp f(int l, int r){
    // cout << l << ' ' << r <<  '\n';
    if(l == r){
        assert(s[l] == '#');
        return defau;
    }
    char Op = s[End[l+1] + 1];
    if(Op == '&')
        return And(f(l+1, End[l+1]), f(End[l+1] + 2, End[End[l+1] + 2]));
    if(Op == '^')
        return Xor(f(l+1, End[l+1]), f(End[l+1] + 2, End[End[l+1] + 2]));
    if(Op == '|')
        return Or(f(l+1, End[l+1]), f(End[l+1] + 2, End[End[l+1] + 2]));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    defau.a[0] = defau.a[1] = defau.a[2] = pr(4, mod - 2);
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        int n = s.size();
        stack <int> X;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                X.push(i);
            }
            if(s[i] == ')'){
                End[X.top()] = i;
                X.pop();
            }
            if(s[i] == '#'){
                End[i] = i;
            }
        }
        Exp ans = f(0, n - 1);
        cout << ans.a[0] << ' ' << ans.a[1] << ' ' << ans.a[2] << ' ' << ans.a[2] <<'\n';
    }
}