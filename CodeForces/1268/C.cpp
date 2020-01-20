#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set X, positions;

signed main(){
    int n;
    cin >> n;
    int a[n], pos[n];
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	pos[a[i]-1] = i;
    	X.insert(a[i]);
    }
    int ans[n];
    memset(ans, 0 , sizeof(ans));
    for(int i = 0; i < n; i++){
    	int temp = X.order_of_key(a[i]);
    	ans[a[i] - 1] += temp;
    	X.erase(a[i]);
    }
    for(int i = 0; i < n; i++){
    	if(i)
    		ans[i] += ans[i-1];
    }
    positions.insert(pos[0]);
    int cur = 0;

    for(int i = 1; i < n; i++){
    	auto p = positions.order_of_key(pos[i]);
    	if(p == 0){
    		
    	}
    	else{
	    	if(p == positions.end()){
	    		if(i&1)
	    			left_half += (*positions.begin()) - pos[i] - 1;
	    		else
	    			right_half += (*positions.begin()) - pos[i] - 1;
	    	}
	    	else{

	    	}
    	}
    	positions.insert(pos[i]);
    	ans[i] += left_half * (i/2) + right_half * (i - i/2);
    }
    for(int i = 0; i < n; i++)
    	cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}