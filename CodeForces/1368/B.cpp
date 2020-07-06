#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    vector <int> a(10, 1);
    int cur = 0, ans = 1;
    while(ans < k){
        a[cur]++;
        cur = (cur + 1) % 10;
        ans = 1;
        for(int i = 0; i < 10; i++){
            ans *= a[i];
        }
    }
    string s = "codeforces";
    for(int i = 0; i < 10; i++){
        while(a[i]--){
            cout << s[i];
        }
    }
    cout << '\n';
}