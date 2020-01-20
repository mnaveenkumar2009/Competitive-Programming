#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005

set <int> adj[N], components;
vector<int> adj2[N];
int n, m, ka, kb;
int R[N], Siz[N];

int root(int X){
    while(X != R[X])
        X = R[X];
    return X;
}

int siz(int X){
    X = root(X);
    return Siz[X];
}
void merge(int X, int Y){
	// cout << X+1 << ' ' << Y+1 << '\n';
	adj2[Y].push_back(X);
	adj2[X].push_back(Y);
	adj[Y].insert(X);
	adj[X].insert(Y);
    X = root(X);
    Y = root(Y);
    if(siz(X) < siz(Y)){
        swap(X, Y);
    }
    // cout << X << ' ' << Y << ' ' << root(Y) << '\n';
    components.erase(root(Y));
    Siz[X] += Siz[Y];
    R[Y] = X;
}

signed main(){
	cin >> n >> m >> ka >> kb;
	if(ka > m - 1 || kb > n -1){
		cout << "No\n";
		return 0;

	}
	int C[n + m];
	memset(C, 0, sizeof(C));
	vector <int> a, b;
	for(int i = 0; i < ka; i++){
		int x;
		cin >> x;
		C[x-1]++;
		a.push_back(x-1);
	}
	for(int i = 0; i < kb; i++){
		int x;
		cin >> x;
		C[x-1]++;
		b.push_back(x-1);
	}
	set <int> S;
	set <int> undone;
	for(int i = 0; i < n+m; i++){
		R[i] = i;
		Siz[i] = 1;
		if(!C[i]){
			S.insert(i);
		}
		components.insert(i);
	}
	int aP = 0, bP = 0;
	while((int)S.size()){
		int X = *S.begin();
		// for(auto i:S){
		// 	cout << i+1 << ' ';
		// }cout << '\n';
		S.erase(S.begin());
		if(X >= n){
			if(aP != ka){
				merge(X, a[aP]);
				C[a[aP]]--;
				if(C[a[aP]] == 0)
					S.insert(a[aP]);
				aP++;
			}
			else{
				undone.insert(X);
			}
		}
		else{
			if(bP != kb){
				merge(b[bP], X);
				C[b[bP]]--;
				if(C[b[bP]] == 0){
					S.insert(b[bP]);
				}
				bP++;
			}
			else{
				undone.insert(X);
			}
		}
	}
	while(undone.size()){
		auto X = *undone.begin();
		undone.erase(undone.begin());
		bool we = 1;
		// cout << X << '\n';
		for(auto i:undone){
			if(root(X) != root(i) && ((X>=n && i <n) || (X<n && i>=n))){
				merge(X, i);
				undone.erase(i);
				we = 0;
				break;
			}
		}
		if(we){
			auto it = components.begin();
			int c1 = *it;
			int c2 = X;
			while((Siz[c1] == 1 && ((c1 >= n && c2 >= n) || (c1 < n && c2 < n))) || root(c1) == root(c2)){
				it++;
				c1 = *it;
			}
			if((c1 >= n && c2 >= n) || (c1 < n && c2 < n)){
				c1 = adj2[c1][0];
			}
			// cout << c1 << '\n';
			merge(c1, c2);
		}
	}


	while(undone.size()){
		auto X = *undone.begin();
		undone.erase(undone.begin());
		auto it = components.begin();
		int c1 = *it;
		int c2 = X;
		while(Siz[c1] == 1 && ((c1 >= n && c2 >= n) || (c1 < n && c2 < n))){
			it++;
			c1 = *it;
		}
		if((c1 >= n && c2 >= n) || (c1 < n && c2 < n)){
			c1 = adj2[c1][0];
		}
		merge(c1, c2);		
	}

	// cout <<aP << '\n';
	if(aP != ka || bP!= kb){
		cout << "No\n";
		return 0;
	}
	// if(simulate()){
	// 	cout << "No\n";
	// 	return 0;
	// }

	cout << "Yes\n";
	for(int i = 0; i < n; i++){
		for(auto chi:adj2[i])
			cout << i+1 << ' ' << chi + 1 << '\n';
	}
}