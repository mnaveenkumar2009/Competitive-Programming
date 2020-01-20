#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int n = 50;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = rand()%1024 + 100;
	}
	int k = rand()%1024 + 100;
	int X = 100;
	while(X--){
		int b[n];
		for(int i = 0; i < n; i++)
			b[i] = a[i]^k;
		cout << k << ' ' << max_element(b, b + n) - b << '\n';
		k = *max_element(b, b + n);
	}
}