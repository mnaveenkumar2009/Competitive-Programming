#include <bits/stdc++.h>
using namespace std;

#define int long long
int ans[64][2];
typedef struct data
{
    data* bit[2];
    int cnt = 0;
    int sum = 0;
}trie;
 
trie* head;
 
void insert(int x)
{
    trie* cur = head;
    for(int i = 60; i >= 0; i--)
    {
        int b = (x >> i) & 1;
        trie* cur0 = cur, *cur1 = cur;
        cur0 = cur -> bit[0];
        cur1 = cur -> bit[1];
        if(b){
            if(cur0)
                ans[i][b] += cur0 -> cnt;
        }
        else{
            // normal inv
            if(cur1)
                ans[i][b] += cur1 -> cnt;
        }
        if(!cur->bit[b])
            cur -> bit[b] = new trie();
        cur = cur -> bit[b];
        cur->cnt++;
    }
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        head = new trie();
        for(int i = 0; i < 64; i++){
            ans[i][0]=ans[i][1]=0;
        }
        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            insert(x);
        }
        for(int i = 0; i < 64; i++){
            // cout << ans[i][0] << ' '<< ans[i][1] << '\n'; 
        }
        while(q--){
            int k;
            cin >> k;
            int A = 0;
            for(int i = 40; i>=0; i--){
                A += ans[i][(k >> i)&1];
            }
            cout << A << '\n';
        }
    }
    
}