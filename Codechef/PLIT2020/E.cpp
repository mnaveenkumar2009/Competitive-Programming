#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector <int> quers;
    int cur = 0;
    string s;
    while(q--){
    	string y;
    	cin >> y;
    	s += y;
    	cur += y.size();
  		quers.push_back(cur);
    }
   	vector<int> v = prefix_function(s);
   	vector <int> ans = v;
   	ans[0] = 1;
   	for(int i = 1; i < ans.size(); i++){
   		ans[i] = ans[i-1] + i + 1 - v[i];
   	}
   	for(auto i:quers)
   		cout << ans[i-1] << '\n';
}