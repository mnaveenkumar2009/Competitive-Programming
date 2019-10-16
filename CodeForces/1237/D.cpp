#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[2*n], ans[2*n], pos[2*n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[n+i] = a[i];
        ans[i] = ans[n+i] = 1e9+5;
    }
    vector <int> X;
    for(int i = 0; i < 2 * n; i++){
        pos[i] = -1;
        if(X.size()){
            int low = 0, high = X.size() - 1;
            while(low != high){
                int mid = (low + high)/2;
                if(mid == low)
                    mid++;
                int B = a[X[mid]];
                if(B > 2*a[i]){
                    low = mid;
                }
                else{
                    high = mid - 1;
                }
            }
            if(a[X[0]] > 2*a[i]){
                pos[i] = X[low];
            }
        }
        // for(auto i:X){
        //     cout << i << ' ';
        // }cout <<'\n';
        // cout << pos[i] << '\n';
        while(X.size()){
            if(a[X[X.size() - 1]] <= a[i])
                X.pop_back();
            else
                break;
        }
        X.push_back(i);
    }
    for(int i = 0; i < 2*n; i++){
        if(pos[i] != -1)
            ans[pos[i]] = min(ans[pos[i]], i - pos[i]);
    }
    for(int i = 0; i < n; i++){
        ans[i] = ans[n+i] = min(ans[i], ans[n+i]);
        ans[i] = min(ans[(i+1)%n] + 1, ans[i]);
    }
    for(int i = 0; i < 2*n; i++){
        ans[i] = min(ans[(i+1)%n] + 1, ans[i]);
    }
    for(int i = 2*n-1; i >= 0; i--){
        ans[i] = min(ans[(i+1)%n] + 1, ans[i]);
    }
    for(int i = 0; i < n; i++){
        if(ans[i]!= 1e9+5)
        cout << ans[i] << ' ';
        else
        cout << -1 << ' ';
    }
    cout << '\n';
}