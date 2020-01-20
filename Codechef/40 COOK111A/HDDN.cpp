#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main(){
    #define int long long
    int t;
    cin >> t;
    while(t--){
        int n, k, m, dummy = -1;
        bool we = 1;
        cin >> n >> k >> m;
        bool done[k+1];
        memset(done, 0, sizeof(done));
        vector <int> ans(n, -1);
        unordered_map <int, int> coun;

        vector <pair <int, pair <int, int> > > F[k + 1];
        vector <pair <int, pair <int, int> > > a(m);
        int X[m], Y[m], Z[m];
        for(int i = 0; i < m; i++){
            cin >> X[i] >> Y[i] >> Z[i];
            Z[i]--;
            F[X[i]].push_back({Z[i],{X[i], Y[i]}});
            a[i] = {Z[i],{Y[i], X[i]}};
            if(ans[Z[i]] != -1)
                we = 0;
            ans[Z[i]] = X[i];
            done[X[i]] = 1;
        }
        sort(a.begin(), a.end());
        for(int i = 1; i<=k;i++){
            if(!done[i]){
                dummy = i;
            }
            sort(F[i].begin(), F[i].end());
            reverse(F[i].begin(), F[i].end());
        }
        set <pair <int, pair <int, int> > > Xs;
        for(int i = 1; i<=k;i++){
            if(F[i].size()){
                Xs.insert(F[i][F[i].size() - 1]);
                F[i].pop_back();
            }
        }
        for(int i = 0; i < n; i++){
            if(!we)break;
            if(Xs.size()){
                while(((*Xs.begin()).ss).ss == 1){
                    Xs.erase(Xs.begin());
                    if(!Xs.size())
                        break;
                }
            }
            if(ans[i] == -1){
                if(Xs.size()){
                    pair <int, pair <int, int> > Ele= *Xs.begin();
                    Ele.ss.ss--;
                    ans[i] = Ele.ss.ff;
                    Xs.erase(Xs.begin());
                    Xs.insert(Ele);
                }
                else{
                    if(dummy == -1){
                        memset(done, 0, sizeof(done));
                        for(int sear = i; sear < n; sear++){
                            if(ans[sear] != -1){
                                done[ans[sear]] = 1;
                            }
                        }
                        for(int kk = 1; kk <=k; kk++){
                            if(!done[kk]){
                                dummy = kk;
                                break;
                            }
                        }
                    }
                    ans[i] = dummy;
                    if(dummy == -1)
                        we = 0;
                }
            }
            else{
                pair <int, pair <int, int> > S = make_pair(i,make_pair(-1, -1));
                S = *lower_bound(a.begin(),a.end(), S);
                if(coun[ans[i]] + 1 != S.ss.ff){
                    we = 0;
                    break;
                }
                if(F[ans[i]].size()){
                    F[ans[i]][F[ans[i]].size() - 1].ss.ss -= coun[ans[i]] + 1;
                    Xs.insert(F[ans[i]][F[ans[i]].size() - 1]);
                    F[ans[i]].pop_back();
                }
            }
            coun[ans[i]]++;
        }
        // if(we||!we)
        if(we)
        {
            cout <<"Yes\n";
            for(auto i:ans)
                cout << i << ' ';
            cout << '\n';
        }
        else
            cout <<"No\n";
    }
}
