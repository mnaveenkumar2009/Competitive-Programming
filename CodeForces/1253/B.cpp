#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector <int> ans;
	bool we = 1;
	set <int> entry, ext;
	set <int> cant_come;
	int cur = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cur++;
		if(x < 0){
			if(entry.find(-x) == entry.end())
				we = 0;
			else
				entry.erase(-x);
		}
		else{
			if(cant_come.find(x) != cant_come.end())
				we = 0;
			entry.insert(x);
			cant_come.insert(x);
		}
		if(entry.size() == 0 && cur > 0){
			ans.push_back(cur);
			cur = 0;
			cant_come.clear();
		}
	}
	if(entry.size()!=0)
		we = 0;
	if(we){
		cout << ans.size() << '\n';
		for(auto i:ans){
			cout << i << ' '; 
		}cout <<'\n';
	}
	else
		cout << "-1\n";
}