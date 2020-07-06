#include <bits/stdc++.h>
using namespace std;

int day_of_week(int year){
  int y, m;
  y = year - 1;
  m = 12;
  return (1 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, l, r;
        cin >> x >> l >> y >> r;
        if(x > 2)
            l++;
        if(y < 2)
            r--;
        int ans = 0;
        for(int i = l; i <= l + 399; i++){
            if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                ans += day_of_week(i) == 6;
            else
                ans += (day_of_week(i) == 6) || (day_of_week(i) == 0);
        }
        ans *= (r + 1 - l) / 400;
        for(int i = l + ((r + 1 - l) / 400) * 400; i <= r; i++){
            if(((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                ans += day_of_week(i) == 6;
            else
                ans += (day_of_week(i) == 6) || (day_of_week(i) == 0);            
        }
        cout << ans << '\n';
    }
}     