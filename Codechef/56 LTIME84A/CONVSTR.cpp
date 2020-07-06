#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector <int> p[26];
        vector <vector <int> > ans;
        for(int i = 0; i < n; i++){
            p[s2[i] - 'a'].push_back(i);
        }
        for(int j = 25; j >= 0; j--){
            int pos = -1;
            for(int i = 0; i < n; i++){
                if(s1[i] == 'a' + j){
                    pos = i;
                    break;
                }
            }
            bool we = 1;
            for(auto i:p[j]){
                if(s1[i] != s2[i]) we = 0;
            }
            if(we)continue;
            if(pos != -1 && (p[j].size() != 0)){
                vector <int> tans;
                if(!binary_search(p[j].begin(), p[j].end(), pos)){
                    tans.push_back(pos);
                }
                char mini = s1[pos];
                for(auto i:p[j]){
                    mini = min(mini, s1[i]);
                }
                for(auto i:p[j]){
                    s1[i] = mini;
                    tans.push_back(i);
                }
                ans.push_back(tans);
            }
        }
        if(s1 != s2){
            cout << "-1\n";
        }
        else{
            cout << ans.size() << '\n';
            for(auto i:ans){
                cout << i.size() << ' ';
                for(auto j:i)cout << j << ' ';cout << '\n';
            }
        }
    }
}