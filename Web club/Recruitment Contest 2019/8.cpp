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
    int k;
    cin>>k;
    pair <int,int> a[k];
    int coun[10000]={0};
    vector <int> pos[32];
    f(i,k){
        cin>>a[i].ff>>a[i].ss;
        assert(a[i].ff==a[i].ss);
        coun[(int)log2(a[i].ff)]++;
        pos[(int)log2(a[i].ff)].push_back(i);
    }
    f(i,30){
        // cout<<coun[i]<<' ';
    }
    cout<<k<<'\n';
    cout<<pos[0][3]<<' '<<0<<' '<<0<<'\n';
    pos[0].pop_back();
    f(i,30){
        if(!pos[i].size())break;
        int l = 1<<i;
        cout<<pos[i][1]<<' '<<l<<' '<<l<<'\n';
        cout<<pos[i][2]<<' '<<0<<' '<<l<<'\n';
        cout<<pos[i][0]<<' '<<l<<' '<<0<<'\n';
    }

    return 0;
}
