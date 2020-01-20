#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int x, y, s;
        cin >> x >> y >> s;
        vector <int> X(x), Y(y);
        for(int i = 0; i < x; i++){
            cin >> X[i];
        }
        for(int i = 0; i < y; i++){
            cin >> Y[i];
        }
        sort(X.begin(), X.end());
        X.push_back(n+1);
        sort(Y.begin(), Y.end());
        Y.push_back(m+1);
        int ans  = 0, temp = 0;
        for(int i = 0; i <= x; i++){
            int xxx = 0;
            if(i)
                xxx = X[i] - X[i-1] - 1;
            else
                xxx = X[i] - 1;
            temp += (xxx/s);
        }
        for(int j = 0; j <= y; j++){
            int xxx, yyy;
            if(j)
                yyy = Y[j] - Y[j-1] - 1;
            else
                yyy = Y[j] - 1;
            ans += (yyy/s)*temp;
            // cout << ans << ' ';
        }
        cout << ans << '\n';
    }

	return 0;
}