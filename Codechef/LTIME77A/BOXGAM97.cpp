#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];   
        }
        if(k&1){
            if(p){
                cout << *min_element(a.begin(), a.end()) << '\n';
            }
            else{
                cout << *max_element(a.begin(), a.end()) << '\n';
            }
        }
        else{
            int ans = 0;
            if(p)
                ans = 1e9;
            if(p)
                for(int i = 0; i < n; i++){
                    int temp = 0;
                    if(i-1>=0)
                        temp = max(temp, a[i-1]);
                    if(i+1<n)
                        temp = max(temp, a[i+1]);
                    ans = min(ans, temp);
                }
            else{
                for(int i = 0; i < n; i++){
                        int temp = 1e9;
                        if(i-1>=0)
                            temp = min(temp, a[i-1]);
                        if(i+1<n)
                            temp = min(temp, a[i+1]);
                        ans = max(ans, temp);
                }
            }
            cout << ans << '\n';
        }
    }
}