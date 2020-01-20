#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

string s;
int n, q, B[500][4], block_size, NOB;
bool toggle[500];

void update(int i){
	B[i][1] = B[i][2] = 0;
	B[i][0] = B[i][3] = 1;
	for(int j = i * block_size; j < min(n, (i+1)*block_size); j++){
		if(s[j] == 'A'){
			B[i][0] = (B[i][0] + B[i][2]) % mod;
			B[i][1] = (B[i][3] + B[i][1]) % mod;
		}
		else{
			B[i][2] = (B[i][0] + B[i][2]) % mod;
			B[i][3] = (B[i][3] + B[i][1]) % mod;
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> q >> s;
	block_size = 250, NOB = (n / block_size) + ((n % block_size) > 0);
	memset(toggle, 0, sizeof(toggle));
	for(int i = 0; i < NOB; i++) // O(n)
		update(i);
	while(q--){
		int c, l, r;
		cin >> c >> l >> r;
		l--;r--;
		int lblok_lim = l / block_size + (l % block_size != 0);
		int rblok_lim = r / block_size - (r != n - 1 && ((r + 1) % block_size != 0));
		if(c == 1){
			if(lblok_lim > rblok_lim){
				for(int i = l; i <= r; i++)
					s[i] = 'A' + 'B' - s[i];
				update(l / block_size);
				update(r / block_size);
				continue;
			}
			for(int i = lblok_lim; i <= rblok_lim; i++) // O(N/X)
					toggle[i] ^= 1;
			for(int i = l; i < lblok_lim * block_size; i++) // O(X)
				s[i] = 'A' + 'B' - s[i];
			update(l / block_size);
			for(int i = (rblok_lim + 1) * block_size; i <= r; i++) // O(X)
				s[i] = 'A' + 'B' - s[i];
			update(r / block_size);
		}
		else{
			int a, b;
			cin >> a >> b;
			if(lblok_lim > rblok_lim){
				for(int i = l; i <= r; i++)
					if((s[i] == 'A') ^ toggle[i/block_size])
						a = (a + b) % mod;
					else
						b = (a + b) % mod;		
				cout << a << ' ' << b << '\n';
				continue;
			}
			for(int i = l; i < lblok_lim * block_size; i++)
				if((s[i] == 'A') ^ toggle[i/block_size])
					a = (a + b) % mod;
				else
					b = (a + b) % mod;			
			for(int bl = lblok_lim; bl <= rblok_lim; bl++){
				if(toggle[bl])
					swap(a, b);
				tie(a, b) = make_pair((B[bl][0] * a + B[bl][1] * b) % mod, (B[bl][2] * a + B[bl][3] * b) % mod);
				if(toggle[bl])
					swap(a, b);
			}
			for(int i = (rblok_lim + 1) * block_size; i <= r; i++)
				if((s[i] == 'A') ^ toggle[i/block_size])
					a = (a + b) % mod;
				else
					b = (a + b) % mod;
			cout << a << ' ' << b << '\n';
		}
	}
}