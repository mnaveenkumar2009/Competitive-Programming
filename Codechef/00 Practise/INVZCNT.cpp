#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    int t, n, q, x, ans[64][2];
    cin >> t;
    while(t--){
        struct trie{
            trie* bit[2];
            int cnt = 0;
        };        
        trie *head = new trie(), *cur = head;
        memset(ans, 0, sizeof(ans));
        for(cin >> n >> q; n--; cur = head){
            cin >> x;
            for(int i = 31; i >= 0; i--){
                int b = (x >> i) & 1;
                if(cur -> bit[b^1])
                    ans[i][b] += cur -> bit[b^1] -> cnt;
                if(!cur->bit[b])
                    cur -> bit[b] = new trie();
                cur = cur -> bit[b];
                cur -> cnt++;
            }
        }
        while(q--){
            int k, A = 0;
            cin >> k;
            for(int i = 30; i >= 0; i--)
                A += ans[i][(k >> i)&1];
            cout << A << '\n';
        }
    }    
}