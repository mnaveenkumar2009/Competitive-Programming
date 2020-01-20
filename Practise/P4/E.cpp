#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int N, M;
	cin >> N >> M;
	int a[N][M], sum[N][M], b[N][M], sum2[N][M];
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		// cout << s << ' ' << M << '\n';
		for(int j = 0; j < M; j++){
			a[i][j] = (s[j] == '.');
			// cout << i << ' ' << j << ' ' << a[i][j] << '\n';
		}
	}
   	for (int i=0; i<M; i++) 
      	sum[0][i] = a[0][i];
   	for (int i=1; i<N; i++)
      	for (int j=0; j<M; j++) 
         	sum[i][j] = a[i][j] + sum[i-1][j];
   	for (int i=0; i<N; i++)
      	for (int j=1; j<M; j++)
         	sum[i][j] += sum[i][j-1];
    // for(int i = 0; i < N; i++){
    // 	for(int j = 0; j<M; j++)
    // 		cout << sum[i][j] << ' ';
    // 	cout << '\n';
    // }


	int low = 0, high = 1e8;
	while(low < high){
		int mid = (low + high)/2;
		if(mid == low)mid++;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				b[i][j] = sum2[i][j] = 0;
			}
		}
		bool poss = 1;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(j + mid >= M)continue;
				if(i + mid >= N)continue;
				if(j - mid < 0)continue;
				if(i - mid < 0)continue;
				int tli = i - mid, tlj = j - mid;
				int rbi = i + mid, rbj = j + mid;
			    int res = sum[rbi][rbj];
			    if (tli > 0)
			       res = res - sum[tli-1][rbj];
			    if (tlj > 0)
			       res = res - sum[rbi][tlj-1];
			    if (tli > 0 && tlj > 0) 
			       res = res + sum[tli-1][tlj-1];
				if(res == 0){
					b[i][j] = 1;
				}
			}
		}
	   	for (int i=0; i<M; i++) 
	    	sum2[0][i] = b[0][i];
	   	for (int i=1; i<N; i++) 
	      	for (int j=0; j<M; j++) 
	        	sum2[i][j] = b[i][j] + sum2[i-1][j];
	   	for (int i=0; i<N; i++)
	      	for (int j=1; j<M; j++)
	        	sum2[i][j] += sum2[i][j-1];
	    for(int i = 0; i < N; i++){
	    	for(int j = 0; j < M; j++){
	    		if(a[i][j] == 0){
					int tli = max(0LL, i - mid), tlj = max(0LL, j - mid);
					int rbi = min(N - 1, i + mid), rbj = min(M - 1, j + mid);
				    int res = sum2[rbi][rbj];
				    if (tli > 0)
				       res = res - sum2[tli-1][rbj];
				    if (tlj > 0)
				       res = res - sum2[rbi][tlj-1];
				    if (tli > 0 && tlj > 0) 
				       res = res + sum2[tli-1][tlj-1];
					if(res == 0){
						poss = 0;
					}
	    		}
	    	}
	    }
		if(poss)
			low = mid;
		else
			high = mid - 1;
	}
	cout << low << '\n';
	int mid = low;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			b[i][j] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(j + mid >= M)continue;
			if(i + mid >= N)continue;
			if(j - mid < 0)continue;
			if(i - mid < 0)continue;
			int tli = i - mid, tlj = j - mid;
			int rbi = i + mid, rbj = j + mid;
		    int res = sum[rbi][rbj];
		    if (tli > 0)
		       res = res - sum[tli-1][rbj];
		    if (tlj > 0)
		       res = res - sum[rbi][tlj-1];
		    if (tli > 0 && tlj > 0) 
		       res = res + sum[tli-1][tlj-1];
			if(res == 0){
				b[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(b[i][j] == 0)
				cout <<'.';
			else
				cout << 'X';
		}
		cout << '\n';
	}

}