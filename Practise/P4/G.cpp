#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int n = 10, q = 10;
	string s;
	cout << n << ' ' << q << '\n';
	for(int i = 0; i < n; i++)
		s.push_back('A' + rand()%2);
	cout << s << '\n';
	while(q--){
		int c = rand()%2, l = rand()%n, r = rand()%n;
		if(l > r)
			swap(l, r);
		cout << c + 1 << ' ' << l + 1 << ' ' << r + 1;
		if(c == 1){
			int a = rand()%1000,  b = rand()%1000;
			cout << ' ' << a << ' ' << b;
		}
		cout << '\n';
	}
}