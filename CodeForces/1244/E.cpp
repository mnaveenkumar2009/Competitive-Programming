#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int n, k;
    cin >> n >> k;
    vector <int> a(n), sum(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        sum[i] = a[i];
        if(i)
            sum[i] += sum[i-1];
    }
    int ans = a[n-1] - a[0];
    for(int i = 0; i < n; i++){
        // cur is max
        int cost = sum[n-1];
        if(i)
            cost -= sum[i-1];
        cost -= a[i] * (n-i);
        if(cost >= k)
            continue;
        int low = a[0], high = a[i];
        while(low != high){
            int mini_cost = 0;
            int mid = (low + high) / 2;
            if(high == low + 1)
                mid++;
            int pos = lower_bound(a.begin(), a.end(), mid) - a.begin();
            if(pos == n)pos--;
            if(a[pos] > mid)pos--;
            // upto pos increase all to mid
            mini_cost = mid*(pos+1) - sum[pos];
            if(cost + mini_cost <= k)
                low = mid;
            else
                high = mid - 1;
        }
        ans = min(ans, a[i] - low);
    }


    for(int i = 0; i < n; i++){
        // cur is min
        int cost = a[i] * (i+1) - sum[i];
        if(cost >= k)
            continue;
        int low = a[i], high = a[n-1];
        while(low != high){
            int mid = (low + high) / 2;
            int pos = lower_bound(a.begin(), a.end(), mid) - a.begin();
            // pos to n-1 inclusive make mid
            int maxi_cost = sum[n-1];
            if(pos)
                maxi_cost -= sum[pos-1];
            maxi_cost -= mid * (n-pos);
            if(cost + maxi_cost <= k)
                high = mid;
            else
                low = mid + 1;
        }
        ans = min(ans, low - a[i]);
    }
    cout << ans << '\n';
}