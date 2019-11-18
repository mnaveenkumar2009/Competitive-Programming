#include <bits/stdc++.h>
using namespace std;
#define ld long double
int x[1000], y[1000];
ld dist(int i, int j){
	ld xxx = (x[i] - x[j])*(x[i] - x[j]);
	ld yyy = (y[i] - y[j])*(y[i] - y[j]);
	return sqrt(xxx + yyy);
}
int main(){
	int n;
	cin >> n;
	ld ans = 0;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i!=j)
				ans += dist(i, j);
		}
	}
	cout << fixed << setprecision(9)<< ans / n << '\n';
}