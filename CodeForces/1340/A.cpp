#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector <int> b(1, a[0]);
        bool we = 1;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                b.push_back(a[i]);
            }
            else{
            	if(a[i] != a[i-1] + 1){
            		we = 0;
				}
			}
        }
        // cout << b.size() << '\n';
        for(int i = 0; i < b.size() - 1; i++){
            if(b[i] < b[i+1])
                we = 0;
        }
        if(we)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}