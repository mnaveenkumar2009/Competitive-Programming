#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a, c(2, 0);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(auto j:s){
                c[j-'0']++;
            }
            a.push_back(s.length());
        }
        sort(a.begin(), a.end());
        c[0] += (c[1]/2)*2;
        c[1] = c[1]&1;
        int ans = 0;
        for(auto i:a){
            if(c[1] && (i&1)){
                if(i-1 <= c[0]){
                    c[1] = 0;
                    c[0] -= i-1;
                    ans++;
                }
            }
            else{
                if(c[0] >= i){
                    c[0] -= i;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}