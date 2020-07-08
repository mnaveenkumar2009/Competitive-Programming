#include <bits/stdc++.h>
using namespace std;

int main(){
	#define int long long
	int n;
	cin >> n;
	int a[n];
	int gc = 0, tsum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		gc = __gcd(gc, a[i]);
		tsum += a[i];
	}
	// cout << gc << '\n';
	if(gc!=1){
		cout << "0\n";
		return 0;
	}
	int fans = 1e15;
	for(int p = 2; p < 1e6 + 1; p++){
		if(tsum % p != 0)
			continue;
		int ans = 0, cur = 0, curi = 0;
		int sump[n], summ[n], sum[n];
		for(int i = 0; i < n; i++){
			sum[i] = a[i] % p;
			sump[i] = (a[i] % p) * i;
			summ[i] = -sump[i];
			if(i){
				sum[i] += sum[i-1];
				sump[i] += sump[i-1];
				summ[i] += summ[i-1];
			}
		}

		for(int i = 0; i < n; i++){
			cur += (a[i] % p);
			if(cur % p == 0){
				int mini = 1e15;
				for(int j = curi; j <= i; j++){
					int cur_cost = sum[j];
					if(curi)
						cur_cost -= sum[curi - 1];
					cur_cost *= j;
					int cur_cost2 = (sum[i]-sum[j]) * j;
					cur_cost -= cur_cost2;
					int lsum = summ[j];
					if(curi)
						lsum -= summ[curi - 1];
					int rsum = sump[i] - sump[j];
					cur_cost += lsum + rsum;
					// if(p == 17){
					// 	cout << "cur " <<  cur_cost << '\n';
					// }
					mini = min(mini, cur_cost);
				}
				curi = i + 1;
				ans += mini;
				cur = 0;
			}
		}
		if(curi == n)
			fans = min(fans, ans);
	}
	if(fans == 1e15)
		cout << "-1\n";
	else
		cout << fans << '\n';
}