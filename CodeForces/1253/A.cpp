#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(cin >> n){
		int a[n], b[n];
		bool we = 1;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++){
			cin >> b[i];
			if(a[i] != b[i]){
				a[i] = b[i] - a[i];
				if(a[i] < 0)we =0;
			}
			else
				a[i] = 0;
		}
		int c = 0;
		set <int> X;
		for(int i = 1; i < n; i++){
			if(a[i]!=a[i-1])
				c++;
			// cout << a[i] << ' ';
			X.insert(a[i]);
		}
		X.insert(a[0]);
		if(a[n-1]!=0)
			c++;
		if(a[0]!=0)
			c++;
		if( c <= 2 && X.size() <= 2 && we){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}