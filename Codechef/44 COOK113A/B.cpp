#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, k;
vector <int> D(1, 1);
int a[100006], gc[100006], pos[100006], S;
unordered_map <int, int> X;

int W[5000];
int DP[5000];
int F(int num){

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> k;

    for(int i = 2; i * i <= k; i++){
    	if(k % i == 0){
    		D.push_back(i);
    		if(k != i * i)
    			D.push_back(k/i);
    	}
    }
    D.push_back(k);
    sort(D.begin(), D.end());
	
	S = D.size();

	int Wl[n][S], Wr[n][S];

	for(int i = 0; i < S; i++){
		X[D[i]] = i;
		Wl[0][i] = 1e16;
		Wr[n-1][i] = 1e16;
	}

	for(int i = 0; i < n; i++){
		cin >> a[i];
		gc[i] = __gcd(a[i], k);
		pos[i] = X[gc[i]];
	}

    // for(auto i : D)cout << i << ' ';cout << '\n';

	Wr[n-1][pos[n-1]] = a[n-1];
	Wl[0][pos[0]] = a[0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < S; j++){
			Wl[i][j] = Wl[i-1][j];
		}
		Wl[i][pos[i]] = min(Wl[i][pos[i]], a[i]);
	}


	while(q--){
		int l, r;
		cin >> l >> r;
		int W[S], DP[S];
		for(int i = 0; i < S; i++)
			W[i] = 1e16;
		if(l != 1){
			for(int i = 0; i < S; i++)
				W[i] = Wl[l - 2][i];
		}
		if(r != n){
			for(int i = 0; i < S; i++)
				W[i] = min(W[i], Wr[r][i]);
		}
		for(int i = 0; i < S; i++)
			DP[i] = W[i];
		for(int i = 0; i < S; i++){
			for(auto j : divisors[i]){
				
			}
		}
		// cout << F(W, k);
	}
}