#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int TC = 1; TC <= t; TC++){
        int n, g, m;
        cin >> n >> g >> m;
        int ans[n], ansC[n], ansAC[n], timeAC[n], timeC[n];
        memset(ans, 0, sizeof(ans));
        memset(ansAC, 0, sizeof(ansAC));
        memset(ansC, 0, sizeof(ansC));
        memset(timeAC, 0, sizeof(timeAC));
        memset(timeC, 0, sizeof(ansC));
        for(int i = 0; i < g; i++){
            int x;
            char c;
            cin >> x >> c;
            x--;
            if(c == 'C'){
                x = (x + m) % n;
                ansC[x]++;
                timeC[x] = m;
            }
            else{
                x = (x - m) % n;
                x += n;
                x %= n;
                ansAC[x]++;
                timeAC[x] = m;
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(ansC[i] == 0 && timeC[(i+1)%n]){
                ansC[i] = ansC[(i+1)%n];
                timeC[i] = timeC[(i+1)%n] - 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(ansAC[i] == 0 && timeAC[(i-1+n)%n]){
                ansAC[i] = ansAC[(i-1+n)%n];
                timeAC[i] = timeAC[(i-1+n)%n] - 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(timeC[i] > timeAC[i]){
                ans[i] = ansC[i];
            }
            if(timeAC[i] > timeC[i]){
                ans[i] = ansAC[i];
            }
            if(timeAC[i] == timeC[i])
                ans[i] = ansAC[i] + ansC[i];
        }
        cout << "Case #" << TC <<  ": ";
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}