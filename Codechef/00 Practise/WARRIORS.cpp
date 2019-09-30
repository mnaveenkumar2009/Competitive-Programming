#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector <ll> p(n),a(n),b(n);
        f(i,n){
            cin>>p[i];
        }
        sort(p.begin(),p.end());
        a[0]=p[0]+1;
        b[0]=a[0];
        f(i,n){
            if(i){
                ll temp = ceil((p[i]+1)/2.0) + p[i-1];
                // cout<<temp<<'\n';
                if(b[i-1]==INT_MAX){
                    b[i] = INT_MAX;
                    a[i] = a[i-1];
                }
                if(temp <= b[i-1]){
                    a[i] = a[i-1];
                    b[i] = 2*(b[i-1] - p[i-1]);
                }
                else{
                    temp = temp - b[i-1];
                    int k = i-1;
                    while(k--){
                        temp = (temp+1)/2;
                        if(temp<=1)break;
                    }
                    a[i] = temp + a[i-1];
                    if((i-1<=34)||(a[i]==a[i-1]))
                        b[i] = 2*(b[i-1] + (a[i] - a[i-1])*(1LL<<((ll)i-1LL)) - p[i-1]);
                    else{
                        b[i] = INT_MAX;
                    }
                }
                if(b[i]>=INT_MAX)
                    b[i] = INT_MAX;
            }
        }
        // f(i,n){
        //     cout<<a[i]<<' ';
        // }cout<<'\n';
        // f(i,n){
        //     cout<<b[i]<<' ';
        // }cout<<'\n';
        while(q--){
            int x;
            cin>>x;
            int pos = upper_bound(a.begin(),a.end(),x) - a.begin();
            if(pos == n)
                pos--;
            if(a[pos]>x)
                pos--;
            cout<<pos+1<<'\n';
        }
    }

}