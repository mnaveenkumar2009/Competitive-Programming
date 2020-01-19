#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t, a = 0, b = 0;
	cin >> t;
    string s;
    cin >> s;
    for(int i = 0; i < t; i++){
        if(s[i] == 'L')
            a++;
        else
            b++;
    }
    cout << a + b + 1 << '\n';
}