#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    while(n){
    	s.push_back('a' + ((n-1)%26));
    	n--;
    	n /= 26;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}