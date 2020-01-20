#include <bits/stdc++.h>
using namespace std;

#define int long long
int mergemin(string a, string b){
    if(a==b)
        return a.size();
    int a1 = a.size(), b1 = b.size();
    int ans1 = 0, ans2 = 0;
    string ans;
    for(int siz = a1; siz > 0; siz--){
        int found = b.rfind(a.substr(0, siz));
        if(found != std::string::npos)
            if(found == b1 - siz){
                ans1 = siz;
                break;
            }
    }
    for(int siz = a1; siz > 0; siz--){
        int found = a.rfind(b.substr(0, siz));
        if(found != std::string::npos)
            if( found == a1 - siz){
                ans2 = siz;
                break;
            }
    }
    if(ans1 > ans2){
        ans = b + a.substr(ans1, a1 - ans1);
    }
    else{
        ans = a + b.substr(ans2, b1 - ans2);
    }
    return ans.size();
}
int merge(string a, string b){
    if(a.size() > b.size()){
        swap(a, b);
    }
    if(b.find(a) != std::string::npos){
        a = b;
        reverse(a.begin(), a.end());
        return mergemin(a, b);
    }
    // a < b
    int a1 = a.size(), b1 = b.size();
    int ans1 = 0, ans2 = 0;
    string ans;
    for(int siz = a1; siz > 0; siz--){
        int found = b.rfind(a.substr(0, siz));
        if(found != std::string::npos)
            if(found == b1 - siz){
                ans1 = siz;
                break;
            }
    }
    for(int siz = a1; siz > 0; siz--){
        int found = a.rfind(b.substr(0, siz));
        if(found != std::string::npos)
            if( found == a1 - siz){
                ans2 = siz;
                break;
            }
    }
    
    string aans = b + a.substr(ans1, a1 - ans1);
    string bans = a + b.substr(ans2, b1 - ans2);
    string raans = aans, rbans = bans;
    
    reverse(raans.begin(), raans.end());
    reverse(rbans.begin(), rbans.end());
    return min(mergemin(aans, raans), mergemin(bans, rbans));
}
signed main(){
    int t;
    cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(t--){
        string s, t;
        cin >> s >> t;
        string s2 = s, t2 = t;
        reverse(s2.begin(), s2.end());
        reverse(t2.begin(), t2.end());
        // cout << merge(s, t) << '\n';
        int ans = merge(s, t);
        ans = min(merge(s, t2), ans);
        ans = min(ans, merge(s2, t2));
        ans = min(ans, merge(s2, t));
        cout << ans << '\n';
    }
}