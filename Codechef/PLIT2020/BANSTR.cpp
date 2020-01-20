#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, p;
    	cin >> n >> p;
    	string s;
    	cin >> s;
    	vector <int> a, B;
    	for(int i = 0; i < n; i++){
    		if(s[i] == 'a')
    			a.push_back(i);
    	}
    	B = a;
    	int swaps = 0;
    	for(int i = 0; i < n; i++){
    		if(a.size() == 0 || p == 0)
    			break;
    		if(s[i] == 'b'){
    			int pa = a[a.size() - 1];
    			if(pa < i)break;
    			a.pop_back();
    			swap(s[i], s[pa]);
    			swaps++;
    			p--;
    		}
    	}
    	for(auto i:B){
    		if(s[i] == 'b' && p){
    			s[i] = 'a';
    			p--;
    		}
    	}
    	// cout << s << ' ' << p << '\n';
    	for(int i = 0; i < n; i++){
    		if(s[i] == 'b'){
				if(p > 1){
					p -= 2;
					s[i] = 'a';
				}
    		}
    	}
    	if(p == 1){
    		int first_b = 1e9, last_a = -1;
    		for(int i = 0; i < n; i++){
    			if(s[i] == 'b'){
    				first_b = min(i, first_b);
    			}
    			else
    				last_a = i;
    		}
    		if(last_a != -1 && first_b != 1e9 && first_b < last_a){
    			swap(s[last_a], s[first_b]);
    		}
    	}
    	cout << s << '\n';
    }
}