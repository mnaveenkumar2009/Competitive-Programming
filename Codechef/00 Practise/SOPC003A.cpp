#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int a[n];
    	for(int i = 0; i < n; i++)
    		cin >> a[i];
    	sort(a, a + n);
    	long long c = 0;
    	for(int i = 0; i < n; i++)
    		c += (upper_bound(a, a + n, 2 * a[i]) - a) - i - 1;
    	cout << c << '\n';
    }

}