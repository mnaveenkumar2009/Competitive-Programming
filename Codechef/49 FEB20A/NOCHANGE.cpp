#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, p, i;
        cin >> n >> p;
        bool we = 0;
        int a[n], ans[n];
        for(i = 0; i < n; i++){
        	cin >> a[i];
        	if(p % a[i]){
        		we = 1;
        		memset(ans, 0, sizeof(ans));
        		ans[i] = p/a[i] + 1;
        	}
        }
        if(!we){
        	for(int i = 0; i < n; i++){
        		for(int j = i + 1; j < n; j++){
        			if(a[i] > a[j]){
        				if(a[i] % a[j]){
        					we = 1;
        					memset(ans, 0, sizeof(ans));
        					ans[i] = p/a[i] - 1;
        					ans[j] = a[i]/a[j] + 1;
        					break;
        				}
        			}
        			if(a[i] < a[j]){
        				if(a[j] % a[i]){
        					we = 1;
        					memset(ans, 0, sizeof(ans));
        					ans[j] = p/a[j] - 1;
        					ans[i] = a[j]/a[i] + 1;
        					break;
        				}
        			}
        		}
        		if(we)
        			break;
        	}
        }
        if(we){
        	cout << "YES ";
        	for(int i = 0; i < n; i++)
        		cout << ans[i] << ' ';
        	cout << '\n';
        }
        else
        	cout << "NO\n";
    }
}