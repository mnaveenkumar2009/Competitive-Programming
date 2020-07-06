#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        int k = 1;
        for(int i = 0; i < n; i++){
            string news = s.substr(i, n - i);
            string x = s.substr(0, i);
            if((i + n) & 1){
                reverse(x.begin(), x.end());
            }
            news += x;
            if(ans > news){
                ans = news;
                k = i + 1;
            }
        }
        cout << ans << '\n' << k << '\n';
    }
}