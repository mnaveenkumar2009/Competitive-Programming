#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    pair <int, int> b[n];
    vector <pair <int, int> > ans;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++)
        a[b[i].second] = i;
    for(int i = n - 1; i > 0; i--){
        vector <pair <int, int> > vec;
        for(int j = 0; j < i; j++){
            if(a[j] > a[i])
                vec.push_back({a[j], j});
        }
        sort(vec.begin(), vec.end());
        for(auto j:vec){
            swap(a[j.second], a[i]);
            ans.push_back({j.second, i});
        }
    }
    cout << ans.size() << '\n';
    for(auto i: ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}