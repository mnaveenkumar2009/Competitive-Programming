#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	vector <int> c(40, 0);
    	int a[n];
    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    		for(int j = 0; j < 40; j++){
    			if(a[i] & (1LL << j)){
    				c[j]++;
    			}
    		}
    	}
    	vector <pair <int, int> > A;
    	for(int i = 0; i < 40; i++){
    		A.push_back({c[i] * (1LL << i), -i});
    	}
    	sort(A.begin(), A.end());
    	reverse(A.begin(), A.end());
    	int x = 0;
    	for(int i = 0; i < k; i++){
    		x |= (1LL << (-A[i].second));
    	}
    	cout << x << '\n';
    }

}