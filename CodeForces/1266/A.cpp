#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int q;
	cin >> q;
	while(q--){
		string x;
		cin >> x;
		int sum = 0;
		bool we1 = 0, we2 = 0;
		for(auto i : x){
			sum += i - '0';
			if(i == '0'){
				if(we1)
					we2 = 1;
				we1 = 1;
			}
			if((i - '0')%2 == 0 && i != '0')
				we2 = 1;
		}
		if(sum % 3 != 0){
			cout << "cyan\n";
			continue;
		}
		if(we1 && we2){
			cout << "red\n";
		}
		else{
			cout << "cyan\n";
		}
	}	
}