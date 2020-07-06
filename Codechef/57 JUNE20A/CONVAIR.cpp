#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, u, v;
        cin >> n >> m;
        if(n == 1){
            cout << "0 0\n";
            continue;
        }
        vector <int> b(n, 0);
        set <pair <int, int> > S;
        pair <int, int> a[n + m];

        for(int i = 0; i < m; i++){
            cin >> u >> v;
            b[u-1]++;
            b[v-1]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (b[i] == 0);
            S.insert({max(b[i], 1), i});
        }
        m = 0;
        while(S.size() > 0){
            if(S.size() == 1){
                assert((*S.begin()).first == 1);
                ans++;
                a[m++] = {(*S.begin()).second, ((*S.begin()).second + 1) % n};
                break;
            }
            auto i = *S.begin();
            auto jj = S.end();
            jj--;
            auto j = *(jj);
            S.erase(jj);
            S.erase(S.begin());
            a[m++] = {i.second, j.second};
            i.first--;
            j.first--;
            if(i.first)
                S.insert(i);
            if(j.first)
                S.insert(j);
            else{
                if(S.size() > 0){
                    S.insert({1, j.second});
                    ans++;
                }
            }
        }
        cout << ans << ' ' << m << '\n';
        for(int i = 0; i < m; i++){
            cout << a[i].first + 1 << ' ' << a[i].second + 1 << '\n';
        }
    }
}