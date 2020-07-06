#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
    cin >> n;
    while(cin >> n){
    	while(n % 2 == 0)
    		n /= 2;
        cout << n/2 << '\n';
    }
}