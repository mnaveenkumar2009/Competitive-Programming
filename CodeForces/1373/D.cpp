#include <bits/stdc++.h>
using namespace std;

#define int long long

int mss(vector <int> a) { 
    int siz = a.size();
    int max_so_far = 0, max_ending_here = 0; 
    for (int i = 0; i < siz; i++) { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_ending_here < 0) 
           max_ending_here = 0;
        else 
            if (max_so_far < max_ending_here) 
                max_so_far = max_ending_here; 
    }
    return max_so_far; 
} 

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], ans = 0;
        vector <int> b, c;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i%2==0)
                ans += a[i];
        }
        for(int i = 0; i < n - 1; i += 2){
            b.push_back(a[i + 1] - a[i]);
        }
        for(int i = 1; i < n - 1; i += 2){
            c.push_back(a[i] - a[i+1]);
        }
        cout << ans + max(mss(b), mss(c)) << '\n';
    }
}