#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, m;
    	cin >> n >> m;
    	char a[n][m];
    	for(int i = 0; i < n; i++){
    		string s;
    		cin >> s;
    		for(int j = 0; j < m; j++){
    			a[i][j] = s[j];
    		}
    	}
    	bool we = 1;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(a[i][j] == 'B'){
    				if(i){
    					if(a[i-1][j] == 'G')
    						we = 0;
    					if(a[i-1][j] == '.')
    						a[i-1][j] = '#';
    				}
    				if(i != n - 1){
    					if(a[i+1][j] == 'G')
    						we = 0;
    					if(a[i+1][j] == '.')
    						a[i+1][j] = '#';
    				}
    				if(j != m - 1){
    					if(a[i][j+1] == 'G')
    						we = 0;
    					if(a[i][j+1] == '.')
    						a[i][j+1] = '#';
    				}
    				if(j != 0){
    					if(a[i][j-1] == 'G')
    						we = 0;
    					if(a[i][j-1] == '.')
    						a[i][j-1] = '#';
    				}
    			}
    		}
    	}
        bool c[n][m];
        memset(c, 0, sizeof(c));
        #define vis c
	    list<pair <int, int> > queue;
	    vis[n-1][m-1] = a[n-1][m-1] == '.';
	    if(vis[n-1][m-1])
	    	queue.push_back({n-1, m-1});
	    while(!queue.empty()) 
	    {
	        auto s = queue.front();
	        queue.pop_front();
	        int i, j;
	        vis[i = s.first][j = s.second] = 1;

			if(i){
				if(a[i-1][j] != '#' && !vis[i-1][j]){
					vis[i-1][j] = 1;
					queue.push_back({i-1, j});
				}
			}
			if(i != n - 1){
				if(a[i+1][j] != '#' && !vis[i+1][j]){
					vis[i+1][j] = 1;
					queue.push_back({i+1, j});
				}
			}
			if(j != m - 1){
				if(a[i][j+1] != '#' && !vis[i][j+1]){
					vis[i][j+1] = 1;
					queue.push_back({i, j + 1});
				}
			}
			if(j != 0){
				if(a[i][j-1] != '#' && !vis[i][j-1]){
					vis[i][j-1] = 1;
					queue.push_back({i, j-1});
				}
			}
	    } 
	    for(int i = 0; i < n; i++){
	    	for(int j = 0; j < m; j++){
	    		if(a[i][j] == 'G' && !c[i][j])we = 0;
	    		if(a[i][j] == 'B' && c[i][j])we = 0;
	    	}
	    }
        if(we){
        	cout << "Yes\n";
        }
        else{
      		cout << "No\n";
        }
    }
}