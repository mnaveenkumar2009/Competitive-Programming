#include <bits/stdc++.h>
using namespace std;

#define int long long

int query(int i, int j){
    if(i == j){
        return i;
    }
    int x;
    cout << 1 << ' ' << i + 1 << ' ' << j + 1 << endl;
    cin >> x;
    return x - 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans[4];
        int win[n][15], lose[n][15];
        memset(win, -1, sizeof(win));
        memset(lose, -1, sizeof(lose));
        vector <int> winners, losers;
        for(int i = 0; i+1 < n; i += 2){
            int x = query(i, i + 1);
            losers.push_back(x);
            winners.push_back(x^1);
            // cout <<x<<'\n';
            lose[x][0] = x^1;
            win[x^1][0] = x;
        }
        int cur = 0;
        if(n&1){
            winners.push_back(n-1);
            losers.push_back(n-1);
        }
        while(winners.size() != 1){
            ++cur;
            vector<int> neww;
            for(int i = 0; i + 1 < (int)winners.size(); i+=2){
                int x = query(winners[i], winners[i + 1]);
                if(x == winners[i + 1]){
                    neww.push_back(winners[i]);
                    win[winners[i]][cur] = winners[i+1];
                }
                else{                 
                    neww.push_back(winners[i + 1]);
                    win[winners[i + 1]][cur] = winners[i];   
                }
            }
            if(((int)winners.size() & 1)){
                neww.push_back(winners[winners.size() - 1]);
                win[winners[winners.size() - 1]][cur] = win[winners[winners.size() - 1]][cur - 1];
            }
            winners = neww;
        }
        ans[3] = winners[0];
        // cout << win[3][0] << ' ' << win[3][1] << '\n';
        int cur_win = win[ans[3]][cur];
        while(cur >= 0){
            cur_win = win[ans[3]][cur] + cur_win - query(win[ans[3]][cur], cur_win);
            cur--;
        }
        ans[2] = cur_win;
        cur = 0;
        while(losers.size() != 1){
            ++cur;
            vector<int> neww;
            for(int i = 0; i + 1 < (int)losers.size(); i+=2){
                int x = query(losers[i], losers[i + 1]);
                if(x != losers[i + 1]){
                    neww.push_back(losers[i]);
                    lose[losers[i]][cur] = losers[i+1];
                }
                else{                 
                    neww.push_back(losers[i + 1]);
                    lose[losers[i + 1]][cur] = losers[i];   
                }
            }
            if(((int)losers.size() & 1)){
                neww.push_back(losers[losers.size() - 1]);
                lose[losers[losers.size() - 1]][cur] = lose[losers[losers.size() - 1]][cur - 1];
            }
            losers = neww;
        }
        ans[0] = losers[0];
        int cur_lose = lose[ans[0]][cur];
        while(cur >= 0){
            cur_lose = query(lose[ans[0]][cur], cur_lose);
            cur--;
        }
        ans[1] = cur_lose;
        for(int i =0 ; i < 4; i++)ans[i]++;
        cout << "2 " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
    }
}