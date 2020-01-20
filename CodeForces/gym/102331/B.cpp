#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define int long long

signed main(){
    struct trie{
        trie *bit[2];
        int cnt;
        trie(){
            cnt = 0;
        }
    } *head = new trie();
    int n, x, fans = 0;
    cin >> n >> x;
    int a[n];
    for(int j = 0; j < n; j++){
        cin >> a[j];
        trie *cur = head;
        int ans = 0;
        for(int i = 60; i >= 0; i--){
            int b = ((a[j]^x) >> i)&1;
            if(!((x>>i)&1)){
                if(cur -> bit[!b]){
                    ans += (cur -> bit[!b])-> cnt;
                }
            }
            if(cur -> bit[b]){
                cur = cur -> bit[b];
                if(i == 0){
                    ans ++;
                }
            }
            else{
                break;
            }
        }
        // cout << ans + 1 << '\n';
        fans += ans + 1;
        cur = head;
        for(int i = 60; i >= 0; i--){
            int b = (a[j] >> i)&1;
            if(!(cur -> bit[b]))
                cur -> bit[b] = new trie();
            cur = (cur -> bit[b]);
            (cur -> cnt) += ans + 1;
        }
    }
    cout << fans << '\n';
}