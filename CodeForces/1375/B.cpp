#include <bits/stdc++.h>
using namespace std;

#define int long long

int maxi(int i, int j, int n, int m){
    int ans = 4;
    if(i == 0 || i == n-1)ans--;
    if(j == 0 || j == m-1)ans--;
    return ans;
}
signed main() {
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		bool we = 1;
		int ans[n][m];
		for(int i = 0; i < n; i++){
		    for(int j = 0; j < m; j++){
		        cin >> ans[i][j];
		        if(ans[i][j] > maxi(i, j, n, m)){
		            we = 0;
		        }
		        ans[i][j] = maxi(i,j,n,m);
		    }
		}
		if(we){
		    cout << "YES\n";
		for(int i = 0; i < n; i++){
		    for(int j = 0; j < m; j++){
		        cout <<  ans[i][j] << ' ';
		    }cout << '\n';
		}
		}
		else{
		    cout << "NO\n";
		}
		
	}
	return 0;
}