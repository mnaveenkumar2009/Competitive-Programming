#include <bits/stdc++.h>
using namespace std;

int c[3], n, t;

int f(int node, int c0, int c1, int cur){
	int c2 = n - (c0 + c1), ret = 2;
	for(auto child : adj[node]){

	}

}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			c[x]++;
		}
		int ans = -1;
		for(int i = 0; i < 3; i++)
			ans += (bool)c[i];
		if(!c[1] && ans == 1)
			ans = 2;
		for(int i = 0; i < n; i++){
			ans = min(ans, )
		}
	}
}