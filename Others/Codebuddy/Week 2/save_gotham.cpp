#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long
#define pb push_back
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i;
	    ll a[n];
	    f(i,n)cin>>a[i];
	    vector <ll> stak;
	    ll ans=0;
	    ll mod = 1000000001;
	    stak.pb(a[0]);
	    for(i=1;i<n;i++){
	        int yy=stak.size();
	        while(stak[yy-1]<a[i]){
	            stak.pop_back();
	            yy--;
	            
	            ans=(ans+a[i])%mod;
	            if(yy==0)break;
	        }
	        stak.pb(a[i]);
	        //cout<<ans<<'\n';
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}