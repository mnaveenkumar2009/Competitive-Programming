#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int S = 0;
        bool we = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            S += a[i];
            if(S == 0){
                we = 0;
            }
        }
        S = 0;
        for(int i = n - 1; i >= 0; i--){
            S += a[i];
            if(S == 0){
                we = 0;
            }
        }
        int max_so_far = -1e9, max_ending_here = 0;  
        for (int i = 0; i < n; i++) {
            max_ending_here = max_ending_here + a[i]; 
            if (max_so_far < max_ending_here){
                max_so_far = max_ending_here;
                if(max_so_far >= S && i != n - 1)
                    we = 0;
            }
      
            if (max_ending_here < 0) 
                max_ending_here = 0; 
        }
        if(!we){
            cout << "NO\n";
            continue;
        }
        if(max_so_far <= S){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}