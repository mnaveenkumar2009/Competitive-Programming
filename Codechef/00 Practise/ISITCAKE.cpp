#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a = 0, x;
		for(int i = 0; i < 100; i++){
			cin >> x;
			if(x <= 30)a++;
		}
		if(a >= 60)
			cout << "yes\n";
		else
			cout <<"no\n";
	}
}