#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int d, n;
        cin >> n >> d;
        string s[n];
        map <string, int> m;
        int ans = 0, cur = 0;
        for(int i = 0; i < d; i++){
            cin >> s[i];
            m[s[i]]++;
            if(m[s[i]] == 1)
                cur++;
        }
        ans = cur;
        for(int i = d; i < n; i++){
            cin >> s[i];
            m[s[i]]++;
            if(m[s[i]] == 1)
                cur++;
            m[s[i-d]]--;
            if(m[s[i-d]] == 0)
                cur--;
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }

}