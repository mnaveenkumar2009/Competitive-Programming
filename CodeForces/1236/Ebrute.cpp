#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int n, m;
    cin >> n >> m;
    vector <int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    int maxi[n], mini[n];
    for(int i = 1; i <= n; i++){
        int X = i;
        for(int j = 0; j < m; j++){
            if(a[j] != X + 1)
                X++;
        }
        X++;
        maxi[i - 1] = min(n, X);
        X = i;
        for(int j = 0; j < m; j++){
            if(a[j] != X - 1)
                X--;
        }
        X--;
        mini[i - 1] = max(1LL, X);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cout << maxi[i - 1] << ' ' <<  mini[i - 1] << '\n';
        ans += maxi[i - 1] - mini[i - 1] + 1;
    }
    cout << ans << '\n';
}