#include <bits/stdc++.h>
using namespace std;
#define ld long double
bool isv(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int l, n = 0, m = 0;
		cin >> l;
		ld Xa = 1, Xb = 1;
		vector <ld> A(26, 0), B(26, 0), Fa(26, 0), Fb(26, 0);
		while(l--){
			string s;
			set <char> a;
			cin >> s;
			bool we = 0;
			for(int j = 0; j < s.size() - 1; j++){
				if(!isv(s[j]) && !isv(s[j+1])){
					we = 1;
					break;
				}
			}
			for(int j = 0; j < s.size() - 2; j++){
				if(!isv(s[j]) && !isv(s[j+2])){
					we = 1;
					break;
				}
			}
			if(we)
				n++;
			else
				m++;
			for(auto i:s){
				a.insert(i);
				if(we)
					Fa[i-'a']++;
				else
					Fb[i-'a']++;
			}
			for(auto i:a)
				if(we)
					A[i-'a']++;
				else
					B[i-'a']++;
		}
		ld ans = 0;
		for(int i = 0; i < 26; i++){
			ld Xa = 0, Xb = 0;
			if(Fa[i])
				Xa = log(A[i]) - n * log(Fa[i]);
			if(Fb[i])
				Xb = log(B[i]) - m * log(Fb[i]);
			ans += Xb - Xa;
		}
		// cout << ans  << '\n';
		if( ans > 100)
			ans = 1e8;
		else
			ans = exp(ans);
		if(ans < 1e7)
			cout << fixed << setprecision(9) << ans << '\n';
		else
			cout << "Infinity\n";
	}
}