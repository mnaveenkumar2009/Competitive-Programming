#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 500

vector <pair <bitset <N>, bitset <N> > > mult(vector <pair <bitset <N>, bitset <N> > > A,  vector <pair <bitset <N>, bitset <N> > > B){
     int n = A.size();
     vector <pair <bitset <N>, bitset <N> > > res(n);
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
             bool x = ((A[i].first & B[j].second).count()) & 1;
             res[i].first[j] = x;
             res[j].second[i] = x;
         }
     }
     return res;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        vector <pair <bitset <N>, bitset <N> > > A(n, make_pair(0, 0)), res(n, make_pair(0, 0));
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            l--;r--;
            for(int j = l; j <= r; j++){
                A[i].first[j] = 1;
                A[j].second[i] = 1;
            }
//            cout << A[i].first << '\n';
        }
        bool xxx = 1;
        k--;
        while(k){
            if(k & 1){
            	if(xxx){
            		res = A;
            		xxx = 0;
				}
				else
                res = mult(res, A);
            }
            A = mult(A, A);
            k /= 2;
        }
        vector <int> ans(n, 0);
        for(int i = 0; i < n; i++){
//            cout << res[i].first <<'\n';
            for(int j = 0; j < n; j++){
                if(res[i].first[j])
                    ans[i] ^= a[j];
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << ' ';
        }cout << '\n';
    }
    return 0;
}