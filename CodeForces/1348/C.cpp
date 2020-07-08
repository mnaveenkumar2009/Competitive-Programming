#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
    	int n, k;
    	string s;
    	cin >> n >> k >> s;
    	sort(s.begin(), s.end());
    	if(s[0] == s[n-1]){
    		cout << s.substr(0, (n/k));
    		if(n%k != 0){
    			cout << s[0];
			}cout << '\n';
		}
		else{
			if(s[0] == s[k-1]){
			    if(k<n){
			        if(s[k-1] != s[k] && s[k] == s[n-1]){
			            cout << s[0];
				        s.erase(s.begin(), s.begin() + k);
				        n = s.size();
                		cout << s.substr(0, (n/k));
                		if(n%k != 0){
                			cout << s[0];
            			}cout << '\n';
			            continue;
			        }
			    }
				s.erase(s.begin(), s.begin() + k - 1);
				cout << s << '\n';
			}
			else{
				cout << s[k-1] << '\n';
			}
		}
    }
}