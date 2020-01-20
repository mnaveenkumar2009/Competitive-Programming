#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[2000], b[2000];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i] >> b[i];
    	a[i] += 1e9;
    	b[i] += 1e9;
    }
    for(int p = 1; p < 33; p++){
    	set <int> X;
    	for(int i = 0; i < n; i++)
    		X.insert((a[i]+b[i] + (1LL << 35)) % (1LL << p));
    	if(X.size() == 2){
	    	for(int i = 0; i < n; i++)
	    		if((a[i]+b[i] + (1LL << 35)) % (1LL << p) == *X.begin())
	    			ans++;
	    	cout << ans << '\n';
	    	for(int i = 0; i < n; i++)
	    		if((a[i]+b[i] + (1LL << 35)) % (1LL << p) == *X.begin())
	    			cout << i + 1 << ' ';
	    	return 0;
    	}
    }
    srand(time(0));
    cout << "1\n";
    cout << (rand()%n) + 1 << '\n';
}