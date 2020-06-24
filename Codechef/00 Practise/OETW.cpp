#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        ll i,j,k;
        ll s=0,s2=0,s3=0;
        f(i,n){
            cin>>a[i];
            s+=a[i];
        }
        ll ans=0;
        f(i,n){
            s2+=a[i];
            if(a[i]==1)break;
        }
        s2=s-s2;
        for(i=n-1;i>=0;i--){
            s3+=a[i];
            if(a[i]==1)break;
        }
        s3=s-s3;
        ans+=(s+1)/2;
        ans+=max((s3+1)/2,(s2+1)/2);
        cout<<ans<<'\n';
    }
    return 0;
}