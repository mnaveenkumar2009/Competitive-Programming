#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
long long summ(vector <long long> a){
    long long ret=0;
    for(auto it:a){
        ret+=it;
    }
    return ret;
}
int main() {

    #define int long long
    int n,m;
    cin>>n>>m;
    int xxx;
    int k;
    cin>>k;
    pair <int,int> a[k];
    set<pair <int,int> > b;
    int c[4]={0};
    vector <int> d[4];
    f(i,k){
        cin>>a[i].ff>>a[i].ss;
        b.insert({a[i].ff,a[i].ss});
        // cout<<(a[i].ff/2001)*2 + (a[i].ss/2001)<<'\n';
        c[(a[i].ff/2001)*2 + (a[i].ss/2001)]++;
        d[(a[i].ff/2001)*2 + (a[i].ss/2001)].push_back(i);
    }

    // f(i,4)
    //     cout<<c[i]<<' ';cout<<'\n';
    // for(auto it:b){
    //     cout<<it.ff<<' '<<it.ss<<'\n';
    // }
    cout<<k<<'\n';

    f(i,225){
        // cout<<i<<'\n';
        int l= (i/15)*5000;
        int r= (i%15)*5000;
        cout<<d[0][i]<<' '<<l<<' '<<r<<'\n';
        cout<<d[1][i]<<' '<<l<<' '<<r+2000<<'\n';
        cout<<d[2][i]<<' '<<l+2000<<' '<<r<<'\n';
        cout<<d[3][i]<<' '<<l+2000<<' '<<r+2000<<'\n';
    }
    return 0;
}
