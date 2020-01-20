#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005

signed main(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = n + 1- a[i];
	}
	for(int i = 0; i < n; i++)
		cout << b[i] << ' ';
}