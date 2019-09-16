#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
int main() {

    #define int long long
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int a[k],temmmm;
    unordered_map<int,int> index;
    f(i,k){
        cin>>a[i]>>a[i];
        if(a[i]==1&&index[a[i]]==0){
            temmmm=i;
        }
        index[a[i]] = i;
    }

    cout<<k<<'\n';
    int l = 1, r = 1;
    bool lorr = 1;
    cout<<temmmm<<' '<<0<<' '<<0<<'\n';
    while(r<=433494437){
        // cout<<r<<'\n';
        if(lorr){
            cout<<index[r]<<' '<<0<<' '<<l<<'\n';
        }
        else{
            cout<<index[r]<<' '<<l<<' '<<0<<'\n';
        }
        lorr^=1;
        int temp = l+r;
        l = r;
        r = temp;
        // cout<<temp<<'\n';
    }
    return 0;
}
