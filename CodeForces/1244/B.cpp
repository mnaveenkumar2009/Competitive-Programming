#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cur_ans = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                cur_ans = min(cur_ans, min(i, n-i-1));
        }
        if(cur_ans != n)
            cout << 2*(n - cur_ans) << '\n';
        else{
            cout << n << '\n';
        }
    }
}