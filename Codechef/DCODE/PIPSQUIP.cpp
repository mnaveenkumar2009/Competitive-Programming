#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n, h, y1, y2, l;
        cin >> n >> h >> y1 >> y2 >> l;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int tt, x;
            cin >> tt >> x;
            if(l){
                if((h-y1 <=x && tt == 1) || (y2>=x &&tt==2)){
                    ans++;
                }
                else{
                    l--;
                    if(l)
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
	return 0;
}