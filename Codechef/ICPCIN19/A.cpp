#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector <int> A((1 << 20), 1e7);
        string s;
        cin >> s;
        for(int i = 0; i < k; i++){
            string s1;
            cin >> s1;
            int x = 0;
            for(auto i : s1)
                x += 1 << (i - 'a');
            // cout << x << '\n';
            A[x] = i + 1;
        }
        for(int mask = (1<<20) - 1; mask >= 0 ; --mask)
            for(int i = 0; i < 20; ++i)
                if(mask & (1<<i))
                    A[mask^(1<<i)] = min(A[mask^(1<<i)], A[mask]);
        int cur = 0, printed = 0;
        for(int i = 0; i < s.size(); i++){
            // cout << cur << '\n';
            if(A[cur | (1 << (s[i] - 'a'))] == 1e7){
                for(; printed < i; printed++){
                    cout << A[cur] << ' ';
                }
                cur = 0;
            }
            cur |= (1 << (s[i] - 'a'));
        }
        // cout << cur  << '\n';
        for(; printed < n; printed++){
            cout << A[cur] << ' ';
        }
        cout << '\n';
    }
}