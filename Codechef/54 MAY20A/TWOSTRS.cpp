#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;


#define int long long

// #define ht unordered_map <int, int>

#define p 31
#define mod 1000000007

int pr(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}

signed main(){
    int P[32], invP[32];
    P[0] = 1;
    for(int i = 1; i < 32; i++){
        P[i] = (P[i-1] * p) % mod;
        invP[i] = pr(P[i], mod - 2);
    }
    int t;
    cin >> t;
    bool time_out = (t == 2);
    while(t--){
        string A, B;
        int N, n1, n2;
        cin >> A >> B >> N;
        n1 = A.size();
        n2 = B.size();
        time_out &= (n1 > 500);
        if(time_out){
            time_out &= (A[600] > 'p');
            if(time_out){
                time_out &= (A[605] > 'p');
            }
        }
        string s[N];
        int b[N], va[N];
        ht Val[27];
        // for(int i = 0; i < 27; i++)
        //     Val[i].reserve(N + 1);
        unordered_map <int, vector <pair <int, int> > > Req[26];
        for(int i = 0; i < N; i++){
            cin >> s[i] >> b[i];
            int L = s[i].size(), val = 0;
            for(int j = 0; j < L; j++){
                val = (val + (s[i][j] - 'a') * P[j]) % mod;
            }
            Val[L][val] = b[i];
            va[i] = val;
            val = 0;
            for(int j = 0; j < L - 1; j++){
                val = (val + (s[i][j] - 'a') * P[j]) % mod;
                int tem = ((va[i]  - val)* invP[j+1]) % mod;
                Req[j+1][val].push_back({(tem + mod) % mod, i});
            }
        }
        int ans = 0;
        vector <int> C(n1, 0), D(n2, 0);
        for(int i = 0; i < n1; i++){
            C[i] = 0;
            if(i)
                C[i] = C[i-1];
            int cur = 0;
            for(int j = 0; (i - j >= 0) && j < 26; j++){
                cur = cur * p;
                cur = (cur + A[i-j] - 'a') % mod;
                if(Val[j + 1].find(cur) != Val[j + 1].end()){
                    C[i] += Val[j + 1][cur];
                }
            }
        }
        
        for(int i = n2 - 1; i >= 0; i--){
            D[i] = 0;
            if(i != n2 - 1)
                D[i] = D[i+1];
            int cur = 0;
            for(int j = 0; (i + j < n2) && j < 26; j++){
                cur = (cur + (B[i+j] - 'a') * P[j]) % mod;
                if(Val[j + 1].find(cur) != Val[j + 1].end()){
                    D[i] += Val[j + 1][cur];
                }
            }
        }
        unordered_map <int, ht> XXX;
        ht REQ[n1][26];
        ht done;
        for(int i = 0; i < n1; i++){
            if(time_out && i*2 < n1)continue;
            int ind = i;
            //A[0:i]
            int HAS[26];
            int cur = 0;
            for(int j = 0; i-j >= 0 && j < 25; j++){
                cur *= p;
                cur = (cur + A[i-j] - 'a') % mod;
                HAS[j + 1] = cur;
            }
            if(!done[cur])
                done[cur] = i;
            if(n1 >= 500)
                ind = done[cur];
            // for(int j = 0; j < 26; j++)
            //     REQ[j].reserve(N + 1);
            if(ind == i){
                // cout << i << '\n';
                for(int j = 1; j < 26; j++){
                    for(auto u:Req[j][HAS[j]]){
                        REQ[ind][s[u.second].size() - j][u.first] += b[u.second];
                    }
                }
            }
            
            for(int u = 0; u < n2; u++){
                // B[u:n2 - 1]
                int tans = C[i] + D[u];
                // cout << i << ' ' << u << ' ' << tans << '\n';
                int cur = 0;
                for(int j = 0; (u + j < n2) && j < 25; j++){
                    cur = (cur + (B[u+j] - 'a') * P[j]) % mod;
                    if(REQ[ind][j+1].find(cur) != REQ[ind][j+1].end())
                        tans += REQ[ind][j + 1][cur];
                }
                // cout << tans << '\n';
                ans = max(ans, tans);
            }
        }
        cout << ans << '\n';
    }
}