#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int ans = 0, n = s.size();
    for(int i = 0; i < n; i++)
        s[i] -= 'a';
    vector <int> F(1<<21, 0);
    for(int i = 0; i < n; i++){
        int cur = 0, j = i;
        while(!(cur & (1 << s[j])) && (j != n)){
            cur |= 1 << s[j];
            F[cur] = ++j - i;
        }
    }
    for(int i = 0; i < 20; i++)
        for(int mask = 0; mask < (1<<20); mask++)
            if(mask & (1 << i))
                F[mask] = max(F[mask], F[mask ^ (1 << i)]);
    
    for(int mask = 0; mask < (1 << 20); mask++)
        ans = max(ans, F[((1 << 20) - 1) ^ mask] + F[mask]);
    cout << ans << '\n';
}