#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	srand(time(0));
	int n = 100;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++)
		a[i] = i + 1;
	random_shuffle(a.begin(), a.end());
	int q = 10;
	cout << n << ' ' << q << '\n';
	for(int i = 0; i < n; i++)
		cout <<a[i] << ' ';
	cout << '\n';
	while(q--){
		cout << rand()%n + 1 << ' ' << rand()%n + 1 << '\n';
	}
}