#include <bits/stdc++.h>
using namespace std;

#define ld long double

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ld a[n];
    set <pair <int, pair <ld, int> > > X;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
        X.insert({i, {a[i], 1}});
    }
    set <int> IND;
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1])
            IND.insert(i);
    }
    while((int)IND.size()){
        int cur_ind = *(IND.begin());
        IND.erase(IND.begin());
        auto ele2 = X.lower_bound({cur_ind, {0, 0}}), ele1 = ele2;
        ele2++;
        if(ele2 == X.end() || ele1 == X.end())
            continue;

        auto E1 = *ele1, E2 = *ele2;
        if(E1.second.first < E2.second.first)
            continue;
        X.erase(E1);
        X.erase(E2);

        ld numm = (E1.second.first * E1.second.second + E2.second.first * E2.second.second)/ (E1.second.second + E2.second.second);
        X.insert({E1.first, {numm, E1.second.second + E2.second.second}});
        auto ele3 = X.lower_bound({E1.first, {numm, E1.second.second + E2.second.second}});
        if(ele3 != X.begin()){
            ele3--;
            auto E3 = *ele3;
            if(E3.second.first > numm){
                IND.insert(E3.first);
                continue;
            }
            ele3++;
        }
        ele3++;
        if(ele3 != X.end()){
            auto E3 = *ele3;
            if(E3.second.first < numm){
                IND.insert(E1.first);
            }
        }
    }
    cout << fixed << setprecision(9);
    for(auto i:X){
        assert(i.second.second > 0);
        while(i.second.second--){
            cout << i.second.first << '\n';
        }
    }
}