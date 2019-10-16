#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int a[n], b[n], en[n], mini[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        en[a[i]-1] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    mini[n-1] = en[b[n-1] - 1];
    for(int i = n-2; i >= 0; i--){
        mini[i] = min(mini[i+1], en[b[i] - 1]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(mini[i+1] < en[b[i] - 1]){
            ans++;
        }
    }
    cout << ans << '\n';
}