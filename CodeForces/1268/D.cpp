#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	int A = 0, B = 0;
	for(int i = 0; i < n; i++){
		A += a[i]/2;
		B += a[i]/2;
		if(i&1){
			if(a[i]&1)
				A++;
		}
		else{
			if(a[i]&1)
				B++;
		}
	}
	cout <<	min(A,B) << '\n';
}