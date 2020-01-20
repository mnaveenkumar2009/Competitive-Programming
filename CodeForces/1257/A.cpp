#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
    	int ans = 0;
    	int n, x, a, b;
    	cin >> n>> x >> a >> b;
    	a--;
    	b--;
    	if( a>b)swap(a, b);
    	while(a>0){
    		if(!x)break;
    		a--;
    		x--;
    	}
    	while(b<n-1){
    		if(!x)break;
    		b++;
    		x--;
    	}
    	cout << abs(a-b) << '\n';
    }
}