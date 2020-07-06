#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, c = 0, ans = 0, a[2] = {0, 0};
	string s1, s2;
	cin >> n >> s1 >> s2;
	for(int i = 0; i < n; i++){
		if(s1[i] != s2[i]){
			int x = s1[i] - '0';
			c += x * 2  - 1;
			if(a[!x])
				a[!x]--;
			a[x]++;
		}
	}
	if(c != 0)
		ans = -1;
	else
		ans = a[0] + a[1];
	cout << ans << '\n';
}