#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector <int> l(n), r(n);
        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
        }
        int low = 1, high = 1e9 + 5;
        while(low < high){
            // cout << low << ' '<< high << '\n';
            int mid = (low + high)/2;
            if(mid == low)
                mid++;
            int cur = 0;
            int gr = 0, ls = 0;
            vector <pair <int, int> > A;
            for(int i = 0; i < n; i++){
                if(r[i] < mid){
                    ls++;
                    cur += l[i];
                    continue;
                }
                if(l[i] > mid){
                    cur += l[i];
                    gr++;
                    continue;
                }
                A.push_back({l[i], r[i]});
            }
            // cout << mid <<' '<< ls <<' ' << gr << '\n';
            if(ls>n/2){
                high = mid - 1;
                continue;
            }
            if(gr > n/2){
                low = mid;
                continue;
            }
            // cout << mid << '\n';
            sort(A.begin(), A.end());
            // cout <<"mc "<<ls <<' ' << gr << ' '<< mid << ' ' << cur << '\n';
            for(int i = 0; i < A.size(); i++){
                if(ls == n/2){
                    break;
                }
                ls++;
                cur += A[i].first;
            }
            cur += (((n+1)/2) - gr)*mid;
            // cout <<"mc "<<ls <<' ' << gr << ' '<< mid << ' ' << cur << '\n';
            if(cur <= s){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}