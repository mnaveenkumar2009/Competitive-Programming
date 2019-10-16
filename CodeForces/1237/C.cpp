#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    set <pair <pair <int, int>, pair <int, int> > > X;

    for(int i = 0; i < n; i++){
        pair <pair <int, int>, pair <int, int> > A;
        cin >> A.first.first >> A.first.second >> A.second.first;
        A.second.second = i;
        X.insert(A);
    }
    #define mp make_pair
    while(X.size()){
        auto A = X.begin();
        int xi = (*A).first.first, yi = (*A).first.second, zi = (*A).second.first;
        A++;
        int x = (*A).first.first, y = (*A).first.second, z = (*A).second.first;
        // cout << x << ' ' << y << ' ' << z << '\n';
        A = X.lower_bound(mp(mp(x, yi), mp(-1e9,-1)));
        if(A == X.end())
            A--;
        if(A == X.begin())
            A++;
        if((*A).first.first != x){
            A--;
        }
        x = (*A).first.first, y = (*A).first.second, z = (*A).second.first;
        A = X.lower_bound(mp(mp(x, y), mp(zi,-1)));
        if(A == X.end())
            A--;
        if(A == X.begin())
            A++;
        if((*A).first.first != x){
            A--;
        }
        if((*A).first.second != y){
            A--;
        }
        cout << (*A).second.second + 1 << ' ' << (*X.begin()).second.second + 1 << '\n';
        X.erase(A);
        X.erase(X.begin());
    }
}