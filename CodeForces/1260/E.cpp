#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, a[1<<18], ans = 0, buf = 1, j = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == -1)
			memset(a, 0, sizeof(a));
	}
	reverse(a, a + n);
	multiset <int> S;
	for(int i = 0, cur = n; i < log2(n); i++){
		while(j < buf)
			S.insert(a[j++]);
		ans += *S.begin();
		S.erase(S.begin());
		buf += (cur/=2);
	}
	cout << ans << '\n';
}