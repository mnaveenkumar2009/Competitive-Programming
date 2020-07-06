#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

ld dist(ld x1, ld y1, ld x2, ld y2){
    ld x = x1 - x2;
    ld y = y1 - y2;
    return sqrtl(x * x + y * y);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int freq[n];
    	memset(freq, 0, sizeof(freq));
    	string s;
    	cin >> s;
    	int c = 0;
    	for(int i = 0; i < n; i++){
    		if(s[i] == '1'){
    			c++;
    			freq[i] = 1;
    		}
    		if(i)
    			freq[i] += freq[i-1];
    	}
    	if(c * 2 - 1 > n){
    		cout << "impossible\n";
    		continue;
    	}
    	string s2 = s;
    	for(int i = 0; i < n; i++){
    		s2[i] = '0';
    	}
    	int offs = 0;
    	while(freq[n - 1] != 0){
    		int pos[n];
    		for(int i = 0; i < n; i++){
    			pos[i] =  i - (freq[i] * 2 - 2);
    			if(freq[i] == 0)
    				pos[i] = 1e9;
    			// if(pos[i] < 0)
    			// 	pos[i] = 1e9;
    		}
    		int mini = min_element(pos, pos + n) - pos;
    		int diff = offs - pos[mini];
    		if(diff <= 0)
    			diff = 0;
    		for(int i = pos[mini] + diff; i <= mini + diff; i += 2){
    			s2[i] = '1';
    			offs = i + 2;
    		}
    		int X = freq[mini];
    		for(int i = 0; i < n; i++){
    			freq[i] = max(0LL, freq[i] - X);
    		}
    	}
    	int ans = 0;
    	vector <int> pos2, pos1;
    	for(int i = 0; i < n; i++){
    		if(s[i] == '1'){
    			pos1.push_back(i);
    		}
    		if(s2[i] == '1'){
    			pos2.push_back(i);
    		}
    	}
    	for(int i = 0; i < pos1.size(); i++){
    		ans += abs(pos1[i] - pos2[i]);
    	}
    	// cout << s2 << '\n';
    	cout << ans << '\n';
    }
}