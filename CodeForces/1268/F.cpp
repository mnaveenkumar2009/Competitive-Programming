#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector <int> a, b;
    int cur = '(';
    int i = 0;
    while(1){
        int coun = 0;
        while(s[i] == cur){
            coun++;
            i++;
            if(i == n)
                break;
        }
        // cout << i << ' ' << coun << " v" << '\n';
        a.push_back(coun);
        cur = '(' + ')' - cur;
        if(i == n)
            break;
    }
    cur = '(';
    i = 0;
    while(1){
        int coun = 0;
        while(t[i] == cur){
            coun++;
            i++;
            if(i == m)
                break;
        }
        b.push_back(coun);
        cur = '(' + ')' - cur;
        if(i == m)
            break;
    }

    if(a.size() < b.size()){
        while(a.size() != b.size()){
            a.push_back(0);
        }
    }
    if(a.size() > b.size()){
        while(a.size() != b.size()){
            b.push_back(0);
        }
    }
    string ans;
    int co = 0;
    cur = '(';
    for(int i = 0; i < a.size(); i++){
        int num = max(a[i], b[i]);
        if(cur == ')' && co < num){
            while(co--){
                ans.push_back(')');
                num--;
            }
            co = 0;
            while(co != num){
                co++;
                ans.push_back('(');
            }
            if(i != a.size() - 1)
                if(a[i] > b[i]){
                    b[i+1] = max(0LL, b[i+1] - co);
                    if(b[i+1] == 0){
                        if(i+2 != a.size())
                            b[i+2] = max(0LL, b[i+2] - num);
                    }
                }
                else
                    if(a[i] < b[i]){
                        a[i+1] = max(0LL, a[i+1] - co);
                        if(a[i+1] == 0){
                            if(i+2 != a.size())
                                a[i+2] = max(0LL, a[i+2] - num);
                        }
                    }
        }
        if(cur == ')')
            co -= num;
        else
            co += num;
        while(num--)
            ans.push_back(cur);
        cur = '(' + ')' - cur;
    }
    while(co--)
        ans.push_back(')');
    cout << ans << '\n';
}