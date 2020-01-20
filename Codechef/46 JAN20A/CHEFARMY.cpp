#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
	int t;
	cin >> t;
	while(t--){
	    int m, n;
	    cin >> m >> n;
	    int num_of_children[n];
	    memset(num_of_children, 0, sizeof(num_of_children));
	    string b[m];
	    for(int i = 0; i < m; i++)
	    	cin >> b[i];
	    int S[n], P[n];
	    for(int i = 0; i < n; i++)
	    	cin >> S[i];
	    for(int i = 0; i < n; i++){
	    	cin >> P[i];
	    	P[i]--;
	    }
	    vector <vector <bool> > poss(n, vector <bool> (n, 1));
	    for(int i = 0; i < n; i++){
	    	int p = P[i];
	    	while(p != -1){
	    		poss[i][p] = poss[p][i] = 0;
	    		p = P[p];
	    	}
	    }
	    vector<int> ND;
	    for(int i = 0; i < n; i++)
	    	ND.push_back(i);
	    // for(auto I:ND)cout << I << ' ';
	    cout << n << '\n';
	    int annn = 0;
	    while(ND.size()){
	    	int C = 200;
	    	vector<int> cND = ND;
	    	vector<int> ans;
	    	while(C-- && (int)cND.size()){
	    		int pos = rand()%((int)cND.size());
	    		int x = cND[pos];
	    		bool we = 1;
	    		for(auto i:ans){
	    			we &= poss[x][i];
	    		}
	    		if(we){
	    			ans.push_back(x);
	    		}
	    		cND.erase(cND.begin() + pos);
	    	}
	    	int min_ele = 0, min_val = 1e3;
	    	for(auto i : ans){
	    		min_val = min(min_val, S[i]);
	    	}
	    	annn++;
	    	cout << ans.size() << ' ' << min_val << ' ';
	    	for(auto i : ans){
	    		cout << i + 1 << ' ';
	    		S[i] -= min_val;
	    	}
	    	cout << '\n';
	    	for(int i = 0; i < ND.size(); i++){
	    		if(S[ND[i]] == 0){
	    			ND.erase(ND.begin() + i);
	    			i--;
	    		}
	    	}
	    }
	    while(n - annn){
	    	cout << "1 0 1\n";
	    	annn++;
	    }
	}
}