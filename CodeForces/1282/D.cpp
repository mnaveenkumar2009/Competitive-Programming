#include <bits/stdc++.h>
using namespace std;
 
int query(string s){
	cout << s << endl;
	int x;
	cin >> x;
	if(x == 0)
		exit(0);
	return x;
}
 
int main(){
	int n = query("a") + 1;
	if(n == 2){
		if(query("b") == 1){
			query("ab");
			query("ba");
		}
		else
			query("aa");
	}
	if(n == 301){
		string X(n-1, 'b');
		query(X);
		return 0;
	}
	string X(n, 'a');
	int prevx = query(X);
	if(prevx == n){
		string s(n, 'b');
		query(s);
		s.pop_back();
		query(s);
	}
	for(int i = 0; i < n; i++){
		X[i] = 'b';
		int x = query(X);
		if(x > prevx)
			X[i] = 'a';
		else
			prevx = x;
	}
}