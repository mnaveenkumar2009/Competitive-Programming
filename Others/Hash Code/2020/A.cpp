#include <bits/stdc++.h>
using namespace std;
#define upperlimit 100000

struct library {
	int id;
	int n;
	int t;
	int m;
	long double scor;
	vector<int> bookid;

};

bool comp1(library a, library b) {
	if(a.scor > b.scor) return true;
	return false;
} 

int s[upperlimit];
library libs[upperlimit];
int main() {
	int b, l, d;
	cin >> b >> l >> d;
	for(int i = 0; i < b; ++i) cin >> s[i];

	// Libraries
	for(int i = 0; i < l; ++i) {
		libs[i].id = i;
		libs[i].scor = 0;
		cin >> libs[i].n >> libs[i].t >> libs[i].m;
		for(int j = 0; j < libs[i].n; ++j) {
			int r1;
			cin >> r1;
			libs[i].bookid.push_back(r1);
			libs[i].scor += s[r1];
		}
		libs[i].scor /= (long double)pow(libs[i].t, 1);
	}

	// Processing
	sort(libs, libs + l, comp1);

	// Output
	cout << l << "\n";
	for(int i = 0; i < l; ++i) {
		cout << libs[i].id << " " << libs[i].n << "\n";
		for(int j = 0; j < libs[i].n; ++j) {
			cout << libs[i].bookid[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
