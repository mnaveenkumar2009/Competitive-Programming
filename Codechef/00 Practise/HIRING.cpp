#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, ans = 0;
        cin >> n >> m;
        vector < vector <int> > DP(256, vector <int> (256, 0));
        while(n--){
            string s;
            cin >> s;
            int x = 0, temp = 1;
            for(auto i:s)
                x = (x << 1) | (i - '0');
            for(int j = 0; j < 256; j++)
                if(!(x & (j << 8)))
                    temp = (temp + DP[j][x & 255]) % mod;
            ans = (ans + temp) % mod;
            for(int j = 0; j < 256; j++)
                if(!(x & j))
                    DP[x >> 8][j] = (DP[x >> 8][j] + temp) % mod;
        }
        cout << ans << '\n';
    }
}