#include <bits/stdc++.h>
using namespace std;

#define int long long

pair <int, int> f(int a, int b){
    if(a < b){
        return {a, b};
    }
    else{
        return {b, a};
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        vector <pair <int, int> > X, Y;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++){
            X.push_back(f(a[i], a[n -i - 1]));
            Y.push_back(f(b[i], b[n -i - 1]));
        }
        bool we = 1;
        if(n&1){
            we = a[n/2] == b[n/2];
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        if(X == Y && we){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}