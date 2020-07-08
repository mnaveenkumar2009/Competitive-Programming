#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	{
	    int n, m;
		cin >> n >> m;
		char a[n][m];
		int mini[n + m], maxi[n + m], ans = 0;
		bool we = 1;
		memset(mini, -1, sizeof(mini));
		memset(maxi, -1, sizeof(maxi));
		vector <int> R(m,1), C(n, 1);
		for(int i = 0; i < n; i++){
		    string s;
		    cin >> s;
		    bool we2 = 0;
		    for(int j = 0; j < m; j++){
		        a[i][j] = s[j];
		        if(s[j] == '#'){
		            if(we2)we = 0;
		            if(mini[i] == -1)
		                mini[i] = j;
		            maxi[i] = j;
		        }
		        else{
		            if(maxi[i] != -1){
		                we2 = 1;
		            }
		        }
		    }
		    if(mini[i] != -1){
		        C[i] = 0;
		        for(int j = mini[i]; j <= maxi[i]; j++){
		            R[j] = 0;
		        }
		        if(i == 0){
		            ans++;
		        }
		        else{
		            if(mini[i-1] > maxi[i] || maxi[i-1] < mini[i]){
		                ans++;
		            }
		        }
		    }
		}
		int c = 0,r = 0;
		for(auto i:C)c+= i;
		for(auto i:R)r+= i;
// 		cout << r << ' ' << c << '\n';
		if(r == 0){
		    if(c != 0)
		        we = 0;
		}
		if(c == 0){
		    if(r != 0)
		        we = 0;
		}
		memset(mini, -1, sizeof(mini));
		memset(maxi, -1, sizeof(maxi));
		for(int i = 0; i < m; i++){
		    bool we2 = 0;
		    for(int j = 0; j < n; j++){
		        if(a[j][i] == '#'){
		            if(we2){
		                we = 0;
		            }
		            if(mini[i] == -1)
		                mini[i] = j;
		            maxi[i] = j;
		        }
		        else{
		            if(maxi[i] != -1){
		                we2 = 1;
		            }
		        }
		    }
		}
		if(we){
		    cout << ans << '\n';
		}
		else{
		    cout << "-1\n";
		}
	}
}