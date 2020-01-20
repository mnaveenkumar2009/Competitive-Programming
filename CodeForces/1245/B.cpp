#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, b, c;
        cin >>a >> b >> c;
        string s, ns;
        cin >> s;
        ns = s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ns[i] = '.';
            if(s[i] == 'P'){
                if(c){
                    ans++;
                    c--;
                    ns[i] = 'S';
                }
            }
            if(s[i] == 'R'){
                if(b){
                    ans++;
                    b--;
                    ns[i] = 'P';
                }
            }
            if(s[i] == 'S'){
                if(a){
                    ans++;
                    a--;
                    ns[i] = 'R';
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(ns[i] == '.'){
                if(s[i] == 'P'){
                    if(b){
                        b--;
                        ns[i] = 'P';
                    }
                }
                if(s[i] == 'R'){
                    if(a){
                        a--;
                        ns[i] = 'R';
                    }
                }
                if(s[i] == 'S'){
                    if(c){
                        c--;
                        ns[i] = 'S';
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(ns[i] == '.'){
                // ans--;
                if(a){
                    a--;
                    ns[i] = 'R';
                }
                if(b){
                    b--;
                    ns[i] = 'P';
                }
                if(c){
                    c--;
                    ns[i] = 'S';
                }
            }
        }
        if(ans >= ((n+1)/2)){
            cout << "YES\n" << ns << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}