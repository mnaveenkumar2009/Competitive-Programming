#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        std::vector< int> prin;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                for(int j = i+1; j < n; j++){
                    if(t[j] == t[i] && t[j] != s[j]){
                        swap(t[j], s[i]);
                        break;
                    }
                }
                break;
            }
        }
        if(s == t)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}