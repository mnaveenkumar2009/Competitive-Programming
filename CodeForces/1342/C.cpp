#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int x, y, a, b, q;
        cin >> a >> b >> q;
        if(a > b){
            swap(a, b);
        }
        int lcm = a * b / (__gcd(a, b));
        int A[2*lcm], B[lcm];
        x = b;
    	for(int i = x; i <= x + 2*lcm - 1; i++){
    		A[i - x] = ((i%a) != (i%b)%a);
    		if(i - x){
    			A[i-x] += A[i-x-1];
			}
		}
		B[0] = A[lcm - 1];
    	for(int i = 1; i< lcm; i++){
    		B[i] = A[i + lcm - 1] - A[i-1];
		}
        while(q--){
        	cin >> x >> y;
        	x = max(x, b);
        	if(y < x){
        		cout << "0 ";
        		continue;
			}
        	int ans = A[(y- b)% lcm]  + A[lcm - 1] * ((y - b)/lcm);
        	if(x != b)
        		ans -= A[(x - 1 - b)% lcm]  + A[lcm - 1] * ((x - 1 - b)/lcm);
			cout << ans << ' ';
		}
		cout << '\n';
    }
}