#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
int main(){
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
        b[0]=2*(a[0]-p[0]);
        f(i,n){
            if(i){
                f(j,10000){
                    ll btemp = j;
                    ll k;
                    for(k=0;k<=i;k++){
                        if(btemp > p[k]){
                            btemp = 2*(btemp - p[k]);
                        }
                        else{
                            break;
                        }
                    }
                    if(k==i+1){
                        a[i] = j;
                        b[i] = btemp;
                        break;
                    }
                }
            }
        }
        f(i,n){
            cout<<a[i]<<' ';
        }cout<<'\n';
        f(i,n){
            cout<<b[i]<<' ';
        }cout<<'\n';
    }

}