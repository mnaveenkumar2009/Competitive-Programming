#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		std::vector<int> a;
		int ans = 0;
		auto pos = (s.find("twone", 0));
		while(1){
			if(pos == string::npos)break;
			s[pos + 2] = 'z';
			a.push_back(pos + 2);
			pos = (s.find("twone", pos + 1));
		}
		pos = (s.find("two", 0));
		while(1){
			if(pos == string::npos)break;
			a.push_back(pos + 1);
			pos = (s.find("two", pos + 1));
		}
		pos = (s.find("one", 0));
		while(1){
			if(pos == string::npos)break;
			a.push_back(pos + 1);
			pos = (s.find("one", pos + 1));
		}
		cout << a.size() << '\n';
		for(auto i:a)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}