#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	if(s.substr(0, n/2) == s.substr(n/2, n/2) && (n%2==0)){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}