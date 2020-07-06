#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
    int a[n], pre[n], suf[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = a[i];
        if(i)
            pre[i] |= pre[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        suf[i] = a[i];
        if(i != n-1)
            suf[i] |= suf[i+1];
    }
    int maxi = 0, val = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        if(i)
            temp |= pre[i-1];
        if(i != n - 1)
            temp |= suf[i+1];
        if(((a[i]|temp) - temp) > val){
            val = ((a[i]|temp) - temp);
            maxi = i;
        }
    }
    swap(a[maxi], a[0]);
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}