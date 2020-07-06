#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int f(int n, int x){
	// n - x + 1 to n
	int ans = (n - x) * x;
	// sigma x
	ans += (x * (x + 1) )/ 2;
	return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        int n, x;
        cin >> n >> x;
        int ans = 0;
        int a[2*n], s[2*n], b[2*n];
        for(int i = 0; i < n; i++){
        	cin >> a[i];
        	a[n + i] = a[i];
        	b[i] = b[n+i] = (a[i] * (a[i] + 1))/2;
        }
        for(int i = 0; i < 2*n; i++){
        	s[i] = a[i];
        	if(i){
        		s[i] += s[i-1];
        		b[i] += b[i-1];//order 1e17
        	}
        }
        for(int i = 0; i < 2 * n; i++){
        	if(s[i] - x < 0)continue;
        	int pos = upper_bound(s, s + 2*n, s[i] - x) - s;
        	// cout << i << ' ' << pos << '\n';
        	int X = s[pos] - (s[i] - x); //num of days in pos
        	int temp = f(a[pos], X);
        	// cout << X << '\n';
        	// cout << temp << '\n';
        	temp += b[i] - b[pos];
        	ans = max(ans, temp);
        }
        cout << ans << '\n';
    }
}