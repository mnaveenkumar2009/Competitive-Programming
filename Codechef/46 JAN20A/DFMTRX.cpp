#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 2002

int a[N][N];

void prin(int n){
	cout << "Hooray\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool S[2*N + 5][N];
void solve(int n){
	if(n == 1){
		cout << "Hooray\n1\n";
		return;
	}
	if(n == 2){
		cout << "Hooray\n3 1\n2 3\n";
		return;
	}
	if(n&1){
		cout << "Boo\n";
		return;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = i == j;
		}
	}

	int cur = 2;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++)
			S[cur][j] = 1;
		a[0][i] = cur;
		S[cur][0] = 0;;
		S[cur][i] = 0;
		cur++;
	}

	for(int i = 1; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i][j] == 0){
				int it = n;
				for(int k = a[i-1][j+1 == n? i:j+1]; it--; k--){
					int num = (k + n) % n;
					if(!num)
						num = n;
					if(S[num][i] && S[num][j]){
						a[i][j] = num;
						S[num][i] = 0;
						S[num][j] = 0;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++)
			a[i][j] = a[j][i] + n - 1;
	}
	prin(n);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		// if(t + 1 <= 500 && t + 1 >= 400)
		// solve(t+1);
		solve(n);
	}
}