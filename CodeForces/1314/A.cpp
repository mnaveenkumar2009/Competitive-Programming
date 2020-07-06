#include <bits/stdc++.h>
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    multiset <pair<int, int> > A;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> y[i];
    for(int i = 0; i < n; i++)
        A.insert({x[i], -y[i]});
    long long ans = 0;
    int cur = 0, star = -100;
    while(A.size()){
        auto X = *A.begin();
        A.erase(A.begin());
        if(X.first == star){
            A.insert({cur, X.second});
            ans += ((long long)(cur - X.first)) * X.second;
            cur++;
        }
        else{
            star = X.first;
            cur = X.first + 1;
        }
    }
    cout << -ans << '\n';
}