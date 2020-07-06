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
bool done[100006];
int s[upperlimit];
library libs[upperlimit];

bool comp2(int a, int b) {
	if(s[a] > s[b]) return true;
	return false;
} 
int main() {
	memset(done, 0, sizeof(done));
	int b, l, d;
	cin >> b >> l >> d;
	int D = d;
	for(int i = 0; i < b; ++i) cin >> s[i];

	// Libraries
	for(int i = 0; i < l; ++i){
		libs[i].id = i;
		cin >> libs[i].n >> libs[i].t >> libs[i].m;
		for(int j = 0; j < libs[i].n; ++j) {
			int r1;
			cin >> r1;
			libs[i].bookid.push_back(r1);
		}
		sort(libs[i].bookid.begin(), libs[i].bookid.end(), comp2);
	}
	for(int j2 = 0; j2 < l; j2++){
		for(int i = j2; i < l; ++i) {
			libs[i].scor = 0;
			for(int j = 0; j < libs[i].n; ++j) {
				int r1 = libs[i].bookid[j];
				if(done[r1]){
					libs[i].bookid.erase(libs[i].bookid.begin() + j);
					j--;
					libs[i].n--;
					continue;
				}
				if(j < (d - libs[i].t) * libs[i].m)
					libs[i].scor += s[r1];
			}
			libs[i].scor /= (long double)(pow(libs[i].t, 0.9));
		}
		sort(libs + j2, libs + l, comp1);
		d -= libs[j2].t;
		for(auto buk:libs[j2].bookid){
			done[buk] = 1;
		}
	}
	memset(done, 0, sizeof(done));
	// cout << libs[16].scor << ' ' << libs[16].t << '\n';
	l = 200;
	// Output
	cout << l << "\n";
	vector<library> extra;
	for(int i = 0; i < l; ++i) {
		// cout << libs[i].id << " " << libs[i].n << "\n";
		// // Check how many are left
		int howmany = 0;
		vector<int> pr;
		for(int j = 0; j < libs[i].n; ++j) {
			// cout << libs[i].bookid[j] << " ";
			if(done[libs[i].bookid[j]] == 0) {
				++howmany;
				pr.push_back(libs[i].bookid[j]);
				done[libs[i].bookid[j]] = 1;
			}
		}
		if(howmany == 0) {
			extra.push_back(libs[i]);
			continue;
		}
		cout << libs[i].id << " " << howmany << "\n";
		for(auto itr: pr) cout << itr << " ";
		cout << "\n";
	}
	for(auto itr: extra) {
		cout << itr.id << " " << 1 << "\n";
		cout << itr.bookid[0] << "\n";
	}	

	return 0;
}
