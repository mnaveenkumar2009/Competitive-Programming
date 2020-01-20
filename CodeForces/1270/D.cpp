#include <bits/stdc++.h>
using namespace std;
#define int long long

pair <int, int> quer(std::vector<int> a){
	cout << "? ";
	for(auto i:a)cout << i + 1 << ' ';
	cout << endl;
	int x, y;
	cin >> x >> y;
	return make_pair(x - 1, y);
}
void answe(int k){
	cout << "! " << k << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    std::vector<int> a(k);
    for(int i = 0; i < k; i++){
    	a[i] = i;
    }
    pair <int, int> A = quer(a);
    int one_side = 0;
    int diff = -1;
    for(int i = 0; i < k; i++){
    	if(i != A.first){
    		a[i] = k;
    		pair <int, int> B = quer(a);
    		one_side += (B == A);
    		if(B != A){
    			diff = B.second;
    		}
    		a[i] = i;
    	}
    }

    if(diff == -1){
    	// 1 or k
    	a[A.first] = k;
    	sort(a.begin(), a.end());
    	diff = quer(a).second;
    	if(diff > A.second){
    		answe(1);
    	}
    	else{
    		answe(k);
    	}
    }
    else{
    	if(diff > A.second){
    		answe(k - one_side);
    	}
    	else{
    		answe(one_side + 1);
    	}
    }
}