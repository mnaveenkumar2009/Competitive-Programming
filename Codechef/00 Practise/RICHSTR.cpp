#include <bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);
    string s;
    cin>>s;
    int n, q, l, r;
    while(cin >> n >> q >> s){
        s.push_back(1);
        int a[n] = {0}, b[n] = {0};
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1])
                a[i] = 1;
            if(i)
                a[i] += a[i-1];
            if(s[i] == s[i+2])
                b[i] = 1;
            if(i)
                b[i] += b[i-1];
        }
        while(q--){
            cin >> l >> r;
            if(r-- - l-- < 2)
                cout<<"NO\n";
            else{
                int c = a[r-1], d = b[r-2];
                if(l){
                    c -= a[l-1];
                    d -= b[l-1];
                }
                if(c || d)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}