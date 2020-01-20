#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
bool check(int i, int j){
	if(i <0 || j < 0)return 0;
	if(i>=n || j >=m)return 0;
	return 1;
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int a[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int ans[n][m];
 		for(int i = 0; i < n; i++){
 			for(int j = 0; j < n; j++){
 				int tmp = 0;
 				if(check(i-1,j))
 					tmp = max(a[i-1][j]);
 				if(check(i-1,j+1))
 					tmp = max(a[i-1][j+1]);
 				if(check(i-1,j-1))
 					tmp = max(a[i-1][j-1]);
 				if(a[i][j] > tmp)
 					cout <<"1";
 				else
 					cout << "0";
 				if(a[i][j] < tmp)
 					a[i][j] = tmp;
 			}
 			cout << '\n';
 		}
	}
}