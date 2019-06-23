#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[10005];

int main(){
    
    ll t;
    cin>>t;

    while(t--){
    	ll n,a1,k,x;
        cin>>n;
    	vector <ll> profit;
        ll sum=0,sz=0;
    	for(a1=0;a1<n;++a1){
    		cin>>a[a1];
    		sum+=a[a1];
    	}
    	cin>>k>>x;
    	for(a1=0;a1<n;++a1){
    		ll excess = (a[a1] ^ x) - a[a1];
            profit.push_back(excess);
            if(excess > 0) ++sz;
    	}
    	sort(profit.begin(), profit.end(), greater<>());
        if(n == k){
            ll mx1=0,mx2=0;
            for(a1=0;a1<n;++a1) mx1+=profit[a1];
            sum+=max(mx1, mx2);
        }
        else if(k&1){
            for(a1=0;a1<sz;++a1) sum+=profit[a1];
        }
        else{
            if(!(sz&1)) for(a1=0;a1<sz;++a1) sum+=profit[a1];
            else{
                for(a1=0;a1<sz-1;++a1) sum+=profit[a1];
                if((profit[a1]+profit[a1+1])>0){
                    sum+=(profit[a1]+profit[a1+1]);
                }
            }
        }

        cout<<sum<<"\n";
    }
	return 0;
}