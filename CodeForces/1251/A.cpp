#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector <bool> a(26, 0);
        string s;
        cin >> s;
        s.push_back('0');
        int n = s.length();
        // cout << s << '\n';
        for(int i = 0; i < n - 1; i++){
            if(s[i]==s[i+1]){
                i+=1;
            }
            else{
                a[s[i]- 'a'] = 1;
            }
        }
        for(int i = 0; i < 26; i++){
            if(a[i]){
                cout <<(char)(i +'a');
            }
        }
        cout << '\n';
    }
}