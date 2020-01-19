#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ret;
    for(int i = 1; i * i <= n; i++){
    	if(n%i == 0){
    		int temp = n/i;
    		temp += (n * (n/i - 1))/2;
    		ret.push_back(temp);
    		if(i*i != n){
	    		int temp = i;
	    		temp += (n * (i - 1))/2;
	    		ret.push_back(temp);
    		}
    	}
    }
    sort(ret.begin(), ret.end());
    for(auto I:ret)cout << I << ' ';cout << '\n';
}