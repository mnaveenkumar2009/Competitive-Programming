#include <iostream>
#include <set>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n;
		set <int> a;
		for(int i = 0; i < n; i++){
			cin >> x;
			a.insert(x);
		}
		while(a.size() > 2)
			a.erase(a.begin());
		if(a.size() == 1)
			cout << "0\n";
		else
			cout << *a.begin() << '\n';
	}
}